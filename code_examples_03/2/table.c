#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    int numb;
    char surname[20];
    char name[20];
    char phone[20];
    int det;
    union
    {
        struct
        {
            int day;
            int month;
            int year;
        } pers;
        struct
        {
            char occup[20];
            char organ[20];
        } serv;
    } un;
} sub;

// подсчёт времени
unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

// Сброс массива ключей
int resetmas(int* mas, int k)
{
    for (int i=0; i < k; i++)
        mas[i] = i;
    printf("\n\n\n\n\n\n");
    return 0;
}

// Начальное заполнение таблицы из файла
int fillbeg(FILE*f, sub* a, int* k)
{
    char ch;
    rewind(f);
    ch = fgetc(f);
    while (ch != EOF)
    {
        ungetc(ch,f);
        a[*k].numb = (*k) + 1;
        fscanf(f, "%s", a[*k].surname);
        fscanf(f, "%s", a[*k].name);
        fscanf(f, "%s", a[*k].phone);
        fscanf(f, "%i", &a[*k].det);
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
        ch = fgetc(f);
        (*k)++;
    }
    return 0;
}

// Печать таблицы
int printtable(sub* a, int* k)
{
    for (int i = 0; i < *k; i++)
    {
        if (a[i].det)
            printf("\n#%i   %11s   %11s   %11s   %i.%i.%i",
                   a[i].numb, a[i].surname, a[i].name,
                   a[i].phone, a[i].un.pers.day,
                   a[i].un.pers.month, a[i].un.pers.year);
        else
            printf("\n#%i   %11s   %11s   %11s           %11s   %8s",
                   a[i].numb, a[i].surname, a[i].name,
                   a[i].phone, a[i].un.serv.occup,
                   a[i].un.serv.organ);
    }
    printf("\n\n\n\n\n\n");
    return 0;
}

// Печать таблицы по массиву ключей
int printtablemas(sub* a, int k, int* mas)
{
    for (int i = 0; i < k; i++)
    {
        if (a[mas[i]].det)
            printf("\n#%i   %11s   %11s   %11s   %i.%i.%i",
                   a[mas[i]].numb, a[mas[i]].surname, a[mas[i]].name,
                   a[mas[i]].phone, a[mas[i]].un.pers.day,
                   a[mas[i]].un.pers.month, a[mas[i]].un.pers.year);
        else
            printf("\n#%i   %11s   %11s   %11s           %11s   %8s",
                   a[mas[i]].numb, a[mas[i]].surname, a[mas[i]].name,
                   a[mas[i]].phone, a[mas[i]].un.serv.occup,
                   a[mas[i]].un.serv.organ);
    }
    printf("\n\n\n\n\n\n");
    return 0;
}

// Добавление абонента
int addsub(sub* a, int* k, int* mas)
{
    int i;
    int t;
    int n = *k;
    printf("Ввведите фамилию абонента: ");
    scanf("%s", a[n].surname);
    printf("Введите имя абонента: ");
    scanf("%s", a[n].name);
    printf("Введите телефон абонента: ");
    scanf("%s", a[n].phone);
    printf("Введите 1, если данный контакт является личным");
    printf("(в противном случае он будет считаться служебным контактом): ");
    t = scanf("%i", &i);
    if ((i != 1) || (t == 0))
    {
        a[n].det = 0;
        printf("Введите должность: ");
        scanf("%s", a[n].un.serv.occup);
        printf("Введите организацию: ");
        scanf("%s", a[n].un.serv.organ);
    }
    else
    {
        a[n].det = 1;
        printf("Введите год, в котором родился абонент: ");
        scanf("%i", &a[n].un.pers.year);
        printf("Введите месяц, в котором родился абонент: ");
        scanf("%i", &a[n].un.pers.month);
        printf("Введите число месяца, в котором родился абонент: ");
        scanf("%i", &a[n].un.pers.day);
    }
    a[n].numb = ++(*k);
    resetmas(mas, *k);
    printf("\n\n\n\n\n\n");
    return 0;
}

