#include "inverted_search.h"
extern int status;
int search(hash_t *arr, int size)
{
    if(status==0)
    {
        printf("Database is empty.Please create database to search words.\n\n");
        return DATABASE_EMPTY;
    }
    struct main_node *m_link;
    struct sub_node *s_link;
    char str[20];
    printf("Enter the word to search:");
    scanf("%s", str);
    printf("\n");
    int flag = 0;
    int index = find_index(str[0]);
    if (arr[index].link != NULL)
    {
        //printf("\n");
        m_link = arr[index].link;
        while (m_link != NULL)
        {
            if (strcmp(m_link->word, str) == 0)
            {
                flag = 1;
                s_link = m_link->sub_link;
                printf("%s is present in %d files\n",m_link->word,m_link->file_count);
                while (s_link != NULL)
                {
                    printf("In file: %s  %d time/s", s_link->filename, s_link->word_count);
                    printf("\n");
                    // printf("%d",s_link->word_count);
                    // printf("  ");
                    s_link = s_link->link;
                }
            }
            m_link = m_link->main_link;
        }
        printf("\n");
    }

    if (flag == 0)
        return FAILURE;
}