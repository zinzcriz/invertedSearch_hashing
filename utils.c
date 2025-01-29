#include "inverted_search.h"

int check_args(int argc,char *argv[],file_list **list_head)
{
    long file_size;
    if(argc>1)
    {
        for(int i=1;argv[i]!=NULL;i++)
        {
            if(strstr(argv[i],".txt")!=NULL)
            {
                FILE *file=fopen(argv[i],"r");
                if(file)
                {
                    file_size=0;
                    fseek(file,0,SEEK_END);
                    file_size=ftell(file);
                    fclose(file);
                    //printf("%d\n",file_size);
                    if(file_size>0)
                    {
                        if(search_duplicates(*list_head,argv[i])!=SUCCESS)
                        {
                            if(insert_at_last(list_head,argv[i])==SUCCESS)
                            {
                                //printf("%s is successfully added\n",argv[i]);
                            }
                            else
                            {
                                printf("%s is not added\n",argv[i]);
                            }
                        }
                        else
                        {
                            printf("%s is already added\n",argv[i]);
                        }
                    }
                    else
                    {
                        printf("%s is empty file\n",argv[i]);
                    }
                }
                else
                {
                    printf("%s is not available\n",argv[i]);
                }

            }
            else
            {
                printf("%s is not .txt file\n",argv[i]);
                continue;
            }
        }
    }
    else
    {
    printf("Argument count should be more than one\n");
    return FAILURE;
    }
    if(*list_head==NULL)
        return FAILURE;
    //print_list(*list_head);
    return SUCCESS;
}

int open_files(file_list *listhead)
{
    if(listhead==NULL)
       return FAILURE;
    while(listhead)
    {
        FILE *fp=fopen(listhead->file_name,"r");
        if(fp)
        {
            printf("%s file is opened\n",listhead->file_name);
        }
        listhead=listhead->link;
    }
    return SUCCESS;
}

int find_index(char c)
{
    if(isdigit(c))
    {
        return 26;
    }
    else if(ispunct(c))
    {
        return 27;
    }
    else
    {
        c=c%97;
        return c;
    }
}