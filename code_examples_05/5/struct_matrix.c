#include "struct_matrix.h"

int get_arr_zero_len(const int* arr)  // Что-то с этим
{
	int i = 0;
	
	while (*(arr + i) != 0)
		i++;
	
	return i;
}

int* put_in_arr(int* arr, int tmp) // <===== здесь что-то не чисто
{
	int* buff = NULL;
	
	if (!arr)
	{
		buff = malloc(sizeof(int)*2);
		
		if (buff)
		{
			*(buff)     = tmp;
			*(buff + 1) = 0;
		}
		else
			return NULL;
	}             // <--- До этого места норм
	else
	{
		//int len = sizeof(arr)/sizeof(int);
		int len = get_arr_zero_len(arr)+1;
		
		buff = arr;
		
		buff = realloc(buff, (len+1)*sizeof(int));
		
		if (buff)
		{
			*(buff + len-1) = tmp;	
			*(buff + len)   = 0;
		}
		else
			return NULL;
	}
	
	return buff;
}

int get_max_in_arr(int* arr)
{
	if (arr)
	{
		int max = *arr;
		int i = 0;
		
		while(*(arr + i) != 0)
		{
			if (*(arr + i) > max)
				max = *(arr + i);
			
			i++;
		}
		
		return max;
	}
	else
		return 0;
}

int get_max_in_arr_bg_nd(const int* bg, const int* nd)
{
	if (bg)
	{
		int max = *bg;
		
		while(bg <= nd)
		{
			if (*bg > max)
				max = *bg;
			
			bg++;
		}
		
		return max;
	}
	else
		return 0;
}

void print_struct_matrix(FILE* f, struct matrix* matr) // Работает в штатном режиме
{	
	struct IA *rem = matr->Nk;
	int max_j = get_max_in_arr(matr->JA);
	int bg;
	int mid;
	
	// До первого элемента в строке
	while (matr->Nk)
	{
		if (matr->Nk->NJA == 0) // Пустая строка
		{
			for (int i = 0; i < max_j; i++)
				fprintf(f, "  0");
		}
		else  // Не пустая строка
		{
			// Нулей до
			bg = *(matr->JA + matr->Nk->NJA-1)-1;
			for (int i = 0; i < bg; i++)
				fprintf(f, "  0");
				
			// Середина строки
			if (matr->Nk->next)  // Не последняя строка
			{
				if (matr->Nk->next->NJA != 0)
					mid = *(matr->JA + matr->Nk->next->NJA-2);
				else
					mid = max_j;
			}
			else                 //    Последняя строка
				mid = *(matr->JA + get_arr_zero_len(matr->JA)-1);
			
			int j = 0;
			
			for (int i = bg; i < mid; i++)
			{
				if (i == *(matr->JA + matr->Nk->NJA-1 + j)-1)
				{
					fprintf(f, "%3d", *(matr->A + matr->Nk->NJA-1 + j));
					j++;
				}
				else
					fprintf(f, "  0");
			}
			// Нулей после
			for (int i = mid; i < max_j; i++)
				fprintf(f, "  0");
		}
		
		fprintf(f, "\n");
		matr->Nk = matr->Nk->next;
	}
	
	matr->Nk = rem;
}

void debug_print_struct_matrix(FILE* f, struct matrix* matr) // Работает в штатном режиме
{
	fprintf(f, "\n\n----------------------------------\n A = {");
	int i = 0;
	
	struct IA *rem = matr->Nk;
	
	while (*(matr->A + i) != 0)
	{
		fprintf(f, "%d ", *(matr->A + i));
		i++;
	}
	
	fprintf(f, "}\nJA = {");
	
	i = 0;
	
	while (*(matr->JA + i) != 0)
	{
		fprintf(f, "%d ", *(matr->JA + i));
		i++;
	}
	
	fprintf(f, "}\n\nNk:\n");
	
	while (matr->Nk)
	{
		fprintf(f, "NJA = %d;\n", matr->Nk->NJA);
		matr->Nk = matr->Nk->next;
	}
	
	matr->Nk = rem;
	
	fprintf(f, "\n----------------------------------\n\n");
}