int remsub(sub* a, int* k, int* mas)
{
    int n;
    printf("Введите порядковый номер абонента, которого вы хотите удалить: ");
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

int sorttab(sub* a, int* k, unsigned long long* time1)
{
    unsigned long long te, tb;
    printf("Сортировка таблицы по полю \"Фамилия\" с помощью самой таблицы успешно завершена!");
    te = tick();
    for (int i=0; i < *k-1; i++)
        for (int j=i+1; j<*k; j++)
            if (strcmp(a[i].surname,a[j].surname)>0)
            {
                int numb = a[i].numb;
                sub x = a[i];
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

int shellssorttab(sub* a, int N, unsigned long long* time3)
{
    unsigned long long te, tb;
    int i,j,k;
    int numb, numb_t;
    sub t;
    te = tick();
    for(k = N/2; k > 0; k /=2)
    for(i = k; i < N; i++)
    {
        t = a[i];
        for (j = i; j>=k; j-=k)
        {
            if (strcmp(t.surname, a[j-k].surname)<0)
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

int sorttabmas(sub* a, int* k, int *mas, unsigned long long* time2)
{
    printf("Сортировка таблицы по полю \"Фамилия\" с помощью дополнительного массива успешно завершена!");
    unsigned long long te, tb;
    te = tick();
    for (int i=0; i < *k-1; i++)
        for (int j=i+1; j<*k; j++)
            if (strcmp(a[mas[i]].surname,a[mas[j]].surname)>0)
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

int shellssorttabmas(sub* a, int N, int *mas, unsigned long long* time4)
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
            if (strcmp(a[t].surname, a[mas[j-k]].surname)<0)
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

int findbirth(sub* a, int* k)
{
    int month, day;
    printf("Введите текущий месяц: ");
    scanf("%i", &month);
    printf("Введите сегодняшнее число: ");
    scanf("%i", &day);
    printf("\nЛюди, которых вам нужно поздравить в течение 7 дней в этом месяце:");
    for (int i=0; i < *k; i++)
        if (a[i].det)
        {
            if ((a[i].un.pers.month == month) && (a[i].un.pers.day - day <= 7) && (a[i].un.pers.day - day >= 0))
            {
                printf("\n#%i   %11s   %11s   %11s   %i.%i.%i",
                       a[i].numb, a[i].surname, a[i].name,
                       a[i].phone, a[i].un.pers.day,
                       a[i].un.pers.month, a[i].un.pers.year);
            }
        }
    printf("\n\n\n\n\n\n");
    return 0;
}

int main(void)
{
    FILE* f;
    int c = 1;
    int t;
    int k = 0;
    unsigned long long time1=0, time2=0, time3 = 0, time4 = 0;
    sub a[100];
    int mas[100];
    setlocale(0, "russian");
    f = fopen("test.txt", "r");
    fillbeg(f, a, &k);
    resetmas(mas, k);
    printf("Данная программа реализует работу со списком абонентов. \n");
    while (c != 0)
    {
        printf("Выберите число, соотвествующее необходимому вам действию:");
        printf("\n1 - вывести таблицу");
        printf("\n2 - вывести таблицу по массиву ключей");
        printf("\n3 - добавить абонента(дополнительно сбрасывается массив ключей)");
        printf("\n4 - удалить абонента (аналогично)");
        printf("\n5 - отсортировать таблицу абонентов по фамилии пузырьком");
        printf("\n6 - отсортировать таблицу абонентов по фамилии с помощью массива ключей пузырьком");
        printf("\n7 - отсортировать таблицу абонентов по фамилии Шеллом");
        printf("\n8 - отсортировать таблицу абонентов по фамилии с помощью массива ключей Шеллом");
        printf("\n9 - найти всех друзей, которых необоходимо поздравить с днём рождения на этой неделе.");
        printf("\n10 - сброс массива ключей к исходному");
		printf("\n11 - сохранить таблицу в файл");
        printf("\n0 - выход из программы");
        printf("\n\nМесто для ввода: ");

        t = scanf("%i", &c);
        if (t == 0)
        {
            c = 9;
        }
        if (c == 1)
            printtable(a, &k);
        if (c == 2)
            printtablemas(a, k, mas);
        if (c == 3)
            addsub(a, &k, mas);
        if (c == 4)
            remsub(a, &k, mas);
        if (c == 5)
            sorttab(a, &k, &time1);
        if (c == 6)
            sorttabmas(a, &k, mas, &time2);
        if (c == 7)
            shellssorttab(a, k, &time3);
        if (c == 8)
            shellssorttabmas(a, k, mas, &time4);
        if (c == 9)
            findbirth(a, &k);
        if (c == 10)
            resetmas(mas, k);
    }
    printf("\n\nВремя на сортировку самой таблицы пузырьком: %llu", time1);
    printf("\nВремя на сортировку таблицы c помощью массива ключей пузырьком: %llu", time2);
    printf("\n\nВремя на сортировку самой таблицы Шеллом: %llu", time3);
    printf("\nВремя на сортировку таблицы c помощью массива ключей Шеллом: %llu", time4);
    printf("\nРазмер добавленного массива: %i", sizeof(mas));
    printf("\nРазмер самой структуры: %i", sizeof(a));
    fclose(f);
    return 0;
}
