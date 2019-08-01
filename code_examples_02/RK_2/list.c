#include "list.h"

////////////////////////////////////////////////////////////////////////
/// \brief read_list_from_file -- читает целые числа из файла и
/// записывает их в список.
/// \param f -- файл с целыми числами
/// \return -- возвращает указатель на голову списка, если удалось
/// прочитать хотя бы одно слово. Иначе -- NULL
///
struct list_el* read_list_from_file(FILE* f)
{
    struct list_el* head = NULL;

    int tmp = 0;

    if (fscanf(f, "%d", &tmp) == 1)
    {
        head = malloc(sizeof(struct list_el));

        if (head)
        {
            head->data = tmp;
            head->next = NULL;

            //printf("HEAD_IS\n");

            struct list_el* curr = head;
            struct list_el* buff = NULL;

            while (fscanf(f, "%d", &tmp) == 1)
            {
                buff = malloc(sizeof(struct list_el));

                if (buff)
                {
                    buff->data = tmp;
                    buff->next = NULL;

                    curr->next = buff;
                    curr = curr->next;
                }
                else
                    return head;

                //printf("EL_IS\n");
            }

            return head;
        }
        else
            return NULL;
    }
    else
        return NULL;
}

////////////////////////////////////////////////////////////////////////
/// \brief print_list -- печатает элементы списка с данными
/// целочисленного типа.
/// \param f -- файл в который печатаются элементы, можно указать
/// в качестве файла stdout
/// \param head -- указатель на голову списка, если head == NULL,
/// то функция ничего не печатает
///
void print_list(FILE* f, struct list_el* head)
{
    while (head)
    {
        fprintf(f, "%d ", head->data);
        head = head->next;
    }
}

////////////////////////////////////////////////////////////////////////
/// \brief free_list -- освобождает список
/// \param head -- указатель на голову списка, можно указывать NULL
///
void free_list(struct list_el* head)
{
    struct list_el* trash;

    while (head)
    {
        trash = head;
        head = head->next;
        free(trash);
    }
}

////////////////////////////////////////////////////////////////////////
/// \brief lists_uny -- объединяет два упорядоченных по невозрастанию
/// списка в один, сохраняя порядок.
/// \param a -- указатель на первый список с целочисленными элементами
/// \param b -- указатель на второй список с целочисленными элементами
/// \return -- возвращает объединённый список. (Внимание! Требуется
/// освобождение памяти только возвращаемого списка)
///
struct list_el* lists_uny(struct list_el* a, struct list_el* b)
{
    struct list_el* remem_h;
    struct list_el* waste_h;

    if ((a) && (b))
    {
        // Запоминаем ведущую и ведомую голову
        if (a->data >= b->data)
        {
            remem_h = a;
            waste_h = b;
        }
        else
        {
            remem_h = b;
            waste_h = a;
        }

        struct list_el* curr_r = remem_h;
        struct list_el* curr_w = waste_h;

        // Начало основной операции
        while ((curr_r) && (curr_w))
        {
            struct list_el* rem1;
            struct list_el* rem2;

            if (curr_r->next)
            {
                if ((curr_w->data > curr_r->next->data))
                {
                    // действия
                    rem1 = curr_w;
                    curr_w = curr_w->next;
                    rem2 = curr_r->next;

                    // вставка
                    curr_r->next = rem1;
                    rem1->next = rem2;
                }
                else
                {
                    curr_r = curr_r->next;
                }
            }
            else
            {
                // Поставить в конец и закончить
                curr_r->next = curr_w;
                break;
            }
        }

        return remem_h;
    }
    else
        return NULL;
}
