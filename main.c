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
	hash_t arr[HASHTABLE_SIZE];
	create_HT(arr,HASHTABLE_SIZE);
	check_args(argc,argv,&head);
	create_database(head,arr);
	display_database(arr,HASHTABLE_SIZE);
}