struct IA* del_last_zero(struct IA *head) // Удаляет из Nk последнюю нулевую строку
{
	struct IA* rem = head;
	
	if (head)
	{
		if (head->next)
		{
		
			while(head->next->next)
				head = head->next;
			
			if (head->next->NJA == 0)
			{
				free(head->next);
				head->next = NULL;
				return rem;
			}
			else
				return rem;
		}
		else
		{
			if (head->NJA == 0)
			{
				free(head);
				return NULL;
			}
			else
				return head;
		}
	}
	else
		return NULL;
}

struct IA* del_all_last_zeros(struct IA *head)
{
	struct IA* rem = head;
	
	while (head)
	{	
		while (head->next)
			head = head->next;
			
		if (head->NJA == 0)
		{
			rem  = del_last_zero(rem);
			head = rem;
		}
		else
			break;
	}
	
	return rem;
}
// Переделать
struct matrix* read_struct_matrix(FILE* f, int* row) // Работает в штатном режиме, возможно стоит проверить ещё
{
	int r = 0;  int c = 0;  int tmp = 0;
	
	struct matrix *M = NULL;
	
	if (fscanf(f, "r: %d c: %d", &r, &c) == 2) // Нормально
	{
		struct IA *head  = NULL;
		struct IA *rem   = NULL;
		
		struct IA *buff = NULL;
		
		M = malloc(sizeof(struct matrix)); 
		M->A  = NULL;  M->JA = NULL;           // Нормально
		
		int h = 0;
		
		for (int i = 0; i < r; i++)
		{	
			if (!head)
			{
				head = malloc(sizeof(struct IA));
				
				if (!head)	return NULL;
				
				rem  = head;
			}
			else
			{
				buff = malloc(sizeof(struct IA));
				
				if (!buff)	return NULL;
				
				head->next = buff;
				head = head->next;
			}
			
			int k1 = 0;
			
			
			for (int j = 0; j < c; j++)
			{
				if (fscanf(f, "%d", &tmp) == 1)
				{
					if (tmp != 0)
					{
						h++;
						M->A  = put_in_arr(M->A,  tmp);
						M->JA = put_in_arr(M->JA, j+1);
						
						
						if (k1 == 0)
						{
							head->NJA = h;
							k1 = 1;
						}
						
						if (!head->NJA)  return NULL;
					}
				}
				else
					return NULL;
			}
			
			if (k1 == 0)
				head->NJA = 0;
		}
		
		head->next = NULL;
		head = rem;
		
		M->Nk = head;
		
		*row = r;
		
		// Подчищаем концы удаляем нулевые строки с конца
		M->Nk = del_all_last_zeros(M->Nk);
		
		return M;
	}
	else
		return NULL;
}

// Из позиции начала строки находит позицию конца
int get_row_end(struct matrix* A) // нумерация идёт с нуля
{
	if (A->Nk->next)
	{
		if (A->Nk->next->NJA == 0)
		{
			struct IA *rem = A->Nk;
			while ((rem->next) && (rem->next->NJA == 0))
				rem = rem->next;
			if (rem->next)
                return rem->next->NJA - 2;
			else
				return get_arr_zero_len(A->JA) - 1;
		}
		else
            return A->Nk->next->NJA - 2;
	}
	else
		return get_arr_zero_len(A->JA) - 1;
}

int find_c_in_row(int* A, int* JA, int bg, int nd, int col)
{
	for (int i = bg; i <= nd; i++) // стандартный проход по строке
        if (*(JA+i)-1 == col)  return (*(A+i));

	return 0;
}

