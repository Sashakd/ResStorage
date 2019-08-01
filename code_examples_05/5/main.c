/*
Задача №5. Вариант №5 (26)
// Не забыть кинуть в SVN
*/

#include <stdio.h>  // У меня слетел старый make, поэтому я собираю с помощью mingw32-make
#include <stdlib.h> // поэтому с рускоязычной раскладкой там не очень
#include <windows.h>

#include "matrix_gen.h"
#include "array_matrix.h"
#include "struct_matrix.h"
#include "time.h"

#define MAX_STR 40

// Вектор-строку умножить на матрицу

/*
	Номер последнего столбца, если в нём нет элементов -- отрицательный.
	Последний нижний угловой в случае его отсутствия задаётся в IA с отрицательным JA, 
	но по модулю равен номеру столбца (последнего).
*/

// 100*100 -- многовато
int auto_test(int size, double per, int times, unsigned long long *mtime_arr, int *mmem_arr, unsigned long long *mtime_str, int *mmem_str)
{
    // Автотест

    // Под массивы
    int *ar_arrA = NULL;
    int *ar_arrB = NULL;
    int *ar_arrC = NULL;

    // Под структуры
    struct matrix *st_arrA = NULL;
    struct matrix *st_arrB = NULL;
    struct matrix *st_arrC = NULL;

    // Под файлы
    FILE* file1 = NULL;
    FILE* file2 = NULL;

    // Для замеров времени
    unsigned long long time1 = 0;
    unsigned long long time2 = 0;

    unsigned long long time3 = 0;
    unsigned long long time4 = 0;

    unsigned long long t_arr = 0;
    unsigned long long t_str = 0;

    unsigned long long mid_t_arr = 0;
    unsigned long long mid_t_str = 0;

    // Для замеров памяти
    int m_arr = 0;
    int m_str = 0;

    int mid_m_arr = 0;
    int mid_m_str = 0;

    file1 = fopen("test_arr_1_01.txt", "w");
    file2 = fopen("test_arr_2_02.txt", "w");

    generate_rand_matrix(file1, 1, size, per);
    generate_rand_matrix(file2, size, size, per);

    fclose(file1);
    fclose(file2);

    file1 = fopen("test_arr_1_01.txt", "r");
    file2 = fopen("test_arr_2_02.txt", "r");

    int tr1, tr2;

    ar_arrA = read_array_matrix(file1, &tr1, &tr2);
    ar_arrB = read_array_matrix(file2, &tr1, &tr2);

    fclose(file1);
    fclose(file2);

    // Сначала умножение матриц-массивов
    for (int i = 0; i < times; i++)
    {
        time1 = tick();
        ar_arrC = multiply_array_matrix(ar_arrA, 1, size, ar_arrB, size, size, &tr1, &tr2);
        time2 = tick();

        m_arr = (size + size*size + size)*sizeof(int);
        mid_m_arr += m_arr;

        t_arr = time2 - time1;
        mid_t_arr += t_arr;

        if (ar_arrC) free(ar_arrC);
    }

    mid_m_arr = mid_m_arr / times;
    mid_t_arr = mid_t_arr / (unsigned long long)times;

    *mtime_arr = mid_t_arr;
    *mmem_arr  = mid_m_arr;

    if (ar_arrA) free(ar_arrA);
    if (ar_arrB) free(ar_arrB);
    if (ar_arrC) free(ar_arrC);

    file1 = fopen("test_arr_1_01.txt", "r");
    file2 = fopen("test_arr_2_02.txt", "r");

    st_arrA = read_struct_matrix(file1, &tr1);
    st_arrB = read_struct_matrix(file2, &tr1);

    // Затем умножение разреженных матриц
    for (int i = 0; i < times; i++)
    {
        m_str = 0;
        time3 = tick();
        if ((st_arrA) && (st_arrB)) st_arrC = multiply_struct_vec_on_matrix(st_arrA, st_arrB);
        time4 = tick();

        m_str += calc_memory_struct_matrix(st_arrA);
        m_str += calc_memory_struct_matrix(st_arrB);
        if (st_arrC) m_str += calc_memory_struct_matrix(st_arrC);
        mid_m_str += m_str;

        t_str = time4 - time3;
        mid_t_str += t_str;

        if (st_arrC) free_struct_matrix(st_arrC);
    }

    mid_m_str = mid_m_str / times;
    mid_t_str = mid_t_str / (unsigned long long)times;

    *mtime_str = mid_t_str;
    *mmem_str  = mid_m_str;

    if (st_arrA) free_struct_matrix(st_arrA);
    if (st_arrB) free_struct_matrix(st_arrB);


    fclose(file1);
    fclose(file2);

    return 1;
}


