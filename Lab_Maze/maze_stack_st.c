#include "maze_stack_st.h"

// нужно отдельно создать список всех клеток не со стеной и по нему ходить со стеком
// может воспользоваться каким-нибудь специфическим алгоритмом (не из ДМ)?

// + структура-элемент стека
struct stack_elem // <--короче проверить
{
    int x;
    int y;
    int dat;
    struct stack_elem* prev; // -- ??
};

// стек в виде массива, стек в виде односвзного списка //////////////////// <----

void print_stack(struct stack_elem* head)
{

}

int push_stack(struct stack_elem* head, struct stack_elem* neww, int* qr_sz, int max_sz)
{
    if (*qr_sz >= max_sz)
    {
        return 0;    // ошибка
    }
    else
    {
        //stack_elem* temp;

        // copy
        neww->prev = head;  // ---------- ??
        head = neww;

        return 1;
    }
}

int pop_stack(struct stack_elem* head, int qr_sz, int max_sz) // --- ??
{

}

int find_in_stack()
{

}

int get_bg_nd()
{

}

int get_cell_list()
{

}

int init_stack()
{

}


