#include <stdio.h>

#include "operations.h"
#include "read.h"
#include "structures.h"

int main(int argc, char **argv)
{
    FILE *f;
    FILE *out;
    struct BinTree *root = NULL;

    if (argc == 2)
    {
        f = fopen(argv[1], "r");
        out = fopen("out.gv", "w");
        root = tree_create(root, f);
        fprintf(out, "digraph A {\n");
        PrintTree(root, out);
        fprintf(out, "}");
        fclose(out);
        //system("D:/dot/bin/dot.exe out.gv -Tpng -o graph.png");///// <---here
		system("dot.exe out.gv -Tpng -o graph.png");
        system("graph.png");
    }
    return 0;
}
