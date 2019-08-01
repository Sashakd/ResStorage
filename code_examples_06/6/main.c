// Вариант No 3 (24)
/*
Построить дерево в соответствии со своим вариантом задания.
Вывести его на экран в виде дерева. Реализовать основные операции
работы с деревом: обход дерева, включение,  исключение и поиск узлов.
Сравнить эффективность алгоритмов сортировки и поиска в зависимости
от высоты деревьев и степени их ветвления.

Вариант №24 — 3
Построить бинарное дерево, в вершинах которого находятся слова их
текстового файла. Вывести его на экран в виде дерева. Удалить все слова,
начинающиеся на указанную букву. Сравнить время удаления слов,
начинающихся на указанную букву, в дереве и в файле.
 */

/*
ПРИ МАЛОМ ЧИСЛЕ ПОВТОРЕНИЙ:
в лучшем случае -- лучше     ( 71% эффективности)
в среднем -- примерно так же ( ~4% эффективности)
в худшем -- очень плохо      (-50% эффективности)
в самом худшем               (-82% эффективности)

ПРИ ОБЫЧНОМ ЧИСЛЕ ПОВТОРЕНИЙ:
в среднем -- примерно ( ~ до 40%)

// Лучше всего себя ведёт при удалении не существующего элемента

при наличии циклических повторений:
    однако при наличие повторений эффективность может
    возрастать уже при втором повторении на 50%,
    но с увеличением количества повторений эффективность
    падает (примерно можно оценить как обратную
    пропорциональнось числа повторений),
    но всегда лучше обычного способа.
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 100

#include "tree_node.h"
#include "tree_graphviz.h"
#include "read.h"
#include "balance.h"

struct list_el
{
    char* data;

    struct list_el* prev;
    struct list_el* next;
};

struct list_el* add_after_el(struct list_el* head, char* tmp)
{
    struct list_el* curr = head;

    if (curr)
    {
        while (curr->next)
            curr = curr->next;

        struct list_el* buff = calloc(1, sizeof(struct list_el));

        if (buff)
        {
            curr->next = buff;
            buff->data = tmp;
            buff->prev = curr;
            buff->next = NULL;
        }

        return buff;
    }
    else
    {
        struct list_el* buff = calloc(1, sizeof(struct list_el));

        if (buff)
        {
            buff->data = tmp;
            buff->prev = NULL;
            buff->next = NULL;

            return buff;
        }
        else
            return NULL;
    }
}

//////////////////////////////////////////////
/*
struct list_el* init_c_list(FILE* f) // ///////////////// переделать в init_string_list
{
    if (cnt > 0)
    {
        struct list_el* head = NULL;

        head = add_after_el(head, 1);

        if (head)
        {
            struct list_el* curr = head;

            int i = 2;

            while (i <= cnt)
            {
                curr = add_after_el(curr, i);

                i = i+1;

                if (!curr)
                    return head;
                    //return NULL;
            }

            curr->next = head;
            head->prev = curr;

            return head;
        }
        else
            return NULL;
    }
    else
        return NULL;
}
*/
////////////////////////////

void print_c_list(FILE* f, struct list_el* head)
{
    if (head)
    {
        struct list_el* curr = head;

        //printf("\nLIST CONTAINS:\n");
        fprintf(f, "%s ", curr->data);
        curr = curr->next;

        while ((curr)&&(curr != head))
        {
            fprintf(f, "%s ", curr->data);
            curr = curr->next;
        }
    }
    else
        printf("(EMPTY)\n");
}

struct list_el* del_current(struct list_el* head)
{
    if (head != head->next)
    {
        struct list_el* prev = head->prev;
        struct list_el* next = head->next;

        free(head->data);
        free(head);

        prev->next = next;
        if (next) next->prev = prev;

        return next;
    }
    else
    {
        free(head);
        return NULL;
    }
}

void free_list(struct list_el* head)
{
    while (head)
        head = del_current(head);
}

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}
/*
int get_word_cnt(FILE* f, int max_len)
{
    char* curr;
    int len;
    int cnt = 0;

    curr = get_word_from_file(f, &len, max_len);

    if (curr)
    {
        cnt++;

        while (curr)
        {
            curr = get_word_from_file(f, &len, max_len);
            if (curr) cnt++;
        }

        free(curr);
    }

    rewind(f);

    return cnt;
}
*/

////////////////////////////////////////////////////////////  это
struct list_el* get_word_from_file_to_arr(FILE* f, int max_len)
{
    struct list_el *head = NULL;
    char *curr = NULL;
    int len;


