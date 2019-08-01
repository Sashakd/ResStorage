/*
Вариант 25 (10)

Задана система двусторонних дорог.
Определить, можно ли, построив еще три новые дороги,
из заданного города добраться до каждого из остальных
городов, проезжая расстояние не более Т единиц.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <windows.h>

#define INF (INT_MAX - 1000)

/*
A B 2
A C 3
C B 7
C E 1
E D 2
E Q 5
D L 3
L B 1
A D 1
A L 2
*/

// дублирование строк
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

void free_matrix(int **data, const int n)
{
    for (int i = 0; i < n; i++)
       free(data[i]);

    free(data);
}

int** allocate_matrix(const int n, const int m)
{
    int **data = calloc(n, sizeof(int*));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof(int));
        if (!data[i])
        {
            free_matrix(data, n);
            return NULL;
        }
    }
    return data;
}

int farnum(char* str, char** name, int k)  // Находит слово в списке первых k слов
{
    int i, num=-1;
    for (i=0; i<k; i++)
        if (name[i] != NULL && strcmp(name[i], str) == 0)
            num = i;
    return num;
}

int minnu(int* u, int* d, int k)
{
    int min=0;
    for (int i=0; i<k; i++)
        if (u[i] == 0 && (d[min]>d[i] || u[min] == 1))
            min = i;
    return min;
}

int minmatr(int x, int y)
{
    if (x >= 0 && y >= 0 && x <= y)
        return 1;
    if (x >= 0 && y >= 0 && x > y)
        return -1;
    if (x >= 0 && y < 0)
        return 1;
    if (x < 0 && y >= 0)
        return -1;
    return 0;
}

int inwayu(int i, int j, int **matway, int num, int k)
{
    int z;
    for (z=0; z<k-1; z++)
    {
        if (matway[num][z] == i && matway[num][z+1] == j)
            return 1;
        if (matway[num][z] == j && matway[num][z+1] == i)
            return 1;
        if (matway[num][z] == -i && matway[num][z+1] == j)
            return 1;
        if (matway[num][z] == -j && matway[num][z+1] == i)
            return 1;
    }
    return 0;
}

int inwayr(int i, int j, int **matway, int num, int k)
{
    int z;
    for (z=0; z<k-1; z++)
    {
        if (matway[num][z] == i && matway[num][z+1] == -j)
            return 1;
        if (matway[num][z] == j && matway[num][z+1] == -i)
            return 1;
        if (matway[num][z] == -i && matway[num][z+1] == -j)
            return 1;
        if (matway[num][z] == -j && matway[num][z+1] == -i)
            return 1;
    }
    return 0;
}

// Распечатка в файл
void print_into(FILE* f, char **name, int *mk, int num2, int **matu, int **matway, int k)
{
	int i, j;

	f = fopen("1.gv", "w");
	
	fprintf(f, "graph towns {\n");
	
	for (j=1; j<mk[num2]-1; j++)
        if ((matway[num2][j] > 0 && matway[num2][j+1] < 0) || (matway[num2][j] < 0 && matway[num2][j+1] > 0))
            fprintf(f, "%s [color=red];\n", name[abs(matway[num2][j])]);
	
    for (i=0; i<k; i++)
    {
        for (j=i+1; j<k; j++)
        {
            if (matu[i][j] > 0)
            {
                if (inwayu(i, j, matway, num2, mk[num2]))
				{
                    fprintf(f, "%s -- %s [color=blue, style=bold, label=\"%i\"];\n", name[i], name[j], matu[i][j]);
					fprintf(stdout, "%s -- %s [color=blue, style=bold, label=\"%i\"];\n", name[i], name[j], matu[i][j]);
				}
                else
				{
                    fprintf(f, "%s -- %s [color=blue, style=dotted, label=\"%i\"];\n", name[i], name[j], matu[i][j]);
					fprintf(stdout, "%s -- %s [color=blue, style=dotted, label=\"%i\"];\n", name[i], name[j], matu[i][j]);
				}
            }
			/*
            if (matr[i][j] > 0)
            {
			
                if (inwayr(i, j, matway, num2, mk[num2]))
                    fprintf(f, "%s -- %s [color=green, style=bold, label=\"%i\"];\n", name[i], name[j], matr[i][j]);
                else
                    fprintf(f, "%s -- %s [color=green, style=dotted, label=\"%i\"];\n", name[i], name[j], matr[i][j]);
            }
			*/
        }
    }
    fprintf(f,"}");	
	
	fclose(f);
}

