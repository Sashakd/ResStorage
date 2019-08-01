#include "sorting.h"

int keys_create(student *table, key *list, int count) // функция создания массива ключей
{
    int i = 0;

    if (count <= 0)
    {
        printf("Nothing to create.\n");
        return -1;
    }
    for (i = 0; i < count; i++)
    {
        strcpy(list[i].lastname, table[i].lastname);
        list[i].number = i;
    }
    return 0;
} // end of функция создания массива ключей

int comp_student(student *arg1, student *arg2) // функция сравнения табличных элементов
{
    return strcmp(arg1->lastname, arg2->lastname);
} // end of функция сравнения табличных элементов

int comp_key(key *arg1, key *arg2) // функция сравнения элементов массива ключей
{
    return strcmp(arg1->lastname, arg2->lastname);
} // end of функция сравнения элементов массива ключей

void my_sort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *)) // функция сортировки модифицированным пузырьком
{
    int flag = 1;
    int i = 0;
    char *pbeg = base;
    char *pend = (char *)pbeg + size * (num);
    char *pa;
    void *temp = malloc(size);
    assert(num);
    while (flag)
    {
        flag = 0;
        if (i % 2 == 0)
        {
            pa = pend - size;
            for (;pa > pbeg; pa -= size)
                if (compare(pa, pa - size) < 0)
                {
                    flag = 1;
                    memmove(temp, pa - size, size);
                    memmove(pa - size, pa, size);
                    memmove(pa, temp, size);
                }
        }
        else
        {
            pa = pbeg;
            for (;pa < pend - size; pa += size)
                if (compare(pa, pa + size) > 0)
                {
                    flag = 1;
                    memmove(temp, pa + size, size);
                    memmove(pa + size, pa, size);
                    memmove(pa, temp, size);
                }
        }
        i++;
    }
    free(temp);
} // end of функция сортировки модифицированным пузырьком

int analyse_sorting(student *table, int count, char *name_file) // функция анализа эффективности сортировок
{
    int fd;
    int i;
    unsigned long long time_before = 0;
    unsigned long long time_after = 0;
    unsigned long long time = 0.0;
    double q_my = 100;
    double keys = 100;
    key *mas;

    mas = malloc(count * sizeof(key));
    if (count == 0)
    {
        printf("Nothing to sort\n");
        return -1;
    }
    fd = open(name_file, O_RDONLY, S_IREAD|S_IWRITE);
    i = 1;
    while (!eof(fd))
    {
        read(fd, &table[i - 1], sizeof(student));
        i++;
    }
    __asm__ __volatile__ ("rdtsc" : "=A" (time_before) );
    my_sort(table, count, sizeof(student),(int(*) (const void *, const void *)) comp_student);
    __asm__ __volatile__ ("rdtsc" : "=A" (time_after) );
    time = time_after - time_before;
    q_my = time;
    printf("\nBubble modified sort without keys: %d\n", time);
    lseek(fd, 0L, SEEK_SET);
    i = 1;
    while (!eof(fd))
    {
        read(fd, &table[i - 1], sizeof(student));
        i++;
    }
    __asm__ __volatile__ ("rdtsc" : "=A" (time_before) );
    keys_create(table, mas, count);
    my_sort(mas, count, sizeof(key),(int(*) (const void *, const void *)) comp_key);
    __asm__ __volatile__ ("rdtsc" : "=A" (time_after) );
    time = time_after - time_before;
    keys = (q_my - time) / q_my * 100;
    printf("Bubble modified sort with keys: %d\n", time);
    lseek(fd, 0L, SEEK_SET);
    i = 1;
    while (!eof(fd))
    {
        read(fd, &table[i - 1], sizeof(student));
        i++;
    }
    __asm__ __volatile__ ("rdtsc" : "=A" (time_before) );
    qsort(table, count, sizeof(student),(int(*) (const void *, const void *)) comp_student);
    __asm__ __volatile__ ("rdtsc" : "=A" (time_after) );
    time = time_after - time_before;
    q_my = (q_my - time) / q_my * 100;
    printf("Quick sort without keys: %d\n", time);
    lseek(fd, 0L, SEEK_SET);
    i = 1;
    while (!eof(fd))
    {
        read(fd, &table[i - 1], sizeof(student));
        i++;
    }
    __asm__ __volatile__ ("rdtsc" : "=A" (time_before) );
    keys_create(table, mas, count);
    qsort(mas, count, sizeof(key),(int(*) (const void *, const void *)) comp_key);
    __asm__ __volatile__ ("rdtsc" : "=A" (time_after) );
    time = time_after - time_before;
    printf("Quick sort with keys: %d\n\n", time);
    printf("Efficiency of keys = %0.2f%\n", keys);
    printf("Efficiency of sorting = %0.2f%\n\n", q_my);
    close(fd);
    return 0;
} // end of функция анализа эффективности сортировок

int prnt_sort_keys(student *table, key *mas, int count) // создание, сортировка и печать массива ключей
{
    int i = 0;
    if (keys_create(table, mas, count) == 0)
    {
        qsort(mas, count, sizeof(key),(int(*) (const void *, const void *)) comp_key);
        printf("\nNum|Lastname            |\n");
        printf("---|--------------------|\n");
        for(i = 0; i < count; i++)
        {
            printf("%3d|%20s|\n", mas[i].number + 1, mas[i].lastname);
            printf("---|--------------------|\n");
        }
    }
    return 0;
} // end of создание, сортировка и печать массива ключей
