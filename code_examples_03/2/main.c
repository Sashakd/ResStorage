#include <stdio.h>
#include <string.h>
#include <locale.h>

// ���������� �� ���� /�������� ���������/

struct theatre // ��� ������
{
	int numb;
    char name[40];
    char play[40];
    char director[40];
    int min_cost;
    int max_cost;
	
    enum {ch, ad, ms} ty;
    union
    {
        struct
        {
			int age;
			enum {fairytale, ch_play, musical} child_type;
        } child;
		
		struct
        {
			enum {play, drama, comedy} adult_type;
        } adult;

		struct
        {
			char composer[40];
        } musical;
    } type;
};

// ������� �������
unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

// ����� ������� ������
int resetmas(int* mas, int k)
{
    for (int i=0; i < k; i++)
        mas[i] = i;
    printf("\n\n\n\n\n\n");
    return 0;
}

// ��������� ���������� ������� �� �����
int fillbeg(FILE* f, struct theatre* a, int* k)
{
    char ch2;
    rewind(f);
    ch2 = fgetc(f);
	
	char ty_str[40];
	char sec_ty_str[40];
	
    while (ch2 != EOF)
    {
        ungetc(ch2,f);
        a[*k].numb = (*k) + 1;
        fscanf(f, "%s", a[*k].name);
        fscanf(f, "%s", a[*k].play);
        fscanf(f, "%s", a[*k].director);
        fscanf(f, "%i", &a[*k].min_cost);
		fscanf(f, "%i", &a[*k].max_cost);
		
		
		if (fscanf(f, "%s", ty_str) == 1)
		{
			if (strcmp(ty_str, "ch") == 0)
			{
				a[*k].ty = ch;
				
				//printf("--FUUUU--");
				//a[*k].type.child
				
				fscanf(f, "%i", &a[*k].type.child.age);
				fscanf(f, "%s", sec_ty_str);
				if (strcmp(sec_ty_str, "fairytale") == 0)
				{
					a[*k].type.child.child_type = fairytale;
				}
				else
				if (strcmp(sec_ty_str, "ch_play") == 0)
				{
					a[*k].type.child.child_type = ch_play;
				}
				else
				if (strcmp(sec_ty_str, "musical") == 0)
				{
					a[*k].type.child.child_type = musical;
				}
				else
				{
					return -3;
				}
			}
			else
			if (strcmp(ty_str, "ad") == 0)
			{
				a[*k].ty = ad;
				//a[*k].type.adult
				
				fscanf(f, "%s", sec_ty_str);
				if (strcmp(sec_ty_str, "play") == 0)
				{
					a[*k].type.adult.adult_type = play;
				}
				else
				if (strcmp(sec_ty_str, "drama") == 0)
				{
					a[*k].type.adult.adult_type = drama;
				}
				else
				if (strcmp(sec_ty_str, "comedy") == 0)
				{
					a[*k].type.adult.adult_type = comedy;
				}
				else
				{
					return -4;
				}
			}
			else
			if (strcmp(ty_str, "ms") == 0)
			{
				a[*k].ty = ms;
				fscanf(f, "%s", a[*k].type.musical.composer);
			}
			else
			{
				//printf("[FAIL READ]\n");
				return -2;
			}
		}
		else
		{
			//printf("[FAILREAD]");
			return -1;
		}
		
		/*
        if (a[*k].det)
        {
            fscanf(f, "%i", &a[*k].un.pers.year);
            fscanf(f, "%i", &a[*k].un.pers.month);
            fscanf(f, "%i", &a[*k].un.pers.day);
        }
        else
        {
            fscanf(f, "%s", a[*k].un.serv.occup);
            fscanf(f, "%s", a[*k].un.serv.organ);
        }
		*/

        ch2 = fgetc(f);
        (*k)++;
    }
	
	printf("\n\n\n\n\n\n");
	
    return 0;
}

