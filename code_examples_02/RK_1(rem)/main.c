// Вариант 1

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
		printf("\n----INITIAL TEXT:\n");
		
		while (fgets(str, mlen, f))  // Считывание строки
		{
			pnt = str;
			
			// Заменяем символы EOF и '\n' на '\0'
			for (int i = 0; i < strlen_my(str); i++)
				if ((*(str+i) == '\n') || (*(str+i) == EOF))
					*(str+i) = '\0';  // Нулевой символ на месте переноса на новую строку
			
			printf("%s\n", str);
			
			if (strlen_my(str) != 0)
			{
				while (pnt && (*pnt != '\n')) // Проверка на пустую строку
				{
					pnt = get_word_from_str_bg(pnt, &word, mask);  // Получение слова из строки
					
					if (word != NULL)
					{
						head = add_elem(head, word);  // Запись слова в структуру и подсчёт
						free(word);                   // количества вхождений
					}
				}
			}
		}
		
		printf("\n");  // Печать в поток
		fprintf(out, "----WORD LIST:\n");
		
		if (head)
			print_list(out, head);
		else
			fprintf(out,"	EMPTY");
		
		free_elem(head); // Освобождение списка слов 
		free(str);  // Освобождение памяти, выделенной под строку
	}

}

int main(int argc, char* argv[])
{

	char dvds[] = " .,;";
	
	FILE* f = NULL;
	FILE* out = NULL;
	
	if ((argc > 1) && (argc < 4)) // Хотя бы указан файл с текстом для чтения 
	{
		f = fopen(argv[1], "r");
		
		if (!f) // Файл для чтения не открыт
		{
			printf("WARNING! Could not open file [%s]\n", argv[1]);
			return -1;
		}
		
		if (argc == 3)  // Вывод результатов в файл
		{
			out = fopen(argv[2], "w");
			
			if (!out)
			{
				fclose(f);
				printf("WARNING! Could not create file [%s]\n", argv[2]);
				return -2;
			}
			
			printf("\n	-->Result in file [%s]\n", argv[2]);
		}
		else      // Вывод результатов на экран
		{
			out = stdout;
		}
		
		// Функция, выполняющая основные операции
		main_work(f, out, MAX_LEN, dvds);
		
		printf("\n----------------DONE\n\n");
		
		fclose(f);  // Закрываем открытые файлы
		if ((argc == 3) && out)
			fclose(out);
	}
	else
		printf("HELP:\n	main.exe [input_file.txt] ([output_file.txt])\n");
	
	
	return 0;
}

	//char str[] = "12345678901234567890"; // We are the crystal gems!
	//char *str1 = NULL;
	//char* str;
	
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