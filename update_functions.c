#include "inverted_search.h"

void update_mainnode(int index, char *word,int f_count,hash_t *arr)
{
    struct main_node *m_link;
    if (arr[index].link == NULL)
    {
        m_link = malloc(sizeof(struct main_node));
        strcpy(m_link->word, word);
        m_link->file_count = f_count;
        m_link->main_link = NULL;
        arr[index].link = m_link;
        m_link->sub_link = NULL;
        //printf("%s\n",(arr[index].link)->word);
    }
    else{
        struct main_node *new;
        m_link=arr[index].link;
        while(m_link->main_link!=NULL)
             m_link=m_link->main_link;
        new=malloc(sizeof(struct main_node));
        new->file_count=f_count;
        new->main_link=NULL;
        strcpy(new->word,word);
        new->sub_link=NULL;
        m_link->main_link=new;
        //printf("%s\n",new->word);
    }
}

void update_subnode(int index,char *word,char *f_name,int wordcount,hash_t *arr)
{
    struct main_node *m_link;
    struct sub_node *s_link;
    m_link=arr[index].link;
    while(m_link!=NULL)
    {
        if(strcmp(m_link->word,word)==0)
        {
            if(m_link->sub_link==NULL)
            {
                s_link = malloc(sizeof(struct sub_node));
                strcpy(s_link->filename,f_name);
                s_link->word_count=wordcount;
                s_link->link=NULL;
                m_link->sub_link=s_link;
                //printf("%s\n",s_link->filename);
            }
            else
            {
                s_link=m_link->sub_link;
                while(s_link->link!=NULL)
                    s_link=s_link->link;
                struct sub_node *new;
                new=malloc(sizeof(struct sub_node));
                strcpy(new->filename,f_name);
                new->word_count=wordcount;
                new->link=NULL;
                //printf("%s\n",new->filename);
            }
        }
        m_link=m_link->main_link;
    }
}

int delete_updatedNode(file_list **listhead,char *f_name)
{
    if(*listhead==NULL)
          return FAILURE;
    file_list *temp=*listhead;
    file_list *prev=NULL;
    while(temp!=NULL)
    {
        if(strcmp(temp->file_name,f_name)==0)
        {
            if(*listhead==temp)
            {
                *listhead=temp->link;
                free(temp);
                //temp=listhead;
                return SUCCESS;
            }
            else
            {
                prev->link=temp->link;
                free(temp);
                return SUCCESS;
            }
        }
        prev=temp;
        temp=temp->link;
    }
    return FAILURE;
}