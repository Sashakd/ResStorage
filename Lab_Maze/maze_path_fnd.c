#include "maze_rdy.h"

struct stack_elem // <--короче проверить
{
    int x;
    int y;
    int dat;
    struct stack_elem* prev; // -- ??
};

struct can_movm
{
    int n;
    int e;
    int s;
    int w;
};

struct can_movm* intit_can_movm_arr(int* arr, int ix, int jy, int c)
{
    // если граничная клетка
    // иначе
    // просматриваем соседние по вертикали и горизонтали
    // присваиваем структуре
	return NULL;
}

struct any_way
{
    int len;
	int* x;
	int* y;
	int* s;
};

int* init_all_list_arr(int* arr, int r, int c)
{
    int *buf;

	buf = malloc(r*c*sizeof(int));
	
	if (buf)
        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++)
                if (get_value_arr(arr, i, j, c) == 1)
                    *(buf+i*c+j) = 0;
                else
                    *(buf+i*c+j) = 1;

    return buf;
}

int* find_path_arr(int* arr, int r, int c, int bg_ix, int bg_jy, int nd_ix, int nd_jy)
{
    // Список всех вершин тк нам не сильно нужно удаление и
    // Добавление элементов, то просто воспользуемся статич. массивом
    int *all_list; // Значение матрицы будем хранить в линейном массиве
	struct stack_elem* head = NULL;  // Стек вершин
    // инициализируем этот "список"
    all_list = init_all_list_arr(arr, r, c); // Стены в поиске не учавствуют и считаются полностью просмотренными

    // тукущий элемент
    int qur_ix = bg_ix;
    int qur_jy = bg_jy;

	// текущему 
	
    // Что делать со списками смежности ?

	
	
    // Пока не дойдём до конца
    while ((qur_ix != nd_ix)&&(qur_jy != nd_jy))
    {
        // если вершина в роли текущей - первая, то инициализируем её список смежности и запихнуть его в стек
        // + рекурсивное обращение
		
		//--------------------------
		
		//--------------------------
		
		qur_ix++;
		qur_jy++;
    }

    // Стек вершин
	
	return all_list;
}
