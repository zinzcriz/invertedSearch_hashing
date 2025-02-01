#include "inverted_search.h"
extern int status;
extern int update_status;
int update_database(file_list *listhead, hash_t *arr)
{
    if(status==1)
    {
        printf("INFO: You cannot update database after database is created\n\n");
        return FAILURE;
    }
    else if(update_status==1)
    {
        printf("You cannot update database more than once!\n\n");
        return CREATED;
    }
    char file_name[20];
    char header[50];
    int filecount,wordcount,index;
    char word_name[15];
    char temp[5];
    FILE *fp;
    long file_length;
    printf("Enter the file name to update:");
    scanf("%s", file_name);
    if (strstr(file_name, ".txt") != NULL)
    {
        fp = fopen(file_name, "r");
        if (fp)
        {
            if ((file_length=isFile_empty(fp))>0)
            {
                //printf("%ld\n",file_length);
                //fscanf(fp,"#%[^\n]",header);
                while (ftell(fp)<file_length)
                {
                    fscanf(fp,"#%d;%[^;];%d;",&index,word_name,&filecount);
                    /*fscanf(fp,"#%d;",&index);
                    fscanf(fp,"%[^;];",word_name);
                    fscanf(fp,"%d;",&filecount);*/
                    //printf("%d %s %d\n",index,word_name,filecount);
                    update_mainnode(index,word_name,filecount,arr);
                    for(int i=0;i<filecount;i++)
                    {
                        fscanf(fp,"%[^;];%d;",file_name,&wordcount);
                        //printf("%s %d\n",file_name,wordcount);
                        update_subnode(index,word_name,file_name,wordcount,arr);
                        delete_updatedNode(&listhead,file_name);
                    }
                    fscanf(fp,"#\n",temp);
                }
            }
        }
    }
    print_list(listhead);
    printf("\n");
    update_status=1;
    return SUCCESS;
}
