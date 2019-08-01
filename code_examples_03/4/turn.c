// Вариант №5 (26)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX 1
#define MMEMORY 200000
#define RAZM 20000
#define ABS 3000
#define NUMBZ 1000
#define VR1 2  // время прихода
#define VR2 1  // время обработки
#define PR 0.8

// подсчёт времени
unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

// структура очереди
struct node
{
    int k;
    struct node *next;
};

// добавить элемент в очередь (массив)
void push_mas(int val, int** First, int** Last, int* numb)
{
    **Last = val;
    (*Last)++;
    (*numb)++;
}

// вытащить элемент из очереди (массив)
int pop_mas(int** First, int** Last, int* numb)
{
    if (*numb != 0)
    {
         int val = **First;
         (*First)++;
         (*numb)--;
         return val;
    }
    return -1;
}

// добавить элемент в очередь
void push_list(int val, struct node** First, struct node** Last, int *numb, int* uaddr, int* kua)
{
    struct node *a = malloc(sizeof(struct node));
    a->k = val;
    a->next = NULL;
    if (*numb == 0)
        *Last = *First = a;
    else
    {
        (*Last)->next = a;
        *Last = a;
    }
    (*numb)++;
    (*kua)++;
    *(uaddr+*kua) = (int) a;
}

// вытащить элемент из очереди
int pop_list(struct node** First, struct node** Last, int *numb, int* faddr, int* kfa, int* uaddr, int* kua)
{
    if (numb == 0)
        return -1;
    struct node *a = *First;
    int val = a->k;
    *First = a->next;
    if (*First == NULL)
        *Last = NULL;
    (*numb)--;
    (*kfa)++;
    (*kua)--;
    for (int i=1; i <= *kua; i++)
        uaddr[i] = uaddr[i+1];
    *(faddr+*kfa) = (int) a;
    free(a);
    return val;
}

