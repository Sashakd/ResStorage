#include "read.h"

char* get_word_from_file(FILE* f, int* len, int mx_len)
{
    char* buff;
	char rd[mx_len];  // максимальная длина слова
	*len = 0;
	
	if (fscanf(f, "%s", rd) == 1) 
	{
	    *len = strlen(rd);
		
		buff = malloc((*len+1)*sizeof(char));
		
		if (buff)
		{
            for (int i=0; i<=*len; i++)
                *(buff+i) = *(rd+i);
		}
		else
			return NULL;
	}
	else
	    return NULL;
	
	return buff;
}

struct tree_node* get_tree_from_file(FILE* f, int mx_len)
{
    struct tree_node* root = NULL;
    struct tree_node* qur_root = NULL;
    int len;
    char* qur;

    // Получаем первое слово из файла
    qur = get_word_from_file(f, &len, mx_len);
    printf("GET_IT\n");

    if (qur)
    {
        root = add_tree_node(root, qur);
        printf("ADD_IT\n");
        qur_root = root;

        // Получаем остальные слова из файла
        while (qur)
        {
            printf("STEEP_BGN_IT\n");
            qur = get_word_from_file(f, &len, mx_len);
            if (qur)
                qur_root = add_tree_node(qur_root, qur);  // опасный момент
            printf("STEEP_END_IT\n");
        }

        return root;
    }
    else
        return NULL;
}
