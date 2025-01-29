#include "inverted_search.h"

void save_database(hash_t *arr,int size)
{
    struct main_node *m_link;
    struct sub_node *s_link;
    FILE *fptr;
    int flag=0;
    if((fptr=fopen("file.txt","w"))==NULL)
    {
        printf("File opening not successfull!...\n");
        return;
    }
    fprintf(fptr,"#index;\tword;\tfilecount;\tfilename;\twordcount;#\n");
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
                fprintf(fptr,"\t");
                fprintf(fptr,"%s;",m_link->word);
                fprintf(fptr,"\t");
                fprintf(fptr,"%d;",m_link->file_count);
                fprintf(fptr,"\t");
                //printf("Files: ");
                while(s_link!=NULL)
                {
                    fprintf(fptr,"%s;  %d;",s_link->filename,s_link->word_count);
                    fprintf(fptr,"\t");
                    //printf("%d",s_link->word_count);
                    //printf("  ");
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