#include "inverted_search.h"

int display_database(hash_t *arr,int size)
{
    struct main_node *m_link;
    struct sub_node *s_link;
    int flag=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i].link!=NULL)
        {
            flag=1;
            m_link=arr[i].link;
            while(m_link!=NULL)
            {
                s_link=m_link->sub_link;
                printf("[%d]",i);
                printf("\t");
                printf("[%s]",m_link->word);
                printf("\t");
                printf("Filecount: %d",m_link->file_count);
                printf("\t");
                printf("Files: ");
                while(s_link!=NULL)
                {
                    printf("%s  %d",s_link->filename,s_link->word_count);
                    printf("\t");
                    //printf("%d",s_link->word_count);
                    //printf("  ");
                    s_link=s_link->link;
                }
                m_link=m_link->main_link;
                printf("\n");

            }
        }
    }
    if(flag==0)
        return FAILURE;
}