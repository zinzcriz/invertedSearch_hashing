#include "inverted_search.h"

void create_HT(hash_t *HT,int size)
{
    for(int i=0;i<size;i++)
    {
        HT[i].index=i;
        HT[i].link=NULL;
    }
}