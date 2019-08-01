struct h_table_node* init_hesh(void)
{
    struct h_table_node* buff;
	
	// abcdefghigklmnopqrstuvwxyz
    buff = malloc((44)*sizeof(char));
    
	if (buff)
	{
	    for (int i = 'A'; i <= 'Z'; i++)
		{
		    (buff - 'A' + i)->key = i;
			(buff - 'A' + i)->str_list = NULL;
			(buff - 'A' + i)->wd_cnt = 0;
		}
		
		for (int i = 'a'; i <= 'z'; i++)
		{
		     (buff - 'A' + 21 + i)->key = i;
			 (buff - 'A' + 21 + i)->str_list = NULL;
			 (buff - 'A' + 21 + i)->wd_cnt = 0;
		}
		
		//buff + 44 = NULL; 
	}
	else
	    return NULL;
	
	return buff;
}

struct h_table_node* put_in_h_table(struct h_table_node* cur, char* word)
{
    for (int i = 0; i < 44; i++)
	{
	    if (*(word) == (cur + i)->key)
		{
		    ((cur + i)->wd_cnt)++;			
		    (cur + i)->str_list = realloc((cur + i)->str_list, wd_cnt*sizeof(char*));
			(((cur + i)->str_list) + ((cur + i)->wd_cnt) - 1) = word;
		}
	}
	
	return bg;
}

void print_h_table(struct h_table_node* cur)
{
    printf("------------------\n");
	printf("| key | words \n"
	printf("------------------\n");
    
    for (int i = 0; i < 44; i++)
	{

	}
}