/*
        printf("-----------------------------------------------------------------------\n");
        printf("      For A[%d, %d] * B[%d, %d]  (for %d and %d elements)\n", row1, col1, row2, col2, row1*col1, row2*col2);
        printf("-----------------------------------\n");
        printf("    For %lf (per) filling", per);

            // Подсчёты времени и памяти
            printf("\n   -- for array matrix:\n");
            printf("         time   = %ld (tics)", time2 - time1);
            printf("  (summ) memory = %d (bytes)\n", mem_arr_A + mem_arr_B + mem_arr_C);
            printf(" (A arr) memory = %d (bytes)\n", mem_arr_A);
            printf(" (B arr) memory = %d (bytes)\n", mem_arr_B);
            printf(" (C arr) memory = %d (bytes)\n", mem_arr_C);

            printf("\n      -- for rared matrix:\n");
            printf("         time   = %ld (tics)", time4 - time3);
            printf("         memory = %d (bytes)\n", mem_str_A + mem_str_B + mem_str_C);
            printf(" (A arr) memory = %d (bytes)\n", mem_str_A);
            printf(" (B arr) memory = %d (bytes)\n", mem_str_B);
            printf(" (C arr) memory = %d (bytes)\n", mem_str_C);

            printf("\n      -- efficiency:\n");

            int d_t = (time2 - time1) - (time4 - time3);
            //printf("[dt = %d]\n", d_t);
            int t   = time2 - time1;
            float result1 = ((float)d_t / (float)t)*100;
            float d_m = (mem_arr_A + mem_arr_B + mem_arr_C) - (mem_str_A + mem_str_B + mem_str_C);
            float m   = (mem_arr_A + mem_arr_B + mem_arr_C);
            float result2 = ((d_m / m)*100);
            printf("         time (rared better when array on) %f (per)\n", result1);
            printf("       memory (rared better when array on) %f (per)\n", result2);

*/

