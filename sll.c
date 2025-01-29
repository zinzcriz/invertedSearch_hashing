#include "inverted_search.h"

int insert_at_last(file_list **head, char *data)
{
	/* create new node */
	file_list *new = malloc(sizeof(file_list));
	if (!new)
	{
		return FAILURE;
	}

	/* if new node created, update data + link */
	strcpy(new->file_name,data);
	new->link = NULL;

	/* If list is empty */
	if (*head == NULL)
	{
		/* add new node to first position */
		*head = new;
		return SUCCESS;
	}

	/* else */
	/* temp points to first node */
	file_list *temp = *head;

	/* traverse to next node check next node is present or not */
	while (temp->link != NULL)
	{
		temp = temp->link;
	}

	/* establish the link between last and new node*/
	temp->link = new;

	return SUCCESS;
}

void print_list(file_list *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head -> file_name);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}
int search_duplicates(file_list *head,char *data)
{
    if(head==NULL)
       return FAILURE;
    while(head)
    {
        if(strcmp(head->file_name,data)==0)
        {
            return SUCCESS;
        }
        head=head->link;
    }
    return FAILURE;
}