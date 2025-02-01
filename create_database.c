#include "inverted_search.h"

// void create_database(FILE *filelist)
// {
// 	/* Definition here */
// }
extern int status;
int create_database(file_list *listhead, hash_t *arr)
{
	if (listhead == NULL)
		return FAILURE;
	if(status==1)
	{
		return CREATED;
	}
	file_list *temp = listhead;
	status=1;
	char str[20];
	int index;
	struct main_node *m_link;
	struct main_node *m_prev;
	struct sub_node *s_link;
	struct sub_node *s_prev;

	int s_flag = 0, m_flag = 0;
	while (temp)
	{
		FILE *fp = fopen(temp->file_name, "r");
		if (fp)
		{
			//printf("%s file is opened\n", temp->file_name);
			while (fscanf(fp, "%s", str) != EOF)
			{
			    index=find_index(str[0]);
				//printf("%d\n",index);
				if (arr[index].link == NULL)
				{
					//printf("In while\n");
					m_link = malloc(sizeof(struct main_node));
					strcpy(m_link->word, str);
					m_link->file_count = 1;
					m_link->main_link = NULL;
					arr[index].link = m_link;
					s_link = malloc(sizeof(struct sub_node));
					strcpy(s_link->filename, temp->file_name);
					s_link->link = NULL;
					s_link->word_count = 1;
					m_link->sub_link = s_link;
					//printf("%s\n", (arr[index].link)->word);
				}
				else
				{
					//printf("else while\n");
					m_link = arr[index].link;
					do
					{
						if (strcmp(m_link->word, str) == 0)
						{
							m_flag = 1;
							s_link = m_link->sub_link;
							do
							{
								if (strcmp(s_link->filename, temp->file_name) == 0)
								{
									s_link->word_count += 1;
									s_flag = 1;
									//printf("%s\n",m_link->word);
								}
								// if(s_link->link!=NULL)
								s_prev = s_link;
								s_link = s_link->link;
							} while (s_link != NULL);
							if (s_flag == 0)
							{
								s_link = malloc(sizeof(struct sub_node));
								strcpy(s_link->filename, temp->file_name);
								s_link->link = NULL;
								s_link->word_count = 1;
								s_prev->link = s_link;
								m_link->file_count += 1;
								//printf("%s\n",m_link->word);
							}
							s_flag = 0;
						}
						// if(m_link->main_link!=NULL)
						m_prev = m_link;
						m_link = m_link->main_link;
					} while (m_link != NULL);
					if (m_flag == 0)
					{
						m_link = malloc(sizeof(struct main_node));
						strcpy(m_link->word, str);
						m_link->file_count = 1;
						m_link->main_link = NULL;
						s_link = malloc(sizeof(struct sub_node));
						strcpy(s_link->filename, temp->file_name);
						s_link->link = NULL;
						s_link->word_count = 1;
						m_link->sub_link = s_link;
						m_prev->main_link=m_link;
						//printf("%s\n", m_link->word);
					}
					m_flag=0;
				}
			}
		}
		temp = temp->link;
	}
	return SUCCESS;
}
