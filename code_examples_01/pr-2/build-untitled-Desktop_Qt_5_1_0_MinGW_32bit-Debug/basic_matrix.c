#include "basic_matrix.h"

double** matr_init(const int w, const int h)
{
    double** matr = calloc(h, sizeof(double*));

    if (!matr)
        return NULL;

    for (int i = 0; i < h; i++)
    {
        *(matr + i) = calloc(w, sizeof(double));
        if (!(*(matr + i)))
            return NULL;
    }

    return matr;
}

double** read_matr_fr_file(FILE* f, int* row, int* col)
{
    int r = 0;
    int c = 0;

    if (fscanf(f, "w: %d h: %d", &c, &r) == 2)
    {
        if ((r <= 0) || (c <= 0))
            return NULL;

        double** M = matr_init(c, r);

        if (M)
        {
            double tmp = 0.0;
            *row = r;
            *col = c;   // До этого момента отлично

            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                {
                    if (fscanf(f, "%lf", &tmp) == 1)
                        *(*(M + i) + j) = tmp;
                    else
                    {
                        matr_free(M, c);
                        return NULL;
                    }
                }

            return M;
        }
        else
            return NULL;
    }
    else
        return NULL;
}

// Норм
void print_matr(FILE* f, double** M, const int row, const int col)
{
    fprintf(f, "w: %d h: %d\n", col, row);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            fprintf(f, " %6.2lf", *(*(M + i) + j));
        fprintf(f, "\n");
    }
}

void matr_free(double** matr, const int h)
{
    for (int i = 0; i < h; i++)
        free(*(matr + i));

    free(matr);
}
