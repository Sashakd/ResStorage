#include "read.h"
#include "operations.h"

struct BinTree *tree_create(struct BinTree *root, FILE *f)
{
    char w[30];
    char symb;
    int i = 0;

    while (!feof(f))
    {
        symb = fgetc(f);
        while (symb == ' ' || symb == '\n' || symb == '\t')
            symb = fgetc(f);
        i = 0;
        while (symb != ' ' && symb != '\n' && symb != '\t' && !feof(f))
        {
            w[i] = symb;
            i++;
            symb = fgetc(f);
        }
        w[i] = '\0';
        root = InsIteration(root, w);
    }
    return root;
}
