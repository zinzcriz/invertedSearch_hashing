#include "inverted_search.h"
extern int status;
extern int update_status;
int display_database(hash_t *HT)
{
    if (status != 1 && update_status!=1)
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