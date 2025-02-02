#include "inverted_search.h"
extern int status;
// int display_database(hash_t *arr,int size)
// {
//     /*if(status!=1)
//     {
//         return FAILURE;
//     }*/
//     struct main_node *m_link;
//     struct sub_node *s_link;
//     int flag=0;
//     printf("index\t\tword\t\tfilecount\t\tfilename\t\twordcount\n");
//     for(int i=0;i<size;i++)
//     {
//         if(arr[i].link!=NULL)
//         {
//             flag=1;
//             m_link=arr[i].link;
//             while(m_link!=NULL)
//             {
//                 s_link=m_link->sub_link;
//                 printf("[%d]",i);
//                 printf("\t\t");
//                 printf("[%s]",m_link->word);
//                 printf("\t\t");
//                 printf("%d",m_link->file_count);
//                 printf("\t\t");
//                 printf("Files: ");
//                 while(s_link!=NULL)
//                 {
//                     printf("%s  %d",s_link->filename,s_link->word_count);
//                     printf("\t\t");
//                     //printf("%d",s_link->word_count);
//                     //printf("  ");
//                     s_link=s_link->link;
//                 }
//                 m_link=m_link->main_link;
//                 printf("\n");

//             }
//         }
//     }
//     if(flag==0)
//         return FAILURE;
// }
#include "inverted_search.h"

int display_database(hash_t *HT)
{
    if (status != 1)
    {
        return FAILURE;
    }
    printf("\n\t\tHASH TABLE DISPLAY\n");
    printf("-----------------------------------------------------------\n");
    printf("| INDEX |   WORD   | FILECOUNT |   FILENAME   | WORDCOUNT |\n");
    printf("-----------------------------------------------------------\n");

    // Iterate over each index of the hash table
    for (int i = 0; i < 28; i++)
    {
        if (HT[i].link != NULL)
        {
            struct main_node *mainnode = HT[i].link;
            // Traverse the main linked list
            while (mainnode != NULL)
            {
                printf("| %-5d | %-8s | %-9d |", i, mainnode->word, mainnode->file_count);

                // Traverse the subnodes for the current word
                struct sub_node *subnode = mainnode->sub_link;
                int first_entry = 1;

                while (subnode != NULL)
                {
                    if (!first_entry)
                        printf("|       |          |           |"); // Maintain column alignment

                    printf(" %-12s | %-9d |\n", subnode->filename, subnode->word_count);

                    subnode = subnode->link;
                    first_entry = 0;
                }

                // If no subnodes exist, move to the next line
                if (first_entry)
                    printf(" N/A           | N/A       |\n");

                mainnode = mainnode->main_link;
            }
        }
    }
    printf("-----------------------------------------------------------\n");
}