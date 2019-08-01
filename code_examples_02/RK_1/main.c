#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 101

#include "list_el.h"
#include "string_my.h"

void main_work(FILE* f, FILE* out, int mlen, const char* mask)
{
	char* str = malloc(sizeof(char)*mlen);
	char* pnt = str;
	struct list_elem* head = NULL;
	char* word = NULL;

	if (str)
	{
		while (fgets(str, mlen, f))
		{
			*(str+mlen-1) = '\0'; // <---- Проверить
				
			while (pnt && (*pnt != '\n')) // <---- зацикливается здесь \t
			{
				pnt = get_word_from_str_bg(pnt, &word, mask);
				//printf("\n--[%s]--\n", *word);
				if (word != NULL)
					head = add_elem(head, word);
					
				free(word);
			}
		}
			
		// Печать в поток
		printf("\nLIST:\n");
		print_list(out, head);
	}

}

int main(int argc, char* argv[])
{

	char dvds[] = " .,;";
	char str[] = "12345678901234567890"; // We are the crystal gems!
	//char *str1 = NULL;
	//char* str;
	
	FILE* f = NULL;
	
	f = fopen("a.txt", "r");
	
	main_work(f, stdout, MAX_LEN, dvds);
	
	printf("[%s]", str);
	
	fclose(f);
	
	/*
	printf("str    = [%s]\n", str);
	printf("strlen = %d\n", strlen_my(str));
	*/
	
	//str1 = strcpy_my_why(str);
	//str1 = strncpy_my_why(str, 40);
	/*
	printf("str    = [%s]\n", str);
	printf("str    = [%s]\n", str1);
	*/
	/*
	char str2[] = "12345678901234567890";
	char str3[] = "12345678901234567890";
	
	printf("str2   = [%s]\n", str2);
	printf("str3   = [%s]\n", str3);
	
	printf("%d\n", or_strcmp(str2, str3));
	*/
	/*
	char s1[] = "fall";
	char s2[] = "fake";
	char s3[] = "dull";
	char s4[] = "nuke";
	char s5[] = "fall";
	char s6[] = "fall";
	
	struct list_elem* head = NULL;
	
	head = add_elem(head, s1);
	head = add_elem(head, s2);
	head = add_elem(head, s3);
	head = add_elem(head, s4);
	head = add_elem(head, s5);
	head = add_elem(head, s6);
	
	printf("\nLIST:\n");
		print_list(stdout, head);
	*/
	
	return 0;
}