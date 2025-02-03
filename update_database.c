#include "inverted_search.h"
extern int status;
extern int update_status;
int update_database(file_list **listhead, hash_t *arr)
{
    if(status==1)
    {
        printf("ERROR: You cannot update database after database is created\n\n");
        return FAILURE;
    }
    else if(update_status==1)
    {
        printf("ERROR: You cannot update database more than once!\n\n");
        return CREATED;
    }
    char file_name[20];
    char file_nme[20];
    char header[50];
    int filecount,wordcount,index;
    char word_name[15];
    char temp[5];
    FILE *fp;
    long file_length;
    label:
    printf("Enter the file name to update:");
    scanf("%s", file_name);
    if (strstr(file_name, ".txt") != NULL)
    {
        fp = fopen(file_name, "r");
        if (fp)
        {
            if (validate_updatefile(fp)==SUCCESS)
            //if((file_length=find_fileLength(fp))>0)
            {
                file_length=find_fileLength(fp);
                while (ftell(fp)<file_length)
                {
                    fscanf(fp,"#%d;%[^;];%d;",&index,word_name,&filecount);
                    //convertTo_lower(word_name);
                    update_mainnode(index,word_name,filecount,arr);
                    for(int i=0;i<filecount;i++)
                    {
                        fscanf(fp,"%[^;];%d;",file_nme,&wordcount);
                        /*if (strstr(file_nme, ".txt") == NULL)
                        {
                            continue;
                        }*/
                        //printf("%s %d\n",file_name,wordcount);
                        update_subnode(index,word_name,file_nme,wordcount,arr);
                        delete_updatedNode(listhead,file_nme);
                    }
                    fscanf(fp,"#\n",temp);
                }
            }
            else{
                printf("ERROR: This file is not compatible to update\n");
            }
        }
        else{
            printf("ERROR: %s is not available\n\n",file_name);
            return FAILURE;
        }
    }
    else{
        printf("ERROR: Filename should contain a .txt extension\n");
        goto label;
    }
    print_list(*listhead);
    printf("\n");
    update_status=1;
    return SUCCESS;
}