    curr = get_word_from_file(f, &len, max_len);
    if (curr) head = add_after_el(head, curr);  else return NULL;

    //if (head) printf("HEAD IS...\n");

    if (head)
    {
        struct list_el *curr_head = head;

        while (curr)
        {
            curr = get_word_from_file(f, &len, max_len);

            if (curr) curr_head = add_after_el(curr_head, curr);

            //if (curr_head) printf("HEAD STILL IS...\n"); // после последнего слова
        }

        return head;
    }
    else
        return NULL;

}
////////////////////////////////////////////////////////////

struct list_el* del_with_char(struct list_el *head, char* ch) ///////// <== теперь здесь //////////////// ТОЧНО ЗДЕСЬ
{
    struct list_el *curr = head;

    if (curr)
    {
        while (curr)
        {
            //printf("PROCESSING...\n");
            if (strncmp(ch, curr->data, 1) == 0)
            {
                //struct list_el *trash = curr;
                struct list_el *rem1 = curr->prev;
                struct list_el *rem2 = curr->next;

                free(curr->data);
                free(curr);

                rem1->next = rem2;
                if (rem2) rem2->prev = rem1;

                curr = rem1;
            }
            else
            {
                //printf("SKIP [%s]\n", curr->data); // Всё та же проблема с последним элементом
                curr = curr->next;
            }
        }

        return head;
    }
    else
        return NULL;
}

void wd_devide(char *str) // Заменяет пробелы на \0
{
    char* pp;

    while (memchr(str, ' ', 101) != NULL)
    {
        pp = memchr(str, ' ', 101);
        memset(pp, '\0', sizeof(char));
    }

    while (memchr(str, '\n', 101) != NULL)
    {
        pp = memchr(str, '\n', 101);
        memset(pp, '\0', sizeof(char));
    }
}

void wd_gets(FILE* inp_f, FILE* out_f, int maxl, char* ch)
{
    char* str = calloc(maxl, sizeof(char));

    while (fscanf(inp_f, "%s", str) == 1)
    {
        char* bg_p = str;
        char* nd_p;

        //int code = 1;

        // приведем строку к новому виду
        wd_devide(str);

        nd_p = malloc(sizeof(char**));
        if (nd_p)
        {
            // выделяем слова и преобразуем strod-ом
            int inc = 1;
            if (*bg_p != '\0')  // адресная арифметика
                inc = 0;
            // blah-blah

            while (bg_p < str+maxl)
            {
                nd_p = (char*)memchr(bg_p+1, '\0', str-bg_p-1);
                if ((nd_p - bg_p-1) > 0)
                {
                    if (strncmp(ch, bg_p+inc, 1) != 0)
                        fprintf(out_f, "%s ", bg_p+inc); // от начала до конца слова

                    //printf("HH--[%c]-%c-[%c]\n",  *(bg_p), 178, *(nd_p-1));// 178
                }
                if (!inc)
                    inc = 1;
                bg_p = nd_p;
            }

            free(nd_p);
        }
        free(str);
        str = calloc(maxl, sizeof(char));
    }
}