void write_f_table(FILE* f, struct theatre* a, int* k)
{
	for (int i = 0; i < *k; i++)
	{
		if (f == stdout)
		{
			fprintf(f, "(%2d) %15s ", a[i].numb, a[i].name);
		}
		else		
			fprintf(f, "%20s ", a[i].name);
		
		fprintf(f, "%20s ", a[i].play);
		fprintf(f, "%20s ", a[i].director);
		
		fprintf(f, "%7i %7i ", a[i].min_cost, a[i].max_cost);
		
		if (a[i].ty == ch)
		{
			fprintf(f, "ch ");
			fprintf(f, "%3i ", a[i].type.child.age);
			if (a[i].type.child.child_type == fairytale)
			{
				fprintf(f, "fairytale\n");
			}
			else
			if (a[i].type.child.child_type == ch_play)
			{
				fprintf(f, "ch_play\n");
			}
			else
			if (a[i].type.child.child_type == musical)
			{
				fprintf(f, "musical\n");
			}
		}
		else
		if (a[i].ty == ad)
		{
			fprintf(f, "ad ");
			if (a[i].type.adult.adult_type == play)
			{
				fprintf(f, "play\n");
			}
			else
			if (a[i].type.adult.adult_type == drama)
			{
				fprintf(f, "drama\n");
			}
			else
			if (a[i].type.adult.adult_type == comedy)
			{
				fprintf(f, "comedy\n");
			}
		}
		else
		if (a[i].ty == ms)
		{
			fprintf(f, "ms ");
			fprintf(f, "%s\n", a[i].type.musical.composer);
		}
		else
			printf("[fail]");
	}
	
	printf("\n\n\n\n\n\n");
}

void write_key_table(FILE* f, struct theatre* a, int* k,  int* mas)
{
	for (int i = 0; i < *k; i++)
	{
		fprintf(f, "%20s ", a[mas[i]].name);
		fprintf(f, "%20s ", a[mas[i]].play);
		fprintf(f, "%20s ", a[mas[i]].director);
		
		fprintf(f, "%7i %7i ", a[mas[i]].min_cost, a[mas[i]].max_cost);
		
		if (a[mas[i]].ty == ch)
		{
			fprintf(f, "ch ");
			fprintf(f, "%3i ", a[mas[i]].type.child.age);
			if (a[mas[i]].type.child.child_type == fairytale)
			{
				fprintf(f, "fairytale\n");
			}
			else
			if (a[mas[i]].type.child.child_type == ch_play)
			{
				fprintf(f, "ch_play\n");
			}
			else
			if (a[mas[i]].type.child.child_type == musical)
			{
				fprintf(f, "musical\n");
			}
		}
		else
		if (a[mas[i]].ty == ad)
		{
			fprintf(f, "ad ");
			if (a[mas[i]].type.adult.adult_type == play)
			{
				fprintf(f, "play\n");
			}
			else
			if (a[mas[i]].type.adult.adult_type == drama)
			{
				fprintf(f, "drama\n");
			}
			else
			if (a[mas[i]].type.adult.adult_type == comedy)
			{
				fprintf(f, "comedy\n");
			}
		}
		else
		if (a[mas[i]].ty == ms)
		{
			fprintf(f, "ms ");
			fprintf(f, "%s\n", a[mas[i]].type.musical.composer);
		}	
	}
	
	printf("\n\n\n\n\n\n");
}

int addsub(struct theatre* a, int* k, int* mas)
{
    //int i;
    //int t;
    int n = *k;
    printf("�������� �������� ������: ");
    scanf("%s", a[n].name);
    printf("������� �������� ���������: ");
    scanf("%s", a[n].play);
    printf("������� ��� ��������: ");
    scanf("%s", a[n].director);
    printf("������� ����������� ��������� ������:  ");
	scanf("%i", &a[n].min_cost);
    printf("������� ������������ ��������� ������: ");
	scanf("%i", &a[n].max_cost);
	
	char type_str[40];
	char sub_type_str[40];
	
	printf("������� ��� ���������  ������� / �������� / ������(child / adult / musical): ");
    scanf("%s", type_str);
    if ((strcmp(type_str, "child") == 0) || (strcmp(type_str, "adult") == 0) || (strcmp(type_str, "musical") == 0))
    {
		if (strcmp(type_str, "child") == 0)
		{
			a[n].ty = ch;
			
			printf("-- �������:\n");
			printf("������� �������: ");
			scanf("%i", &a[n].type.child.age);
			printf("������� ��� �������� ��������� ������ / ����� / ������ (fairytale / play / musical): ");
			scanf("%s", sub_type_str);
			
			if (strcmp(sub_type_str, "fairytale") == 0)
			{
				a[n].type.child.child_type = fairytale;
			}
			else
			if (strcmp(sub_type_str, "play") == 0)
			{
				a[n].type.child.child_type = ch_play;
			}
			else
			if (strcmp(sub_type_str, "musical") == 0)
			{
				a[n].type.child.child_type = musical;
			}
			else
			{
				printf("������! �������� ����\n");
				return -3;
			}
		}
		else
		if (strcmp(type_str, "adult") == 0)
		{
			a[n].ty = ad;
			
			printf("-- ��������:\n");
			printf("������� ��� ��������� ����� / ����� / ������� (play / drama / comedy): ");
			scanf("%s", sub_type_str);
			
			if (strcmp(sub_type_str, "play") == 0)
			{
				a[n].type.adult.adult_type = play;
			}
			else
			if (strcmp(sub_type_str, "drama") == 0)
			{
				a[n].type.adult.adult_type = drama;
			}
			else
			if (strcmp(sub_type_str, "comedy") == 0)
			{
				a[n].type.adult.adult_type = comedy;
			}
			else
			{
				printf("������! �������� ����\n");
				return -4;
			}
		}
		else
		if (strcmp(type_str, "musical") == 0)
		{
			a[n].ty = ms;
			
			printf("-- ������:\n");
			printf("������� ���  �����������: \n");
			scanf("%s", a[n].type.musical.composer);
		}
		else
			return -2;
    }
    else
    {
		printf("������! �������� ����\n");
		return -1;
    }
	
    a[n].numb = ++(*k);
    resetmas(mas, *k);
    printf("\n\n\n\n\n\n");
    return 0;
}
 