int main(void)
{
    setlocale(0,"russian");
    struct node* First = NULL;
    struct node* Last = NULL;
    int numb = 0;
    int mas[RAZM];
    int* FirstM=mas;
    int* LastM=mas;
    double ntime = 0.0;        // текущее время
    double r1time = -1;        // время для заявок, сгенерированных не в ОА
    double r2time = -1;        // время для заявок, сгенерированных во время ОА
    double pred=0;             // время прихода предыдущей заявки
    int znavt;                 // циклы, прошедшие для заявки в ОА
    int k_end=0;               // текущее число вышедших, обработанных заявок
    double nodone=0.0;         // время простоя
    int inels=0;               // число вошедших элементов
    int making=0;              // число срабатываний
    int faddr[MMEMORY];        // свободные адреса
    int kfa=-1;                // их количество
    int uaddr[MMEMORY];        // занятые адреса
    int kua=-1;                // их количество
    int det=0;
    int ltek=0;
    int kzn=0;
    int lobsh=0;
    int kout=100;
    unsigned long long te, tb, rr1=1, rr2=1;

    double summ1=0, summ2=0;
    int k1=0, k2=0;
    int olo1=0, olo2=0;

    srand(time(NULL));

    int sc=0;
    te = tick();
    for (sc = 0; sc < NUMBZ; sc++)
        push_list(0, &First, &Last, &numb, uaddr, &kua);
    for (sc = 0; sc < NUMBZ; sc++)
        pop_list(&First, &Last, &numb, faddr, &kfa, uaddr, &kua);
    tb = tick();
    printf("\n\nВремя для списка  (заполнение+освобождение): %llu", tb-te);

    te = tick();
    for (sc = 0; sc < NUMBZ; sc++)
        push_mas(0, &FirstM, &LastM, &numb);
    for (sc = 0; sc < NUMBZ; sc++)
        pop_mas(&FirstM, &LastM, &numb);
    tb = tick();
    printf("\nВремя для массива (заполнение+освобождение): %llu", tb-te);

    te  = tick();
    printf("\n\nРеализация списком: (АНАЛИЗ)\n");
	printf("______________________________________________________________\n");
	printf("Заявок обработано | тек. длина очереди | средн. длина очереди\n");
	printf("______________________________________________________________");
    while (k_end != NUMBZ)
    {
        if (k_end == kout)
        {
            printf("\n       %i        |", kout);
            printf("        %3i         |", ltek);
            printf("        %3i", lobsh / kzn);
            kout += 100;
        }
        if (numb == 0)
        {
            if (det == 0)
            {
                r1time = ((double) rand() / RAND_MAX)*VR1;
                //r1time = (double) (rand() % (VR1*ABS)) / ABS; // приход
                //printf("\n111 Время прихода следующей заявки: %f", r1time);
                summ1 += r1time;
                k1++;
                det = 1;
            }
            pred += r1time;
            if (ntime < pred)
            {
                nodone += pred - ntime;
                ntime = pred;
            }
            ++inels;
            push_list(0, &First, &Last, &numb, uaddr, &kua);
            det = 0;
            ++ltek;
            lobsh += ltek;
            ++kzn;

            olo1++;
        }
        znavt = pop_list(&First, &Last, &numb, faddr, &kfa, uaddr, &kua);
        --ltek;
        lobsh += ltek;
        ++kzn;

        if (det == 0)
        {
            r1time = ((double) rand() / RAND_MAX)*VR1;
            //r1time = (double) (rand() % (VR1*ABS)) / ABS; // приход
            //printf("\n222 Время прихода следующей заявки: %f", r1time);
            det = 1;
            summ1 += r1time;
            k1++;
        }
        r2time = ((double) rand() / RAND_MAX)*VR2;
        //r2time = (double) (rand() % (VR2*ABS)) / ABS; // обработка
        //printf("\n333 Время обработки: %f", r2time);
        summ2 += r2time;
        k2++;
        while (pred + r1time < ntime + r2time)  // <==============
        {
            //printf("\n444");
            //getchar();
            ++inels;
            push_list(0, &First, &Last, &numb, uaddr, &kua); // <===
            ++ltek;
            lobsh += ltek;
            ++kzn;

            pred += r1time;

            r1time = ((double) rand() / RAND_MAX)*VR1;
            //r1time = (double) (rand() % (VR1*ABS)) / ABS; // приход
            det = 1;
            //printf("\n555 Время прихода следующей заявки: %f", r1time);
            summ1 += r1time;
            k1++;
            olo2++;
        }
        ntime += r2time;
        ++znavt;
        if (((double) rand() / RAND_MAX) <= PR) ////////////////////////////////////////////////
		{
            push_list(znavt, &First, &Last, &numb, uaddr, &kua);
            ++ltek;
            lobsh += ltek;
            ++kzn;
            //printf("\n666");
        }
        else
            ++k_end;
        //printf("\n777 Текущее время: %f", ntime);
        //getchar();
        ++making;
    }
	printf("\n       %4i       |", kout);
    printf("        %3i         |", ltek);
	printf("        %3i", lobsh / kzn);
	printf("\n______________________________________________________________");
    tb = tick();
    rr1 = tb - te;
    printf("\n\n\nЧисло вошедших: %i", inels);
    printf("\nЧисло вышедших: %i\n", k_end);
    printf("\nЧисло срабатываний ОА: %i", making);
    printf("\nВремя простоя ОА: %f\n", nodone);
    printf("\nВремя моделирования: %f", ntime);
    printf("\nВремя работы программы: %llu\n", rr1);
    printf("\nСреднее время прихода: %f", summ1 / k1);
    printf("\nСреднее время обработки: %f\n", summ2 / k2);
    printf("\nЧисло пришедших при неработающем автомате: %i", olo1);
    printf("\nЧисло пришедших при работающем автомате: %i", olo2);
    getchar();

    printf("\n\n__________________________________________________________________________________________________\n\n\nРеализация массивом: (АНАЛИЗ)\n");
	printf("______________________________________________________________\n");
	printf("Заявок обработано | тек. длина очереди | средн. длина очереди\n");
	printf("______________________________________________________________");
    pred = 0.0;
    numb = 0;
    summ1 = 0.0;
    summ2 = 0.0;
    k1 = 0;
    k2 = 0;
    ntime = 0.0;
    r1time = -1;
    r2time = -1;
    k_end=0;
    nodone=0;
    inels=0;
    making=0;
    ltek=0;
    kzn=0;
    lobsh=0;
    kout=100;
    det = 0;
    olo1 = 0;
    olo2 = 0;
    tb = 0;
    te = 0;
    te = tick();
    while (k_end != NUMBZ)
    {
        if (k_end == kout)
        {
            printf("\n       %i        |", kout);
            printf("        %3i         |", ltek);
            printf("        %3i", lobsh / kzn);
            kout += 100;
        }
        if (numb == 0)
        {
            if (det == 0)
            {
                r1time = ((double) rand() / RAND_MAX)*VR1;
                //r1time = (double) (rand() % (VR1*ABS)) / ABS; // приход
                //printf("\n111 Время прихода следующей заявки: %f", r1time);
                summ1 += r1time;
                k1++;
                det = 1;
            }
            pred += r1time;
            if (ntime < pred)
            {
                nodone += pred - ntime;
                ntime = pred;
            }
            ++inels;
            push_mas(0, &FirstM, &LastM, &numb);
            det = 0;
            ++ltek;
            lobsh += ltek;
            ++kzn;

            olo1++;
        }
        znavt = pop_mas(&FirstM, &LastM, &numb);
        --ltek;
        lobsh += ltek;
        ++kzn;
		
		/*
		if (((double) rand() / RAND_MAX) <= 0.8) ////////////////////////////////////////////////
		{
			push_mas(znavt, &FirstM, &LastM, &numb);
            ++ltek;
            lobsh += ltek;
            ++kzn;
		}*/

        if (det == 0)
        {
            r1time = ((double) rand() / RAND_MAX)*VR1;
            //r1time = (double) (rand() % (VR1*ABS)) / ABS; // приход
            //printf("\n222 Время прихода следующей заявки: %f", r1time);
            det = 1;
            summ1 += r1time;
            k1++;
        }
        r2time = ((double) rand() / RAND_MAX)*VR2;
        //r2time = (double) (rand() % (VR2*ABS)) / ABS; // обработка
        //printf("\n333 Время обработки: %f", r2time);
        summ2 += r2time;
        k2++;
        while (pred + r1time < ntime + r2time)
        {
            //printf("\n444");
            //getchar();
            ++inels;
            push_mas(0, &FirstM, &LastM, &numb);
            ++ltek;
            lobsh += ltek;
            ++kzn;

            pred += r1time;

            r1time = ((double) rand() / RAND_MAX)*VR1;
            //r1time = (double) (rand() % (VR1*ABS)) / ABS; // приход
            det = 1;
            //printf("\n555 Время прихода следующей заявки: %f", r1time);
            summ1 += r1time;
            k1++;
            olo2++;
        }
        ntime += r2time;
        ++znavt;
        //if (znavt != MAX)
        if (((double) rand() / RAND_MAX) <= PR) ////////////////////////////////////////////////
		{
            push_mas(znavt, &FirstM, &LastM, &numb);
            ++ltek;
            lobsh += ltek;
            ++kzn;
            //printf("\n666");
        }
        else
            ++k_end;
        //printf("\n777 Текущее время: %f", ntime);
        //getchar();
        ++making;
    }
	printf("\n       %4i       |", kout);
	printf("        %3i         |", ltek);
    printf("        %3i", lobsh / kzn);
	printf("\n______________________________________________________________");
    tb = tick();
    rr2 = tb - te;
    printf("\n\n\nЧисло вошедших: %i", inels);
    printf("\nЧисло вышедших: %i\n", k_end);
    printf("\nЧисло срабатываний ОА: %i", making);
    printf("\nВремя простоя ОА: %f\n", nodone);
    printf("\nВремя моделирования: %f", ntime);
    printf("\nВремя работы программы: %llu\n", rr2);
    printf("\nСреднее время прихода: %f", summ1 / k1);
    printf("\nСреднее время обработки: %f\n", summ2 / k2);
    printf("\nЧисло пришедших при неработающем автомате: %i", olo1);
    printf("\nЧисло пришедших при работающем автомате: %i", olo2);

    printf("\n\nВремя для списка  (заполнение+моделирование+освобождение): %llu", rr1);
    printf("\nВремя для массива (заполнение+моделирование+освобождение): %llu", rr2);

    printf("\n\nВывести список свободных адресов? (1/0)  >");
    int omeg;
    scanf("%i", &omeg);
    if (omeg)
    {
        printf("\nАдреса свободной памяти:");
        for (sc = 0; sc < kfa+1; sc++)
		{
			if (sc % 8 == 0) printf("\n");
            printf("%p ", faddr[sc]);
			if (sc >= 399)
			{
				printf("\n  (...) \n");
				break;
			}
		}
		/*
        printf("\nАдреса занятой памяти:\n");
        for (sc = 0; sc < kua+1; sc++)
		{
            printf("%i ", uaddr[sc]);
		}
		*/
    }
    getchar();
    return 0;
}
