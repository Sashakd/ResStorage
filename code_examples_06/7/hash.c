#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#include "findtime.h"
#include "usltree.h"
#include "baltree.h"
#include "windows.h"

// ������������ �����
char *strdup(const char *str)
{
    char* result;
    int k=0;
    while (str[k++]!='\0');
    k++;
    result = (char *)malloc(k*sizeof(char));
    if (!result)
        return NULL;
    k = 0;
    while (str[k]!='\0')
    {
        result[k] = str[k];
        k++;
    }
    result[k] = '\0';
    return result;
}

// ������ �������� ���������
struct chainlist
{
    char* word;
    int cpy;
    struct chainlist* next;
};

// �������� ��������� ��� �������� ���������
struct chainlist* createChain(char* word)
{
    struct chainlist *node = malloc(sizeof(struct chainlist));
    if (node)
    {
        node->word = word;
        node->cpy = 0;
        node->next = NULL;
    }
    return node;
}

// ���-�������
int hashfunc(char* word, const int* mas)
{
    int i, sum=0;
    for (i=0; i<strlen(word)+1; i++)
        sum = sum + (word[i] ^ mas[i]);
    sum = sum % 256;
    return sum;
}

// ���������� ������� ��������� �����
void fillnull(int* mas)
{
    int i;
    for (i=0; i<256; i++)
        mas[i] = rand() % 255;
}

// ����� ��� �������� ���������
struct chainlist* searchop(char* word, struct chainlist *masop[256], const int* mas, int *ch)
{
    int i;
    struct chainlist *p, *q;
    i = hashfunc(word, mas);
    p = masop[i];
    q = NULL;
    while (p != NULL)
    {
        (*ch)++;
        if (strcmp(p->word, word) == 0)
        {
            return p;
        }
        q = p;
        p = p->next;
    }
    return q;
}

// ���������� ��� �������� ���������
int addop(char* word, struct chainlist *masop[256], const int* mas)
{
    struct chainlist *p, *node;
    int ch=0;
    p = searchop(word, masop, mas, &ch);
    int i = hashfunc(word, mas);
    if (p == NULL)
    {
        node = createChain(word);
        masop[i] = node;
        return 0;
    }
    if (p != NULL && strcmp(p->word, word) != 0)
    {
        node = createChain(word);
        p->next = node;
        return 1;
    }
    p->cpy += 1;
    return 2;
}

// ����� ��� �������� ���������
int searchcl(char* word, char *mascl[256], const int* mas, int *ch)
{
    int i=hashfunc(word, mas);
    while (mascl[i] != NULL && i < 256)
    {
        (*ch)++;
        if (strcmp(mascl[i], word) == 0)
            return i;
        i++;
    }
    return -i-1;
}

// ���������� ��� �������� ���������
int addcl(char* word, char *mascl[256], const int* mas)
{
    int ch=0;
    int i = searchcl(word, mascl, mas, &ch);
    if (i < 0)
    {
        i = -i;
        i--;
        mascl[i] = word;
        return 0;
    }
    else
        return 1;
}