int main(int argc, char* argv[])  // неверный показатель сбалансированности
{
    if ((argc == 2) || (argc == 3) || (argc == 4))
    {
        if (argc == 2)
        {
            if (strcmp(argv[1], "make_simple_test") == 0)
            {
                struct tree_node* root = NULL;

                root = make_test_tree1();

                if (root) create_tree_graph(root, "init_test_tree.gv", "init_test_tree.png");

                struct tree_node* elem1 = root;                      // root
                struct tree_node* elem2 = root->left->right;         // r_LR
                struct tree_node* elem3 = root->left->left;          // r_LL
                struct tree_node* elem4 = root->right->left->right;  // r_RLR
                struct tree_node* elem5 = root->right->right;        // r_RR

                // node_height
                printf("height(root) = %d\n",  node_height(elem1));
                printf("height(r_LR) = %d\n",  node_height(elem2));
                printf("height(r_LL) = %d\n",  node_height(elem3));
                printf("height(r_RLR) = %d\n", node_height(elem4));
                printf("height(r_RR) = %d\n",  node_height(elem5));

                printf("\n");

                // get_balance_factor
                printf("balance factor(root) = %d\n",  get_balance_factor(elem1));
                printf("balance factor(r_LR) = %d\n",  get_balance_factor(elem2));
                printf("balance factor(r_LL) = %d\n",  get_balance_factor(elem3));
                printf("balance factor(r_RLR) = %d\n",  get_balance_factor(elem4));
                printf("balance factor(r_RR) = %d\n",  get_balance_factor(elem5));

                printf("\n");

                // get_max_sublen
                printf("sub len(root) = %d\n",  get_max_sublen(elem1));
                printf("sub len(r_LR) = %d\n",  get_max_sublen(elem2));
                printf("sub len(r_LL) = %d\n",  get_max_sublen(elem3));
                printf("sub len(r_RLR) = %d\n",  get_max_sublen(elem4));
                printf("sub len(r_RR) = %d\n",  get_max_sublen(elem5));

                printf("\n");

                if (root) create_tree_graph(root, "balanced_test_tree.gv", "balanced_test_tree.png");
            }
            else
            if (strcmp(argv[1], "make_time_test") == 0)
            {
                /*
                ПРИ МАЛОМ ЧИСЛЕ ПОВТОРЕНИЙ:
                в лучшем случае -- лучше     ( 71% эффективности)
                в среднем -- примерно так же ( ~4% до 40%)
                в худшем -- очень плохо      (-50% эффективности)
                в самом худшем               (-82% эффективности)


                // Лучше всего себя ведёт при удалении не существующего элемента

                при наличии циклических повторений:
                    однако при наличие повторений эффективность может
                    возрастать уже при втором повторении на 50%,
                    но с увеличением количества повторений эффективность
                    падает (примерно можно оценить как обратную
                    пропорциональнось числа повторений),
                    но всегда лучше обычного способа.
                */
                //////////////////////////////////////////////////////////
                unsigned long long time1 = 0;
                unsigned long long time2 = 0;

                unsigned long long time3 = 0;
                unsigned long long time4 = 0;

                FILE* f_opn = NULL;
                FILE* f_res = NULL;

                int times = 100;
                unsigned long long mid_t1 = 0;
                unsigned long long mid_t2 = 0;
                char ch[] = "s";

                struct list_el* head = NULL;

                for (int i = 0; i < times; i++)
                {
                    // Обычный способ
                    head = NULL;

                    f_opn = fopen("src1.txt", "r");
                    f_res = fopen("res1.txt", "w");

                    head = get_word_from_file_to_arr(f_opn, MAXLEN);
                    //print_c_list(stdout, head);
                    time1 = tick();
                    head = del_with_char(head, ch);
                    time2 = tick();
                    //print_c_list(stdout, head);

                    if (head)  print_c_list(f_res, head);

                    //free_list(head); // <=============================
                    fclose(f_opn);
                    fclose(f_res);

                    mid_t1 += time2 - time1;

                    // С помощью бинарного дерева //////////////////////////////////////
                    // Получаем дерево из слов в файле
                    struct tree_node* root;

                    f_opn = fopen("src1.txt", "r");
                    f_res = fopen("res1.txt", "w");

                    root = get_tree_from_file(f_opn, MAXLEN);

                    struct tree_node* rem_root = root;
                    struct tree_node* sch = NULL;

                    time3 = tick();

                    sch = root;

                    while (sch)
                    {
                        //sch = DeleteNode(sch, str);
                        if (root) sch = search_ch_tree_node(root, ch); else sch = NULL;
                        if (sch) root = del_tree_node(sch);
                    }

                    root = rem_root;

                    time4 = tick();

                    print_text_tree(f_res, root); // <-- печать в виде текста

                    fclose(f_opn);
                    fclose(f_res);

                    free_tree(root);

                    mid_t2 += time4 - time3;

                    //printf("\n");
                    //printf("(.txt) T1 = %ld\n", (long int) (time2 - time1));
                    //printf("(tree) T2 = %ld\n", (long int) (time4 - time3));
                    //printf("\n");
                }

                mid_t1 = mid_t1 / times;
                mid_t2 = mid_t2 / times;

                //long int t1 = mid_t1;
                //long int t2 = mid_t2;

                double per = 0;

                printf("\n");
                printf("(       simple .txt method) mid_time = %ld (t)\n", (long int) mid_t1);
                printf("(bynary search tree method) mid_time = %ld (t)\n", (long int) mid_t2);
                per = (((double) mid_t1 - (double) mid_t2) / ((double) mid_t1)) * 100;
                printf("        efficiency = %lf (per)\n", per);

                //////////////////////////////////////////////////////////
            }
            else
                printf("  HELP:\n    main.exe [input_file.txt] [output_file.txt]"
                "\n  or\n    main.exe make_simple_test"
                "\n  or\n    main.exe make_time_test\n");
        }

        if (argc == 3)
        {
            struct tree_node* root = NULL;

            FILE* f_opn = NULL;
            FILE* f_res = NULL;

            f_opn = fopen(argv[1], "r");

            if (f_opn)
            {
                f_res = fopen(argv[2], "w");

                if (f_res)
                {
                    // Получаем дерево из слов в файле
                    root = get_tree_from_file(f_opn, MAXLEN);

                    //print_text_tree(stdout, root);

                    // Выводим дерево на печать
                    if (root) create_tree_graph(root, "init_tree.gv", "init_tree.png");

                    struct tree_node* rem_root = root;

                    struct tree_node* sch = NULL;

                    // Получаем букву для удаления из дерева
                    char str[MAXLEN] = {0};

                    printf("\nWrite char: ");

                    if (scanf("%s", str) == 1)
                    {
                        sch = root;

                        while (sch)
                        {
                            //sch = DeleteNode(sch, str);
                            if (root) sch = search_ch_tree_node(root, str); else sch = NULL;
                            if (sch) root = del_tree_node(sch);
                        }

                        root = rem_root;

                        if (root) create_tree_graph(root, "res_tree.gv", "res_tree.png");

                        printf("\n\n");
                        if (root) print_text_tree(f_res, root); // <-- печать в виде текста
                        printf("\n\n");

                        free_tree(root);
                        fclose(f_opn);
                        fclose(f_res);
                    }
                    else
                    {
                        fclose(f_opn);
                        fclose(f_res);
                        printf("ERROR! Wrong char input\n");
                        return -3;
                    }
                }
                else
                {
                    fclose(f_opn);
                    printf("ERROR! Could not create file: [%s]", argv[2]);
                    return -2;
                }
            }
            else
            {
                printf("ERROR! Could not open file: [%s]", argv[1]);
                return -1;
            }
        }

        if (argc == 4) // обход
        {
            if ((strncmp(argv[3], "-pref", 5) == 0) ||
                (strncmp(argv[3], "-infx", 5) == 0) ||
                (strncmp(argv[3], "-pstf", 5) == 0))
            {
                struct tree_node* root = NULL;

                FILE* f_opn = NULL;
                FILE* f_res = NULL;

                f_opn = fopen(argv[1], "r");

                if (f_opn)
                {
                    f_res = fopen(argv[2], "w");

                    if (f_res)
                    {
                        // Получаем дерево из слов в файле
                        root = get_tree_from_file(f_opn, MAXLEN);

                        //print_text_tree(stdout, root);

                        // Выводим дерево на печать
                        if (root) create_tree_graph(root, "init_tree.gv", "init_tree.png");

                        struct tree_node* rem_root = root;

                        if (strncmp(argv[3], "-pref", 5) == 0)
                        {
                            printf("\nRESULT:\n");
                            move_on(stdout, root, "MLR");
                            printf("\nStored in file [%s]\n", argv[2]);
                            root = rem_root;
                            move_on(f_res, root, "MLR");
                        }
                        else
                        if (strncmp(argv[3], "-infx", 5) == 0)
                        {
                            printf("\nRESULT:\n");
                            move_on(stdout, root, "LMR");
                            printf("\nStored in file [%s]\n", argv[2]);
                            root = rem_root;
                            move_on(f_res, root, "LMR");
                        }
                        else
                        if (strncmp(argv[3], "-pstf", 5) == 0)
                        {
                            printf("\nRESULT:\n");
                            move_on(stdout, root, "LRM");
                            printf("\nStored in file [%s]\n", argv[2]);
                            root = rem_root;
                            move_on(f_res, root, "LRM");
                        }

                        free_tree(root);
                        fclose(f_opn);
                        fclose(f_res);
                    }
                    else
                    {
                        fclose(f_opn);
                        printf("ERROR! Could not create file: [%s]", argv[2]);
                        return -2;
                    }
                }
                else
                {
                    printf("ERROR! Could not open file: [%s]", argv[1]);
                    return -1;
                }
            }
            else
            {
                printf("ERROR! Wrong argument [%s]\n", argv[3]);
                return -6;
            }
        }
    }
    else
        printf("  HELP:\n    main.exe [input_file.txt] [output_file.txt]"
               "\n  or\n    main.exe make_simple_test"
               "\n  or\n    main.exe make_time_test\n"
               "\n  or\n    main.exe [input_file.txt] [output_file.txt] [-argument]\n"
               "        arguments:\n          pref\n          infx\n          pstf\n");

    return 0;
}
