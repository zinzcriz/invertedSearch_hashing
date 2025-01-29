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
                    fseek(file,0,SEEK_END);
                    file_size=ftell(file);
                    fclose(file);
                    if(file_size>0)
                    {
                        if(search_duplicates(*list_head,argv[i])!=SUCCESS)
                        {
                            if(insert_at_last(list_head,argv[i])==SUCCESS)
                            {
                                printf("%s is successfully added\n",argv[i]);
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
    }
    print_list(*list_head);
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