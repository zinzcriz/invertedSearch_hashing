#include "inverted_search.h"

void save_database(hash_t *arr,int size)
{
    struct main_node *m_link;
    struct sub_node *s_link;
    char file_name[15];
    start:
    printf("Enter the file name to save database:");
    scanf("%s",file_name);
    if(strstr(file_name,".txt")==NULL)
    {
        printf("Enter a valid file name with .txt extension\n");
        goto start;
    }
    FILE *fptr;
    int flag=0;
    if((fptr=fopen(file_name,"w"))==NULL)
    {
        printf("File opening not successfull!...\n");
        return;
    }
    for(int i=0;i<size;i++)
    {
        if(arr[i].link!=NULL)
        {
            flag=1;
            m_link=arr[i].link;
            while(m_link!=NULL)
            {
                s_link=m_link->sub_link;
                fprintf(fptr,"#%d;",i);
                fprintf(fptr,"%s;",m_link->word);
                fprintf(fptr,"%d;",m_link->file_count);
                while(s_link!=NULL)
                {
                    fprintf(fptr,"%s;%d;",s_link->filename,s_link->word_count);
                    s_link=s_link->link;
                }
                m_link=m_link->main_link;
                fprintf(fptr,"#\n");

            }
        }
    }
    fclose(fptr);
    if(flag==0)
    {
        printf("No Database to save!\n\n");
    }
    else
    {
        printf("Database saved successfully\n\n");
    }
}