int main(int argc, char* argv[])
{
    FILE *f;
    char **name;
    char str[100];
    int **matu;
	//int	**matr;
	int **matway;
    int *mk;
    int n, k=0, k1=0;
    int num, num1, num2;
    int *d, *u;
    int i, j;
    int det = 1;
	
    setlocale(0, "russian");
	
    n = 100;
	
    d = malloc(n*sizeof(int));
    u = malloc(n*sizeof(int));
	
    matu = allocate_matrix(n, n);
    //matr = allocate_matrix(n, n);
    matway = allocate_matrix(n, n);
	
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            matu[i][j] = -1;
            //matr[i][j] = -1;
            matway[i][j] = 0;
        }
	
    mk = malloc(n*sizeof(int));
    name = malloc(n*sizeof(char*));
	
    for (i=0; i<n; i++)
    {
        name[n] = NULL;
        mk[i] = 0;
    }
	
    f = fopen("1.gv", "w");

	if (argc == 1)
	{
		printf("  Формат ввода связи между городами: \n\"ГородВыезда ГородВъезда РасстояниеПоДороге\"\n");
		printf("\n Введенное отрицательное расстояние означает отсутствие пути. Если связь между городами уже была ранее введена, ");
		printf("то произойдёт замена старой информации.         Для окончания ввода введите строку, начинающуюся 00. \n\n");
		while (det)
		{
			scanf("%s", str);
			if (str[0] == '0' && str[1] == '0')
				break;
			num1 = farnum(str, name, k);
			if (num1 == -1)
			{
				name[k] = strdup(str);
				num1 = k;
				k++;
			}
			scanf("%s", str);
			num2 = farnum(str, name, k);
			if (num2 == -1)
			{
				name[k] = strdup(str);
				num2 = k;
				k++;
			}
			scanf("%i", &(matu[num1][num2]));
			matu[num2][num1] = matu[num1][num2];
			//scanf("%i", &(matr[num1][num2]));
			//matr[num2][num1] = matr[num1][num2];
		}
		printf("\n");
	}
	else
	{
		if (argc == 2)
		{
			FILE* rd = fopen(argv[1], "r");
			
			if (rd)
			{
				while (det)
				{
					fscanf(rd, "%s", str);
					if (str[0] == '0' && str[1] == '0')
						break;
					num1 = farnum(str, name, k);
					if (num1 == -1)
					{
						name[k] = strdup(str);
						num1 = k;
						k++;
					}
					fscanf(rd, "%s", str);
					num2 = farnum(str, name, k);
					if (num2 == -1)
					{
						name[k] = strdup(str);
						num2 = k;
						k++;
					}
					fscanf(rd, "%i", &(matu[num1][num2]));
					matu[num2][num1] = matu[num1][num2];
					//scanf("%i", &(matr[num1][num2]));
					//matr[num2][num1] = matr[num1][num2];
				}
				printf("\n");
			}
			else
			{
				free(d);
				free(u);
				free_matrix(matu, n);
				//free_matrix(matr, n);
				free_matrix(matway, n);
				for (i=0; i<n; i++)
					free(name[n]);
				free(name);
			
				printf("ERROR! Could not open file %s\n", argv[1]);
			
				return -2;
			}
		}
		else
		{
			free(d);
			free(u);
			free_matrix(matu, n);
			//free_matrix(matr, n);
			free_matrix(matway, n);
			for (i=0; i<n; i++)
				free(name[n]);
			free(name);
			
			printf("ERROR! Too many parameters\n");
			
			return -1;
		}
	}
	
	print_into(f, name, mk, num2, matu, matway, k);
	
	fclose(f);
	system("dot.exe 1.gv -Tpng -o 1.png");
	system("1.png");
	
	/*
	fclose(f);
	
	system("del 1.png");
	system("dot.exe 1.gv -Tpng -o 1.png");
	system("1.png");
	*/
	
	//////////////////////////////////////// 
	printf("\n-- Строительство трёх новых дорог --\n");
    while (det)
    {
        printf("\nВведите назание начального города: ");
        scanf("%s", str);
        num1 = farnum(str, name, k);
        if (num1 == -1)
            printf("Такого города нет!");
        else
            det = 0;
    }
	/*
	for (int tss = 0; tss < 3; tss++) ///////////////////////////////
	{
		printf("\n(Дорог осталось: %d)\n", 3 - tss);
		det = 1;
		while (det)
		{
			printf("\nВведите назание конечного города: ");
			scanf("%s", str);
			num2 = farnum(str, name, k);
			if (num2 == -1)
				printf("Такого города нет!");
			else
				det = 0;
		}
		
		//int pro = 0;
		
		printf("Задайте длину новой дороги: ");
		if (scanf("%d", &matu[num1][num2]) == 1)
		{
			//matu[num1][num2] = pro;
			matu[num2][num1] = matu[num1][num2];
		}
		else
		{
			free(d);
			free(u);
			free_matrix(matu, n);
			//free_matrix(matr, n);
			free_matrix(matway, n);
			for (i=0; i<n; i++)
				free(name[n]);
			free(name);
			
			printf("ERROR! Wrong value\n");
			
			return -3;
		}
	} //////////////////////////////////////////////
	
	*/
	
	int T = 0;
	printf("\n-- Задайте максимально допустимое расстояние для достижения каждого из городов --\n");
	printf("Задайте расстояние: ");
	if (!scanf("%d", &T) == 1)
	{
		free(d);
			free(u);
			free_matrix(matu, n);
			//free_matrix(matr, n);
			free_matrix(matway, n);
			for (i=0; i<n; i++)
				free(name[n]);
			free(name);
			
			printf("ERROR! Wrong value\n");
			
			return -4;
	}

	//////////////////////////////////////////////////////
	int qvest = 1;
	int skip_factor = 0;
	
    // алгоритм Дейкстры
	for (int hiss = 0; hiss < k; hiss++)
	{
		if (hiss != num1)
		{
			d[num1] = 0;  // Д -- номера
			mk[num1] = 1;
			matway[num1][0] = num1; // матрица кратчайших расстояний где num1 -- начальная вершина
			for (i=0; i<k; i++)
			{
				if (i != num1)  d[i] = INF; // <=== подобие INF
				u[i] = 0;
			}
			k1 = 0;
			while (k1 != k)
			{
				num = minnu(u, d, k);
				u[num] = 1;
				k1++;
				for (i=0; i<k; i++)
				{
					if (u[num] && matu[num][i] > 0 && d[i] > d[num] + matu[num][i]) // minmatr(matu[num][i], matr[num][i]) > 0
					{
						d[i] = d[num] + matu[num][i];
						mk[i] = mk[num]+1;
						for (j=0; j<mk[num]; j++)
							matway[i][j] = matway[num][j];
						matway[i][mk[i]-1] = i;
					}
					/*
					if (matu[num][i] < 0 && d[i] > d[num] + matr[num][i])
					{
						d[i] = d[num] + matr[num][i];
						mk[i] = mk[num]+1;
						for (j=0; j<mk[num]; j++)
							matway[i][j] = matway[num][j];
						matway[i][mk[i]-1] = -i;
					}
					*/
				}
			}
			//////////////////////////////////////////////////////
			
			// для первой строки
			if (d[hiss] != INF)
				printf("Успешно завершено! Длина пути: %i  (из %s в %s)\n", d[hiss], name[num1], name[hiss]);
			else
				printf("Такого пути нет!\n");
				
			if (d[hiss] > T)
			{
				/////////////////////////////////////////////
				if (matu[num1][hiss] > 0) qvest = 0;
				
				skip_factor++;
				d[hiss] = 1; // <--- Верно
				
				//mk[hiss] = 1;
				
				//mk[num1] = mk[hiss]+1;
				
				matu[num1][hiss] = 1;
				matu[hiss][num1] = 1;
				matway[num1][hiss] = 1;
				matway[hiss][num1] = 1;
				
				/////////////////////////////////////////////
				
				
				//
				
				if (skip_factor > 3)  qvest = 0;
			}
		}
		else
			printf("skip\n");
	}
	
	printf("Возможно ли пройти из города %s в остальные города за расстояние не более %d? Ответ:", name[num1], T);  // name + num1
	if (qvest)
	{
		printf(" ДА\n");
		/*
		f = fopen("2.gv", "w"); // <=============
		rewind(f);
		
		print_into(f, name, mk, num2, matu, matway, k);
		
		fclose(f);
		system("dot.exe 1.gv -Tpng -o 2.png");
		system("2.png");
		*/
	}
	else
		printf(" НЕТ\n");
	
	/*
	for (i=0; i<k; i++)
	{
		if (i != num1)
		{
			if (matway[1][i] != INF)
				printf("Успешно завершено! Длина пути: %i\n", d[num2]);
			else
				printf("Такого пути нет!\n");
		}
		else
		{
			printf("Пропуск (Петель быть не должно)\n");
		}
	}
	*/
	
	/*	
	fclose(f);
	//system("del 1.png");
	system("dot.exe 1.gv -Tpng -o 1.png");
	system("1.png");
	*/
    //fclose(f);
    free(d);
    free(u);
    free_matrix(matu, n);
    //free_matrix(matr, n);
    free_matrix(matway, n);
    for (i=0; i<n; i++)
        free(name[n]);
    free(name);
    getchar();
    getchar();
    return 0;
}