int main(int argc, char* argv[])
{
    FILE* fA   = NULL;
    FILE* fB   = NULL;
    FILE* fOut = NULL;
	
    if (argc == 3)
    {
        fA = fopen(argv[1], "r");

        if (fA)
        {
            fB = fopen(argv[2], "r");

            if (fB)  // Возможно начать выполнение
            {
                int choice = 0;
                char out_file[MAX_STR];

                printf("  This program multiplyes matrix-vector (line) on other (optional) matrix in two ways:\n"
                       "  1) multiplyes them as array (stored in arr[][]);\n"
                       "  2) multiplyes them as rared matrix (stored in structure without \'0\' elements);\n\n");

                while (1)
                {
                    // ПРИНТ МЕНЮ
                    printf("  -- MENU:\n"
                           "  0 -- exit;\n"
                           "  1 -- multiply [%s] on [%s] as array;\n", argv[1], argv[2]);
                    printf("  2 -- multiply [%s] on [%s] as rared matrix;\n", argv[1], argv[2]);
                    printf("  3 -- set result file;\n"
                           "  4 -- make auto memory-time test;\n"
                           "  5 -- generate matrix and store in file;\n");

                    if (scanf("%d", &choice) == 1)
                    {
                        switch(choice)
                        {
                            case 0:
                            {
                                fclose(fA);  fclose(fB);
                                if (fOut)    fclose(fOut);
                                return 0;
                            }
                            case 1:
                            {
                                // Как массив:
                                int *arrA = NULL;  int rA, cA;
                                int *arrB = NULL;  int rB, cB;
                                int *arrC = NULL;  int rC, cC;

                                rewind(fA);
                                rewind(fB);

                                arrA = read_array_matrix(fA, &rA, &cA);

                                if (arrA)
                                {
                                    arrB = read_array_matrix(fB, &rB, &cB);

                                    if (arrB)
                                    {
                                        arrC = multiply_array_matrix(arrA, rA, cA, arrB, rB, cB, &rC, &cC);

                                        if (arrC)
                                        {
                                            printf("\n");
                                            print_array_matrix(stdout, arrA, rA, cA);
                                            printf("\n");
                                            printf("    X\n");
                                            printf("\n");
                                            print_array_matrix(stdout, arrB, rB, cB);
                                            printf("\n");
                                            printf("    =\n");
                                            printf("\n");
                                            print_array_matrix(stdout, arrC, rC, cC);

                                            if (fOut)
                                            {
                                                printf("            Result stored in file [%s]\n", out_file);
                                                fprintf(fOut, "r: %d c: %d\n", rC, cC);
                                                print_array_matrix(fOut, arrC, rC, cC);
                                            }
                                        }
                                        else
                                        {
                                            free(arrA);
                                            free(arrB);
                                            printf("WARNING:  Can\'t calculate a result matrix. \n"
                                                   "(maybe needs [rows of first == cols of second] -- this  )\n"
                                                   "(is a necessary condition for array matrix multiplying  )\n"
                                                   "\nPlease try again\n");
                                        }
                                    }
                                    else
                                    {
                                        free(arrA);
                                        printf("WARNING:  Can\'t read the second matrix. Please try again\n");
                                    }
                                }
                                else
                                    printf("WARNING:  Can\'t read the first matrix. Please try again\n");

                                break;
                            }
                            case 2:
                            {
                                // Как разреженная матрица
                                struct matrix *arrA = NULL;
                                struct matrix *arrB = NULL;
                                struct matrix *arrC = NULL;
                                int r = 0;

                                rewind(fA);
                                rewind(fB);

                                arrA = read_struct_matrix(fA, &r);

                                if (arrA)
                                {
                                    if (r == 1)
                                    {
                                        arrB = read_struct_matrix(fB, &r);

                                        if (arrB)
                                        {
                                            arrC = multiply_struct_vec_on_matrix(arrA, arrB);

                                            if (arrC)
                                            {
                                                printf("\n");
                                                print_struct_matrix(stdout, arrA);
                                                printf("\n");
                                                printf("    X\n");
                                                printf("\n");
                                                print_struct_matrix(stdout, arrB);
                                                printf("\n");
                                                printf("    =\n");
                                                printf("\n");
                                                print_struct_matrix(stdout, arrC);

                                                if (fOut)
                                                {
                                                    int r_out, c_out;
                                                    printf("            Result stored in file [%s]\n", out_file);
                                                    get_rc_cnt(arrC, &r_out, &c_out);
                                                    fprintf(fOut, "r: %d c: %d\n", r_out, c_out);
                                                    print_struct_matrix(fOut, arrC);
                                                }
                                            }
                                            else
                                            {
                                                free_struct_matrix(arrA);
                                                free_struct_matrix(arrB);
                                                printf("WARNING:  Can\'t calculate a result matrix. \n"
                                                       "(maybe needs [rows of first == 1] -- this is a          )\n"
                                                       "(necessary condition for rared matrix multiplying       )\n"
                                                       "\nPlease try again\n");
                                            }
                                        }
                                        else
                                        {
                                            free_struct_matrix(arrA);
                                            printf("WARNING:  Can\'t read the second matrix. Please try again\n");
                                        }
                                    }
                                    else
                                    {
                                        free_struct_matrix(arrA);
                                        printf("WARNING:  First matrix could be as matrix-vector (line). Please try again\n");
                                    }
                                }
                                else
                                    printf("WARNING:  Can\'t read the first matrix. Please try again\n");

                                break;
                            }
                            case 3:
                            {
                                if (!fOut)
                                {
                                    printf("    Write name of file: ");
                                    if (scanf("%s", out_file) == 1)
                                    {
                                        fOut = fopen(out_file, "w");

                                        if (fOut)
                                            printf("File [%s] is already set as result file\n", out_file);
                                        else
                                            printf("WARNING: Could not create file [%s]. Please try again\n", out_file);
                                    }
                                    else
                                    {
                                        printf("ERROR:  Wrong file name input\n");
                                        fclose(fA);  fclose(fB);
                                        return -4;
                                    }
                                }
                                else
                                    printf("WARNING:  Result file is already set as [%s]\n", out_file);

                                break;
                            }
                            case 4:
                            {

                                int size = 50; // 14
                                double per = 10.0; // 4.0  // <=== менять эту цифру

                                // 5% -- всё ещё лучше по времени
                                //

                                unsigned long long mtime_arr = 0;
                                int mmem_arr = 0;
                                unsigned long long mtime_str = 0;
                                int mmem_str = 0;

                                while (size < 60)
                                {
                                    while (per > 1)
                                    {
                                        auto_test(size, per, 100000, &mtime_arr, &mmem_arr, &mtime_str, &mmem_str);

                                        printf("-----------------------------------------------------------------------\n");
                                        printf("      For A[%d, %d] * B[%d, %d]  (for %d and %d elements)\n", 1, size, size, size, size, size*size);
                                        printf("-----------------------------------\n");
                                        printf("    For %lf (per) filling", per);

                                        // Подсчёты времени и памяти
                                        printf("   -- for array matrix:\n");
                                        printf("         time   = %ld (tics)", mtime_arr);
                                        printf("  (summ) memory = %d (bytes)\n", mmem_arr);

                                        printf("      -- for rared matrix:\n");
                                        printf("         time   = %ld (tics)", mtime_str);
                                        printf("         memory = %d (bytes)\n", mmem_str);

                                        printf("      -- efficiency:\n");

                                        int d_t = mtime_arr - mtime_str;
                                            //printf("[dt = %d]\n", d_t);
                                        float result1 = ((float)d_t / (float)mtime_arr)*100;

                                        float d_m = mmem_arr - mmem_str;
                                        float result2 = ((d_m / mmem_arr)*100);
                                        printf("         time (rared better when array on) %f (per)\n", result1);
                                        printf("       memory (rared better when array on) %f (per)\n", result2);
                                        printf("                            For %lf (per) filling", per);
                                        Sleep(100);

                                        per -= 0.1;
                                    }

                                    size += 10;
                                }

                                //int auto_test(int size, double per, int times, unsigned long long *mtime_arr, int *mmem_arr, unsigned long long *mtime_str, int *mmem_str);

                                break; ///////////////////////////////////////////
                            }
                            case 5:
                            {
                                // Генератор матриц
                                int r = 0;
                                int c = 0;
                                double per = 0.0;
                                printf("-- MATRIX GEN:\n");
                                printf("Set row: ");

                                if (scanf("%d", &r) == 1)
                                {
                                    printf("Set col: ");

                                    if (scanf("%d", &c) == 1)
                                    {
                                        printf("Set filling (percent): ");

                                        if (scanf("%lf", &per) == 1)
                                        {
                                            FILE* gen_f = NULL;
                                            char gen_file[MAX_STR];

                                            printf("Set output file name: ");

                                            if (scanf("%s", gen_file) == 1)
                                            {
                                                gen_f = fopen(gen_file, "w");

                                                if (gen_f)
                                                {
                                                    if (!generate_rand_matrix(gen_f, r, c, per))
                                                        printf("WARNING:  Could not generate matrix. Please try again\n");

                                                    fclose(gen_f);
                                                }
                                                else
                                                    printf("WARNING:  Wrong file name input. Please try again\n");
                                            }
                                            else
                                            {
                                                printf("ERROR:  Wrong file name input\n");
                                                fclose(fA);  fclose(fB);
                                                if (fOut)    fclose(fOut);
                                                return -7;
                                            }
                                        }
                                        else
                                        {
                                            printf("ERROR:  Wrong persent input (needs double format)\n");
                                            fclose(fA);  fclose(fB);
                                            if (fOut)    fclose(fOut);
                                            return -6;
                                        }
                                    }
                                    else
                                    {
                                        printf("ERROR:  Wrong col input\n");
                                        fclose(fA);  fclose(fB);
                                        if (fOut)    fclose(fOut);
                                        return -5;
                                    }
                                }
                                else
                                {
                                    printf("ERROR:  Wrong row input\n");
                                    fclose(fA);  fclose(fB);
                                    if (fOut)    fclose(fOut);
                                    return -4;
                                }

                                break;
                            }
                            default:
                            {
                                printf("WARNING:  There\'s not such a command. Please try again\n");
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("ERROR:  Wrong command input\n");
                        fclose(fA);  fclose(fB);
                        return -3;
                    }
                }
            }
            else
            {
                printf("ERROR:  Could not open file [%s]\n", argv[2]);
                fclose(fA);
                return -2;
            }
        }
        else
        {
            printf("ERROR:  Could not open file [%s]\n", argv[1]);
            return -1;
        }
    }
    else
    {
        printf("-- HELP:\n    main.exe [matrix_A.txt] [matrix_B.txt]\n\n"
               "        (main.exe needs two arguments                  )\n"
               "        (This files could contain one matrix           )\n"
               "        (EXAMPLE: main.exe some_file.txt other_file.txt)");
    }

	return 0;
}

/*
    f1 = fopen("a.txt", "r");
    f2 = fopen("b.txt", "r");


    int r1 = 0;
    int r2 = 0;

    struct matrix* A = read_struct_matrix(f1, &r1);
    struct matrix* B = read_struct_matrix(f2, &r2);


    print_struct_matrix(stdout, A);

    //debug_print_struct_matrix(stdout, A);


    printf("\n    X  \n\n");
    print_struct_matrix(stdout, B);
    //debug_print_struct_matrix(stdout, B);

    printf("\n    =  \n\n");

    struct matrix* C = multiply_struct_vec_on_matrix(A, B);

    if (C)
    {
        print_struct_matrix(stdout, C);
        //debug_print_struct_matrix(stdout, C);
    }
*/
    /*
    int bg = 3;
    int nd = 3;
    int j  = 1;
    int fnd_c = find_c_in_row(B->A, B->JA, bg, nd, j);

    printf("[find_c = %d; bg = %d; nd = %d; j = %d]", fnd_c, bg, nd, j);
    */
    /*
    int bg = 3;
    B->Nk = B->Nk->next->next;
    int nd = get_row_end(B);

    printf("[bg = %d; nd = %d;]", bg, nd);
    */
/*
    int mem_a = calc_memory_struct_matrix(A);
    int mem_b = calc_memory_struct_matrix(B);
    int mem_c = calc_memory_struct_matrix(C);
    printf("-- Memory used:\n    A: %d bytes;\n    B: %d bytes;\n"
           "    C: %d bytes;\n Summ: %d bytes;\n", mem_a, mem_b, mem_c, mem_a + mem_b + mem_c);
*/

/*
 *-----------------------------------
    For 3.000000 (per) filling   -- for array matrix:
         time   = 24197 (tics)  (summ) memory = 10400 (bytes)
      -- for rared matrix:
         time   = 22533 (tics)         memory = 1068 (bytes)
      -- efficiency:
         time (rared better when array on) 6.876885 (per)
       memory (rared better when array on) 89.730766 (per)
-----------------------------------------------------------------------
      For A[1, 50] * B[50, 50]  (for 50 and 2500 elements)
-----------------------------------
    For 2.900000 (per) filling   -- for array matrix:
         time   = 25099 (tics)  (summ) memory = 10400 (bytes)
      -- for rared matrix:
         time   = 25272 (tics)         memory = 1068 (bytes)
      -- efficiency:
         time (rared better when array on) -0.689270 (per)
       memory (rared better when array on) 89.730766 (per)
-----------------------------------------------------------------------
      For A[1, 50] * B[50, 50]  (for 50 and 2500 elements)
-----------------------------------
    For 2.800000 (per) filling   -- for array matrix:
         time   = 24243 (tics)  (summ) memory = 10400 (bytes)
      -- for rared matrix:
         time   = 24763 (tics)         memory = 1052 (bytes)
      -- efficiency:
         time (rared better when array on) -2.144949 (per)
       memory (rared better when array on) 89.884613 (per)
-----------------------------------------------------------------------
      For A[1, 50] * B[50, 50]  (for 50 and 2500 elements)
-----------------------------------
    For 2.700000 (per) filling   -- for array matrix:
         time   = 24588 (tics)  (summ) memory = 10400 (bytes)
      -- for rared matrix:
         time   = 24486 (tics)         memory = 1028 (bytes)
      -- efficiency:
         time (rared better when array on) 0.414836 (per)
       memory (rared better when array on) 90.115387 (per)
-----------------------------------------------------------------------
      For A[1, 50] * B[50, 50]  (for 50 and 2500 elements)
-----------------------------------
    For 2.600000 (per) filling   -- for array matrix:
         time   = 24551 (tics)  (summ) memory = 10400 (bytes)
      -- for rared matrix:
         time   = 24886 (tics)         memory = 1012 (bytes)
      -- efficiency:
         time (rared better when array on) -1.364506 (per)
       memory (rared better when array on) 90.269234 (per)
-----------------------------------------------------------------------
      For A[1, 50] * B[50, 50]  (for 50 and 2500 elements)
-----------------------------------
    For 2.500000 (per) filling   -- for array matrix:
         time   = 24546 (tics)  (summ) memory = 10400 (bytes)
      -- for rared matrix:
         time   = 20914 (tics)         memory = 964 (bytes)
      -- efficiency:
         time (rared better when array on) 14.796708 (per)
       memory (rared better when array on) 90.730766 (per)
-----------------------------------------------------------------------
      For A[1, 50] * B[50, 50]  (for 50 and 2500 elements)
-----------------------------------
    For 2.400000 (per) filling   -- for array matrix:
         time   = 24081 (tics)  (summ) memory = 10400 (bytes)
      -- for rared matrix:
         time   = 20689 (tics)         memory = 948 (bytes)
      -- efficiency:
         time (rared better when array on) 14.085793 (per)
       memory (rared better when array on) 90.884613 (per)
-----------------------------------------------------------------------
      For A[1, 50] * B[50, 50]  (for 50 and 2500 elements)
-----------------------------------
    For 2.300000 (per) filling   -- for array matrix:
         time   = 24481 (tics)  (summ) memory = 10400 (bytes)
      -- for rared matrix:
         time   = 20433 (tics)         memory = 924 (bytes)
      -- efficiency:
         time (rared better when array on) 16.535273 (per)
       memory (rared better when array on) 91.115387 (per)

*/
