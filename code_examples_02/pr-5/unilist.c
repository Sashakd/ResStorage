#include "unilist.h"

// исправить для void**
struct list_elememt* add_element_to(const char* place, struct list_elememt* head, void** tmp, int* st) // можно в начало/конец
{
    *st = 0;

    if ((strcmp(place, "begin") == 0) || (strcmp(place, "b") == 0) ||
        (strcmp(place, "end"  ) == 0) || (strcmp(place, "e") == 0))
    {
        // Добавляем в начало списка
        if ((strcmp(place, "begin") == 0) || (strcmp(place, "b") == 0))
        {
            struct list_elememt* buff = malloc(sizeof(struct list_elememt));

            if (buff)
            {
                buff->data = tmp;
                buff->next = head;

                return buff;
            }
            else
                *st = -2;
        }

        // Добавляем в конец списка
        if ((strcmp(place, "end"  ) == 0) || (strcmp(place, "e") == 0))
        {
            if (head)
            {
                struct list_elememt* curr = head;

                while (curr->next)
                    curr = curr->next;

                struct list_elememt* buff = malloc(sizeof(struct list_elememt));

                if (buff)
                {
                    buff->data = tmp;
                    buff->next = NULL;

                    curr->next = buff;

                    return head;
                }
                else
                    *st = -4;
            }
            else
            {
                struct list_elememt* buff = malloc(sizeof(struct list_elememt));

                if (buff)
                {
                    buff->data = tmp;
                    buff->next = NULL;

                    return buff;
                }
                else
                    *st = -3;
            }
        }
    }
    else
        *st = -1;

    return head;
}

// исправить для void**
struct list_elememt* del_current_element(struct list_elememt* head, struct list_elememt* current, void** out)
{
    if (head)
    {
        if (head == current)
        {
            struct list_elememt* rem = head->next;

            *out = head->data;

            free(head);

            return rem;
        }
        else
        {
            struct list_elememt* rem = head;

            while ((head->next) || (head != current))
                head = head->next;

            if (head->next)
            {
                struct list_elememt* trash = head->next;

                *out = trash->data;

                head->next = head->next->next;

                free(trash);
            }
            else
            {
                out = NULL;
                return rem;
            }


            return rem;
        }
    }
    else
    {
        out = NULL;
        return NULL;
    }
}

void* pop_front(struct list_elememt** head) // <== ???
{
    struct list_elememt* rem = (*head)->next;

    void* tmp = (*head)->data;

    free(*head);

    *head = rem;

    return tmp;
}

void* pop_end(struct list_elememt** head) // <== уже лучше, но надо подправить
{
    struct list_elememt* rem  = *head;
    struct list_elememt* prev = *head;
    void* tmp;

    while ((*head)->next)
    {
        prev = *head;
        *head = (*head)->next;
    }

    tmp = prev->next->data;

    free(prev->next);

    prev->next = NULL;

    *head = rem;

    return tmp;
}

struct list_elememt* find_elem(struct list_elememt* head, struct list_elememt* current, void** out)
{

}

struct list_elememt* copy(struct list_elememt* head)
{
    if (head)
    {
        struct list_elememt* current = head;

        struct list_elememt* head2 = malloc(sizeof(struct list_elememt));

        if (head2)
        {
            head2->data = head->data;

            current = current->next;

            struct list_elememt* current2 = head2;

            struct list_elememt* buff = NULL;

            while (current)
            {
                buff = malloc(sizeof(struct list_elememt));

                if (buff)
                {
                    current2->next = buff;
                    buff->data = current;
                    current2 = current2->next;
                    current = current->next;
                }
                else
                    return head2;
            }
        }
        else
            return NULL;
    }
    else
        return NULL;
}

void append(struct list_elememt** head_a, struct list_elememt** head_b)
{
    if (*head_a)
    {
        struct list_elememt* rem  = *head_a;

        while ((*head_a)->next)
            *head_a = (*head_a)->next;

       (*head_a)->next = *head_b;

        *head_b = NULL;
    }
    else
    {
        *head_a = *head_b;
        *head_b = NULL;
    }
}
// Подумать
/*
for j = 2 to A.length
    key = A[j]
    i = j - 1
    while i > 0 and A[i] > key
         A[i+1] = A[i]
         i = i - 1
    A[i+1] = key
*/
struct list_elememt* sorted_insert(struct list_elememt* head, void* tmp, int (*compare) (const void *, const void *))
{
    // rem
// sorted part
    struct list_elememt* current = head->next; // Список уже упорядочен, нужно найти место и вставить

    while ()
    {

    }
}