int main()
{
    struct tree_node *tree=NULL, *node=NULL, *find=NULL;
    struct btree_node *treeB=NULL, *findB=NULL;
    unsigned long long tb=0, te=0, ttt1=0, ttt2=0, ttt3=0, ttt4=0;
    int ch3, ch4;
    char *str;
    int c = 1, i;
    FILE *fout1, *fout2;
    FILE *fin;

    int randm[256];
    struct chainlist *masop[256];
    struct chainlist *findop, *p;
    int findcl;
    char *mascl[256];
    int j;


    str = malloc(1000*sizeof(char));
    srand(time(NULL));
    fillnull(randm);
    for (i=0; i<256; i++)
    {
        masop[i] = NULL;
        mascl[i] = NULL;
    }

    setlocale(0, "russian");
    fin = fopen("test.txt", "r");
    while (fscanf(fin, "%s", str) == 1)
    {
        node = createNode(strdup(str));
        tree = insert(tree, node);
        treeB = insertB(treeB, strdup(str));
        addop(strdup(str), masop, randm);
        addcl(strdup(str), mascl, randm);
    }
    printf("\n��������� �������� � ���������, �����������������\n"
	       " ��������� � ���-���������.");
    while (c != 0)
    {
        printf("����:");
        printf("\n1 - ����� c���� (c� ����������)");
        printf("\n2 - �������� �����");
        printf("\n3 - ������� ��");
		printf("\n4 - ������� ��� ����� �� ���� �����");
        printf("\n0 - ����� �� ���������");
        printf("\n\n> ");
        scanf("%i", &c);
        if (c == 1)
        {
            printf("\n\n������� ����� ��� ������: ");
            scanf("%s", str);
            tb = tick();
            //for (j=0; j<1000; j++)
                find = poiskR(str, tree);
            te = tick();
            ttt1 = (te - tb)/*/1000*/;

            tb = tick();
            //for (j=0; j<1000; j++)
                findB = poiskRB(str, treeB);
            te = tick();
            ttt2 = (te - tb)/*/1000*/;

            ch3 = 0;
            tb = tick();
            //for (j=0; j<1000; j++)
                findop = searchop(str, masop, randm, &ch3);
            te = tick();
            ttt3 = (te - tb)/*/1000*/;

            ch4 = 0;
            tb = tick();
            //for (j=0; j<1000; j++)
                findcl = searchcl(str, mascl, randm, &ch4);
            te = tick();
            ttt4 = (te - tb)/*/1000*/;

            if (find == NULL)
                printf("\n������� � ������� ������ �� ������!");
            else
                printf("\n��������� � ������� ������ �������: %s", find->word);
            if (findB == NULL)
                printf("\n������� � ���������������� ������ �� ������!");
            else
                printf("\n��������� � ���������������� ������ �������: %s", findB->word);
            if (findop == NULL)
                printf("\n������� � ���-������� �  ������� ������� �� ������!");
            else
                printf("\n��������� � ���-������� � ������� ������� �������: %s", findop->word);
            if (findcl < 0)
                printf("\n������� � ���-������� � ���������� ������������ �� ������!");
            else
                printf("\n��������� � ���-������� � ���������� ������������ ������: %s", mascl[findcl]);

            printf("\n\n����� ������ � ������� ������: %llu", ttt1);
            printf("\n����� ������ � ���������������� ������: %llu", ttt2);
            printf("\n����� ������ � ���-������� c ������� �������: %llu", ttt3);
            printf("\n����� ������ � ���-������� c ���������� ������������: %llu", ttt4);
            printf("\n����� ��������� � ���-������� � ������� ������������: %i", ch3);
            printf("\n����� ��������� � ���-������� � ���������� ������������: %i", ch4);
        }
        if (c == 2)
        {
            printf("\n\n������� ����� ��� ����������: ");
            scanf("%s", str);
            node = createNode(strdup(str));
            tree = insert(tree, node);
            treeB = insertB(treeB, strdup(str));
            addop(strdup(str), masop, randm);
            addcl(strdup(str), mascl, randm);
            printf("\n���������� ������� ���������!");
        }
        if (c == 3)
        {
            fout1 = fopen("1.gv", "w");
            export_to_dot(fout1, "Tree", tree);
            fclose(fout1);
            fout2 = fopen("2.gv", "w");
            export_to_dotB(fout2, "BalanceTree", treeB);
            fclose(fout2);
            //printf("\n������� ������� �������� � ����. ����������� GraphViz ��� ������������!");
			system("dot -Tpng 1.gv -o Tree.png");
			system("Tree.png");
			system("dot -Tpng 2.gv -o BalancedTree.png");
			system("BalancedTree.png");
            printf("\n\n���-������� � ������� �������: ");
            for (j=0; j<256; j++)
            {
                p = masop[j];
                while (p != NULL)
                {
                    printf("\n [%i] - [%s]", j, p->word);
                    p = p->next;
                }
            }
            printf("\n\n���-������� � ���������� ������������: ");
            for (j=0; j<256; j++)
                if (mascl[j] != NULL)
                    printf("\n [%i] - [%s]", j, mascl[j]);

        }
        if (c == 4)
        {
            printf("\n\n������� ����� ��� �������� ����, ������������ � ��: ");
            scanf("%s", str);
            // �������
            tree = del_for_all_char_X(tree, str);
			treeB = del_for_all_char_XB(treeB, str);
            fout1 = fopen("1.gv", "w");
            export_to_dot(fout1, "Tree", tree);
            fclose(fout1);
            fout2 = fopen("2.gv", "w");
            export_to_dotB(fout2, "Balance Tree", treeB);
            fclose(fout2);
            // �������
        }
        printf("\n\n\n\n\n\n");
    }
    getchar();
    return 0;
}