struct matrix* multiply_struct_vec_on_matrix(struct matrix* A, struct matrix* B)
{
	int max_col_B = get_max_in_arr(B->JA);
	struct IA *rem = B->Nk;
	struct matrix* C = malloc(sizeof(struct matrix));
	C->Nk = NULL;
    C->A  = NULL;
    C->JA = NULL;
	int C_bg = 0;
    int len_A = get_arr_zero_len(A->A);
	int max_col_A = *(A->JA + len_A-1);
    int em_q = 1;

	for (int j = 0; j < max_col_B; j++)  // По столбцам второго
	{
		int sum = 0;
		int bg = 0;
		int nd = 0;
        int qur = 0;

        B->Nk = rem;
		
        for (int i = 0; i < max_col_A; i++)
		{
            if (i+1 == *(A->JA + qur))
			{
                if (B->Nk)
				{
                    if (B->Nk->NJA != 0)
					{
                        int bg = B->Nk->NJA-1;
                        int nd = get_row_end(B);

                        int fnd_c = find_c_in_row(B->A, B->JA, bg, nd, j);

						if (fnd_c != 0)
						{
							sum += (*(A->A + qur))*fnd_c;
                            int num1 = *(A->A + qur);
                            int num2 = fnd_c;
						}
					}
                }
				else
					break;
				qur++;
			}
			
            if (B->Nk)
                B->Nk = B->Nk->next;
            else
                break;
		}
		
        if (sum != 0)
		{
            em_q = 0;
            C->A  = put_in_arr(C->A, sum);  C->JA = put_in_arr(C->JA, j+1);
			
			if (!C_bg)
			{
				C->Nk = malloc(sizeof(struct IA));
				if (C->Nk)
				{
                    C->Nk->NJA  = get_arr_zero_len(C->JA);  C->Nk->next = NULL;
					C_bg = 1;
				}
				else
				{
					free(C->A);
					free(C->JA);
					
					free(C);
					
					return NULL;
				}
			}
		}
	}

    if (em_q)
        //C->Nk = NULL;
        return NULL;
	
	B->Nk = rem;
	
	return C;
}

int calc_memory_struct_matrix(struct matrix* matr) // Работает в штатном режиме
{
    int sum_mem = 0;
    int mem_struct = sizeof(matr);

    int mem_A  = sizeof(matr->A);
    int mem_JA = sizeof(matr->JA);

    int mem_list = 0;
    int m_lst_inc = sizeof(struct IA);

    int i = 0;

    while (*(matr->A + i) != 0)
    {
        mem_A += sizeof(int);
        i++;
    }

    i = 0;

    while (*(matr->JA + i) != 0)
    {
        mem_JA += sizeof(int);
        i++;
    }

    struct IA *rem = matr->Nk;

    while (matr->Nk)
    {
        mem_list += m_lst_inc;
        matr->Nk = matr->Nk->next;
    }

    matr->Nk = rem;

    //printf("[%d %d %d %d]\n", mem_struct, mem_A, mem_JA, mem_list);

    sum_mem = mem_struct + mem_A + mem_JA + mem_list;

    return sum_mem;
}

void free_struct_matrix(struct matrix* matr)
{
    /*
    int i = 0;

    while (*(matr->A + i) != 0)
    {
        fprintf(f, "%d ", *(matr->A + i));
        i++;
    }

    fprintf(f, "}\nJA = {");

    i = 0;

    while (*(matr->JA + i) != 0)
    {
        fprintf(f, "%d ", *(matr->JA + i));
        i++;
    }
    */

    free(matr->A);
    free(matr->JA);

    struct IA *rem = matr->Nk;

    while (matr->Nk)
    {
        matr->Nk = matr->Nk->next;
        free(rem);
        rem = matr->Nk;
    }

    free(matr);
}

void get_rc_cnt(struct matrix* M, int* row, int* col)
{
    int c = get_max_in_arr(M->JA);
    int r = 0;

    struct IA* rem = M->Nk;

    while (rem)
    {
        r++;
        rem = rem->next;
    }

    *col = c;
    *row = r;
}
