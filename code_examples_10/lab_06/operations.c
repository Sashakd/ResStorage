#include "operations.h"


struct BinTree *InsIteration(struct BinTree *T, char *w)
{
    struct BinTree *vsp, *A;
    A = (struct BinTree *) malloc(sizeof(struct BinTree));
    strcpy(A->inf, w);
    A->L = NULL;
    A->R = NULL;
    if (!T)
        T = A;
    else {vsp = T;
    while (vsp)
    {if (strcmp(A->inf, vsp->inf) < 0)
        if (!vsp->L) {vsp->L=A; vsp=A->L;}
        else vsp=vsp->L;
     else
        if (!vsp->R) {vsp->R=A; vsp=A->R;}
        else vsp=vsp->R;
    }
    }
return T;
}

void PrintTree(struct BinTree *T, FILE *f)
{

    if (T) { PrintTree(T->L , f);
        if (T->L->inf != NULL )
            fprintf(f, "%s -> %s;\n", T->inf, T->L->inf);
        if (T->R->inf != NULL)
            fprintf(f, "%s -> %s;\n", T->inf, T->R->inf);
    PrintTree(T->R, f);}
}