// ����� �����, �� ����� ��������� �� ����
int remsub(struct theatre* a, int* k, int* mas)
{
    int n;
    printf("������� ���������� ����� ���������, ������� �� ������ �������: ");
    scanf("%i", &n);
    for (int i=n-1; i < *k-1; i++)
        a[i] = a[i+1];
    (*k)--;
    resetmas(mas, *k);
    for (int i=0; i < *k; i++)
        a[i].numb = i+1;
    printf("\n\n\n\n\n\n");
    return 0;
}

int sorttab(struct theatre* a, int* k, unsigned long long* time1)
{
    unsigned long long te, tb;
    printf("���������� ������� �� ���� \"�������� ���������\" � ������� ����� ������� ������� ���������!");
    te = tick();
    for (int i=0; i < *k-1; i++)
        for (int j=i+1; j<*k; j++)
            if (strcmp(a[i].play, a[j].play)>0)
            {
                int numb = a[i].numb;
                struct theatre x = a[i];
                a[i] = a[j];
                a[j] = x;
                a[j].numb = a[i].numb;
                a[i].numb = numb;
            }
    tb = tick();
    *time1 = tb - te;
    printf("\n\n\n\n\n\n");
    return 0;
}

int shellssorttab(struct theatre* a, int N, unsigned long long* time3)
{
    unsigned long long te, tb;
    int i,j,k;
    int numb, numb_t;
    struct theatre t;
    te = tick();
    for(k = N/2; k > 0; k /=2)
    for(i = k; i < N; i++)
    {
        t = a[i];
        for (j = i; j>=k; j-=k)
        {
            if (strcmp(t.play, a[j-k].play)<0)
            {
                numb = a[j].numb;
                a[j] = a[j-k];
                a[j].numb = numb;
            }
            else
                break;
        }
        numb_t = a[j].numb;
        a[j] = t;
        a[j].numb = numb_t;
    }
    tb = tick();
    *time3 = tb - te;
    printf("\n\n\n\n\n\n");
    return 0;
}

int sorttabmas(struct theatre* a, int* k, int *mas, unsigned long long* time2)
{
    printf("���������� ������� �� ���� \"�������� ���������\" � ������� ��������������� ������� ������� ���������!");
    unsigned long long te, tb;
    te = tick();
    for (int i=0; i < *k-1; i++)
        for (int j=i+1; j<*k; j++)
            if (strcmp(a[mas[i]].play, a[mas[j]].play)>0)
            {
                int x = mas[i];
                mas[i] = mas[j];
                mas[j] = x;
            }
    tb = tick();
    *time2 = tb - te;
    printf("\n\n\n\n\n\n");
    return 0;
}

// Explain
int shellssorttabmas(struct theatre* a, int N, int *mas, unsigned long long* time4)
{
    unsigned long long te, tb;
    int i,j,k;
    int t;
    te = tick();
    for(k = N/2; k > 0; k /=2)
    for(i = k; i < N; i++)
    {
        t = mas[i];
        for (j = i; j>=k; j-=k)
        {
            if (strcmp(a[t].play, a[mas[j-k]].play)<0)
                mas[j] = mas[j-k];
            else
                break;
        }
        mas[j] = t;
    }
    tb = tick();
    *time4 = tb - te;
    printf("\n\n\n\n\n\n");
    return 0;
}

