#include "changing.h"

int adding(student *table, int *count) // добавление записей
{
    int i = 0;
    int rc = 0;
    int n = 0;
    int err_insrt = 0;
    printf("Input count of records: ");
    err_insrt = fscanf(stdin, "%d", &n);
    if (err_insrt != 1 || n <= 0)
    {
        printf("Error. Bigger than 0 integer required.\n");
        return -1;
    }
    if (n + *count > N)
    {
        printf("Error. Overflow of maximum records count %d", N);
        return -2;
    }
    else
    {
        for (i = *count; i < n + *count; i++)
        {
            printf("Writing %d record\n", i);
            insrt_record(&table[i]);
        }
        *count = *count + n;
    }
    return rc;
} // end of добавление записей

int delete_record(student *table, int *count) // удаление записи
{
    int number;
    int i;
    if (*count == 0)
    {
        printf("Nothing to delete.\n");
        return -1;
    }
    printf("Input index number: ");
    fscanf(stdin, "%d", &number);
    if (number > *count)
    {
        printf("No such index number.\n");
        return -1;
    }
    for (i = number - 1; i < *count - 1; i++)
    {
        table[i] = table[i+1];
    }
    *count = *count - 1;
    return 0;
} // end of удаление записи
