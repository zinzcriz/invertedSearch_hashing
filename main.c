/***************************************************************************************************************************************************
*Author		:Emertxe(http://www.emertxe.com)
*Date		:Mon 22 May 2017 14:00:05 IST
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
#include "inverted_search.h"

int main(int argc, char *argv[])
{
	/* Define the main function here */
	file_list *head=NULL;
	if(check_args(argc,argv,&head)==SUCCESS)
	{
	hash_t arr[HASHTABLE_SIZE];
	create_HT(arr,HASHTABLE_SIZE);
	int choice;
	printf("\n");
	while(1)
	{
		printf("1. Create DATABASE\n2. Display DATABASE\n3. Update DATABASE\n4. Search\n5. Save DATABASE\n6. Exit\nEnter you choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			      create_database(head,arr);
				  printf("Database created Successfully\n");
				  printf("\n");
				  break;
			case 2:
			      if(display_database(arr,HASHTABLE_SIZE)==FAILURE)
				  {
					printf("No Database found!\n");
					printf("Please create Database to continue\n");
				  }
				  printf("\n");
				  break;
			case 3:
			      printf("This function is not available as of now\n");
				  break;
			case 4:
			      //printf("This function is not available as of now\n");
				  if(search(arr,HASHTABLE_SIZE)==FAILURE)
				  {
					printf("The entered word is not found!\n\n");
				  }
				  break;
			case 5:
				  save_database(arr,HASHTABLE_SIZE);
				  break;
			case 6:
			       return SUCCESS;
			default:
			       printf("Invalid Input\n");
			      
		}
	}
	}
}