// Re:make
int findbirth(struct theatre* a, int* k)
{
    int y;
    printf("������� ������� ������: ");
    scanf("%i", &y);

    for (int i=0; i < *k; i++)
            if ((a[i].ty == ch) && (a[i].type.child.age == y))
            {
			        printf("     �������� ������   �������� ���������             �������    ����    �������|    ����������� �����\n");
					printf("                                                                 (���)  (����)   | �������, ���\n");
					printf("_______________________________________________________________________________________________________\n");
					
			
                printf("%20s ", a[i].name);
				printf("%20s ", a[i].play);
				printf("%20s ", a[i].director);
				
				printf("%7i %7i ", a[i].min_cost, a[i].max_cost);
				
				printf("ch ");
				printf("%3i ", a[i].type.child.age);
				
				if (a[i].type.child.child_type == fairytale)
				{
					printf("fairytale\n");
				}
				else
				if (a[i].type.child.child_type == ch_play)
				{
					printf("ch_play\n");
				}
				else
				if (a[i].type.child.child_type == musical)
				{
					printf("musical\n");
				}
            }
	
    printf("\n\n\n\n\n\n");
    return 0;
}

int main(int argc, char* argv[])
{
	FILE* f;
    int c = 1;
    //int t;
    int k = 0;
    unsigned long long time1=0, time2=0, time3 = 0, time4 = 0;
    struct theatre a[100];
    int mas[100];
    setlocale(0, "russian");

	if (argc < 3)
	{
		if (argc == 1)
		{
			f = fopen("test.txt", "r");
			
			if (!f)
			{
				printf("������! ���������� �������� ���� test.txt\n");
				return -1;
			}
		}
		else
		{
			f = fopen(argv[1], "r");
			
			if (!f)
			{
				printf("������! ���������� �������� ���� %s\n", argv[1]);
				return -2;
			}
		}
		
		fillbeg(f, a, &k);
		resetmas(mas, k);
		printf("������ ��������� ��������� ������ � ����������� �������. \n");
		
		while(c)
		{
			printf("�������� �����, �������������� ����������� ��������:");
			printf("\n1 - ������� �������");
			printf("\n2 - ������� ������� �� ������� ������");
			printf("\n3 - �������� ���������(������������� ������������ ������ ������)");
			printf("\n4 - �������  ���������(����������)");
			printf("\n5 - ������������� ������� �� �������� ��������� ���������");
			printf("\n6 - ������������� ������� �� �������� ��������� � ������� ������� ������ ���������");
			printf("\n7 - ������������� ������� �� �������� ��������� ������");
			printf("\n8 - ������������� ������� �� �������� ��������� � ������� ������� ������ ������");
			printf("\n9 - ����� ��� ��������� ��� ����� ��������� ��������.");
			printf("\n10 - ����� ������� ������ � ���������");
			//printf("\n11 - ��������� ������� � ����");
			printf("\n0 - ����� �� ���������");
			
			printf("\n\n> ");
			
			if (scanf("%i", &c) == 1)
			{
				if (c == 0)
				{
					break;
					// 0;
				}
				else
				if (c == 1)
				{
					printf("     �������� ������   �������� ���������             �������    ����    �������|    ����������� �����\n");
					printf("                                                                 (���)  (����)   |\n");
					printf("_______________________________________________________________________________________________________\n");
					write_f_table(stdout, a, &k);
				}
				else
				if (c == 2)
				{
				    printf("     �������� ������   �������� ���������             �������    ����    �������|    ����������� �����\n");
					printf("                                                                 (���)  (����)   |\n");
					printf("_______________________________________________________________________________________________________\n");
					write_key_table(stdout, a, &k, mas);
				}
				else
				if (c == 3)
					addsub(a, &k, mas);
				else
				if (c == 4)
					remsub(a, &k, mas);
				else
				if (c == 5)
					sorttab(a, &k, &time1);
				else
				if (c == 6)
					sorttabmas(a, &k, mas, &time2);
				else
				if (c == 7)
					shellssorttab(a, k, &time3);
				else
				if (c == 8)
					shellssorttabmas(a, k, mas, &time4);
				else
				if (c == 9)
				{
					
					findbirth(a, &k);
				}
				else
				if (c == 10)
					resetmas(mas, k);
				//else
				//if (c == 11)
				//	{}//resetmas(mas, k);
				else
				{
					printf("��������! ����� �������� ���. ���������� ��������� ����\n");
				}
			}
			else
			{
				printf("������! �������� ����\n");
				return -3;
			}
		}
		
		printf("\n\n����� �� ���������� ����� ������� ���������: %llu", time1);
		printf("\n����� �� ���������� ������� c ������� ������� ������ ���������: %llu", time2);
		printf("\n\n����� �� ���������� ����� ������� ������: %llu", time3);
		printf("\n����� �� ���������� ������� c ������� ������� ������ ������: %llu", time4);
		printf("\n������ ������������ �������: %i", sizeof(mas));
		printf("\n������ ����� ���������: %i", sizeof(a));
		fclose(f);
	}
	else
		printf("-- ������:\n    main.exe\n      ���\n    main.exe [source_file_name.txt]\n");
	
	return 0;
}