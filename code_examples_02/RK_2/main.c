#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
Вариант 6.

Даны два упорядоченных по невозрастанию списка.
Объедините их в новый упорядоченный по
невозрастанию список. Количество действий O(N+M),
где N и M -- длины списков.
*/
int main(int argc, char* argv[])
{
    FILE* inp1_f = NULL;
    FILE* inp2_f = NULL;
    FILE* out_f = NULL;

    if ((argc == 3) || (argc == 4))
    {
        inp1_f = fopen(argv[1], "r");

        if (inp1_f)
        {
            inp2_f = fopen(argv[2], "r");

            if (inp2_f)
            {
                if (argc == 3)
                    out_f = stdout;
                else
                    out_f = fopen(argv[3], "w");

                if (out_f)
                {
                    struct list_el* list1 = NULL;
                    struct list_el* list2 = NULL;
                    struct list_el* result = NULL;

                    list1 = read_list_from_file(inp1_f);

                    if (list1)
                    {
                        list2 = read_list_from_file(inp2_f);

                        if (list2)
                        {

                            fprintf(stdout, "\nLIST_1:\n");
                            print_list(stdout, list1);
                            fprintf(stdout, "\n\nLIST_2:\n");
                            print_list(stdout, list2);

                            result = lists_uny(list1, list2);

                            printf("\n\nRESULT:\n");

                            if (result)
                            {
                                if (argc == 4)
                                    printf("    in file [%s]\n", argv[3]);

                                print_list(out_f, result);
                            }
                            else
                                printf("(NONE)\n");

                            fclose(inp1_f);
                            fclose(inp2_f);

                            if (argc == 4)
                                fclose(out_f);

                            if (result)
                                free_list(result);
                            else
                            {
                                free_list(list1);
                                free_list(list2);
                            }
                        }
                        else
                        {
                            printf("ERROR! Could not read list from file [%s]", argv[2]);
                            fclose(inp1_f);
                            fclose(inp2_f);

                            if (argc == 4)
                                fclose(out_f);

                            free_list(list1);

                            return -5;
                        }
                    }
                    else
                    {
                        printf("ERROR! Could not read list from file [%s]", argv[1]);
                        fclose(inp1_f);
                        fclose(inp2_f);

                        if (argc == 4)
                            fclose(out_f);

                        return -4;
                    }
                }
                else
                {
                    printf("ERROR! Could not create file [%s]", argv[3]);
                    fclose(inp1_f);
                    fclose(inp2_f);
                    return -3;
                }
            }
            else
            {
                printf("ERROR! Could not open file [%s]", argv[2]);
                fclose(inp1_f);
                return -2;
            }
        }
        else
        {
            printf("ERROR! Could not open file [%s]", argv[1]);
            return -1;
        }
    }
    else
        printf("HELP:\n"
               "    uny.exe [input1.txt] [input2.txt]\n"
               "        or\n"
               "    uny.exe [input1.txt] [input2.txt] [output.txt]\n");

    return 0;
}
