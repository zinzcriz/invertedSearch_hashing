
#include "inverted_search.h"
int status = 0;
int update_status=0;

int main(int argc, char *argv[])
{
	/* Define the main function here */
	file_list *head = NULL;
	if (check_args(argc, argv, &head) == SUCCESS)
	{
		hash_t arr[HASHTABLE_SIZE];
		create_HT(arr, HASHTABLE_SIZE);
		int choice;
		printf("\n");
		while (1)
		{
			printf("1. Create DATABASE\n2. Display DATABASE\n3. Update DATABASE\n4. Search\n5. Save DATABASE\n6. Exit\nEnter you choice : ");
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				if (create_database(head, arr) == SUCCESS)
				{
					printf("Database created Successfully\n");
				}
				else if (create_database(head, arr) == CREATED)
				{
					printf("You can create database only once!\n");
				}
				else
				{
					printf("Nothing new to create!\n");
				}
				// printf("%d\n",status);
				printf("\n");
				break;
			case 2:
				if (display_database(arr) == FAILURE)
				{
					printf("No Database found!\n");
					printf("Please create Database to continue\n");
				}
				printf("\n");
				break;
			case 3:
				// printf("This function is not available as of now\n");
				if(update_database(&head, arr)==SUCCESS)
				{
					printf("Database updated Successfully!\n");
					printf("\n");
				}
				break;
			case 4:
				// printf("This function is not available as of now\n");
				if (search(arr, HASHTABLE_SIZE) == FAILURE)
				{
					printf("The entered word is not found!\n\n");
				}
				break;
			case 5:
				save_database(arr, HASHTABLE_SIZE);
				break;
			case 6:
				return SUCCESS;
			default:
				printf("Invalid Input\n");
			}
		}
	}
}
