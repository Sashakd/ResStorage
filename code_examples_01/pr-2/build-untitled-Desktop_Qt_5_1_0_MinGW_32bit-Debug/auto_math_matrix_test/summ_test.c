#include <stdio.h>
#include <stdlib.h>

#include "../basic_matrix.h"
#include "../math_matrix.h"

/*
Все последующие утечки вытекают из:

 *~~Dr.M~~ Error #1: POSSIBLE LEAK 23 direct bytes 0x00dc00f8-0x00dc010f + 0 indir
ect bytes
~~Dr.M~~ # 0 replace_malloc                    [d:\drmemory_package\common\alloc
_replace.c:2384]
~~Dr.M~~ # 1 msvcrt.dll!strcpy_s              +0x67     (0x76d6fad8 <msvcrt.dll+
0xfad8>)
~~Dr.M~~ # 2 msvcrt.dll!getpid                +0x18f    (0x76d7ef00 <msvcrt.dll+
0x1ef00>)
~~Dr.M~~ # 3 msvcrt.dll!getpid                +0xdb     (0x76d7ee4c <msvcrt.dll+
0x1ee4c>)
~~Dr.M~~ # 4 pre_cpp_init
~~Dr.M~~ # 5 __tmainCRTStartup
~~Dr.M~~ # 6 KERNEL32.dll!BaseThreadInitThunk +0x23     (0x775c7c04 <KERNEL32.dl
l+0x17c04>)
~~Dr.M~~

Возникает при первом выделении памяти ничего не могу с этим поделать
*/

int main()
{
    /*
    double expected_for_A = 1.1;   // 1*1
    double expected_for_B = -4.86; // 2*2
    double expected_for_C = 2.42;  // 2*2
    double expected_for_D = 2.42;  // 2*2
    double expected_for_E = 24.23652;  // 4*4
    double expected_for_F = 283.786408;  // 4*4
    */

    FILE *fA1 = NULL;
    FILE *fA2 = NULL;

    double **M1 = NULL;
    double **M2 = NULL;
    double **M = NULL;
    int r1 = 0;
    int c1 = 0;
    int r2 = 0;
    int c2 = 0;
    int r = 0;
    int c = 0;
    //double det = 0;

    fA1 = fopen("for_summ/A1.txt", "r");
    fA2 = fopen("for_summ/A2.txt", "r");

    if ((!fA1) || (!fA2))
    {
        if (fA1)
            fclose(fA1);

        if (fA2)
            fclose(fA2);

        return 0;
    }

    M1 = read_matr_fr_file(fA1, &r1, &c1);
    M2 = read_matr_fr_file(fA2, &r2, &c2);

    if ((!M1) || (!M2))
    {
        if (M1)
            matr_free(M1, r1);
        if (M2)
            matr_free(M2, r2);

        return 0;
    }

    M = summ_matr(M1, r1, c1, M2, r2, c2, &r, &c);

    if (M)
    {
        print_matr(stdout, M1, r1, c1);
        printf("\n	+\n");
        print_matr(stdout, M2, r2, c2);
        printf("\n	=\n");
        printf("(REAL:)\n");
        print_matr(stdout, M, r, c);
        printf("(EXPECTED:)\n");

        FILE *fAE = NULL;

        fAE = fopen("for_summ/A3.txt", "r");
        double **ME = NULL;
        int rE = 0;
        int cE = 0;

        ME = read_matr_fr_file(fAE, &rE, &cE);
        print_matr(stdout, ME, rE, cE);

        matr_free(ME, rE);
        fclose(fAE);

        matr_free(M, r);
    }
    else
    {
        if (fA1)
            fclose(fA1);

        if (fA2)
            fclose(fA2);
    }

    if (fA1)
        fclose(fA1);

    if (fA2)
        fclose(fA2);

    printf("-------------------------------------------------\n");

    fA1 = fopen("for_summ/B1.txt", "r");
    fA2 = fopen("for_summ/B2.txt", "r");

    if ((!fA1) || (!fA2))
    {
        if (fA1)
            fclose(fA1);

        if (fA2)
            fclose(fA2);

        return 0;
    }

    M1 = read_matr_fr_file(fA1, &r1, &c1);
    M2 = read_matr_fr_file(fA2, &r2, &c2);

    if ((!M1) || (!M2))
    {
        if (M1)
            matr_free(M1, r1);
        if (M2)
            matr_free(M2, r2);

        return 0;
    }

    M = summ_matr(M1, r1, c1, M2, r2, c2, &r, &c);

    if (M)
    {
        print_matr(stdout, M1, r1, c1);
        printf("\n	+\n");
        print_matr(stdout, M2, r2, c2);
        printf("\n	=\n");
        printf("(REAL:)\n");
        print_matr(stdout, M, r, c);
        printf("(EXPECTED:)\n");

        FILE *fAE = NULL;

        fAE = fopen("for_summ/B3.txt", "r");
        double **ME = NULL;
        int rE = 0;
        int cE = 0;

        ME = read_matr_fr_file(fAE, &rE, &cE);
        print_matr(stdout, ME, rE, cE);

        matr_free(ME, rE);
        fclose(fAE);

        matr_free(M, r);
    }
    else
    {
        if (fA1)
            fclose(fA1);

        if (fA2)
            fclose(fA2);
    }

    if (fA1)
        fclose(fA1);

    if (fA2)
        fclose(fA2);

    printf("-------------------------------------------------\n");

    fA1 = fopen("for_summ/C1.txt", "r");
    fA2 = fopen("for_summ/C2.txt", "r");

    if ((!fA1) || (!fA2))
    {
        if (fA1)
            fclose(fA1);

        if (fA2)
            fclose(fA2);

        return 0;
    }

    M1 = read_matr_fr_file(fA1, &r1, &c1);
    M2 = read_matr_fr_file(fA2, &r2, &c2);

    if ((!M1) || (!M2))
    {
        if (M1)
            matr_free(M1, r1);
        if (M2)
            matr_free(M2, r2);

        return 0;
    }

    M = summ_matr(M1, r1, c1, M2, r2, c2, &r, &c);

    if (M)
    {
        print_matr(stdout, M1, r1, c1);
        printf("\n	+\n");
        print_matr(stdout, M2, r2, c2);
        printf("\n	=\n");
        printf("(REAL:)\n");
        print_matr(stdout, M, r, c);
        printf("(EXPECTED:)\n");

        FILE *fAE = NULL;

        fAE = fopen("for_summ/C3.txt", "r");
        double **ME = NULL;
        int rE = 0;
        int cE = 0;

        ME = read_matr_fr_file(fAE, &rE, &cE);
        print_matr(stdout, ME, rE, cE);

        matr_free(ME, rE);
        fclose(fAE);

        matr_free(M, r);
    }
    else
    {
        if (fA1)
            fclose(fA1);

        if (fA2)
            fclose(fA2);
    }

    if (fA1)
        fclose(fA1);

    if (fA2)
        fclose(fA2);

    return 1;
}
