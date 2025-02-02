#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define SUCCESS 1
#define FAILURE 0
#define CREATED -1
#define DATABASE_EMPTY -2

#define HASHTABLE_SIZE 28

typedef struct node
{
	char file_name[10];
	struct node *link;
}file_list;

struct sub_node
{
    int word_count;
    char filename[20];
    struct sub_node *link;
};

struct main_node
{
    int file_count;
    char word[20];
    struct main_node *main_link;
    struct sub_node *sub_link;
};



typedef struct hash_table
{
    int index;
    struct main_node *link;
}hash_t;




//Slist Functions
int insert_at_last(file_list **head, char *data);
void print_list(file_list *head);
int search_duplicates(file_list *head,char *data);

//Hash table functions
void create_HT(hash_t *HT,int size);


int check_args(int argc,char *argv[],file_list **list_head);
int create_database(file_list *listhead,hash_t *arr);
int open_files(file_list *listhead);
//int display_database(hash_t *arr,int size);
int display_database(hash_t *);
int find_index(char c);
long isFile_empty(FILE *fp);
void save_database(hash_t *arr,int size);
int search(hash_t *arr, int size);

//update functions
int update_database(file_list **listhead, hash_t *arr);
void update_mainnode(int index, char *word,int f_count,hash_t *arr);
void update_subnode(int index,char *word,char *f_name,int wordcount,hash_t *arr);
int delete_updatedNode(file_list **listhead,char *f_name);


#endif