#include "read.h"

int print_record(student tmp) // печать одной записи на экран
{
    int i = 0;
    int flag = 0;
    for (i = 0; i < 20; i++)
    {
        if (!flag)
        {
            if (tmp.lastname[i] == '\0')
                flag = 1;
            else
                printf("%c", tmp.lastname[i]);
        }
        else
            printf(" ");
    }
    printf("|");
    if (tmp.sex == male)
        printf("male  |");
    else
        printf("female|");
    printf("%3d|", tmp.growth);
    printf("%0.2f|", tmp.average);
    if (tmp.accm == house)
    {
        printf("house |");
        flag = 0;
        for (i = 0; i < 26; i++)
        {
            if (!flag)
            {
                if (tmp.accom.house.street[i] == '\0')
                    flag = 1;
                else
                    printf("%c", tmp.accom.house.street[i]);
            }
            else
                printf(" ");
        }
        printf("|");
        printf("%3d|", tmp.accom.house.num_house);
        printf("%3d", tmp.accom.house.num_flat);
    }
    else
    {
        printf("hostel|");
        printf("#########################|");
        printf("%3d|", tmp.accom.hostel.num_host);
        printf("%3d", tmp.accom.hostel.num_room);
    }
    return 0;
} // end of печать одной записи на экран

int insrt_record(student *tmp) // процедура ввода полей записи
{
    char sex[7];
    char accomodation[7];
    printf("Input lastname: ");
    scanf("%s", tmp->lastname);
    printf("Input sex (male or female): ");
    scanf("%s", sex);
    if (strcmp(sex, "male") == 0)
        tmp->sex = male;
    else
        tmp->sex = female;
    printf("Input growth ( 140 < growth < 200): ");
    scanf("%d", &tmp->growth);
    printf("Input average score of exams: ");
    scanf("%f", &tmp->average);
    printf("Input type of accomodation (house or hostel): ");
    scanf("%s", accomodation);
    if (strcmp(accomodation, "house") == 0)
    {
        tmp->accm = house;
        printf("Input street name: ");
        fscanf(stdin, "%s", tmp->accom.house.street);
        printf("Input house number: ");
        scanf("%d", &tmp->accom.house.num_house);
        printf("Input flat number: ");
        scanf("%d", &tmp->accom.house.num_flat);
    }
    else
    {
        tmp->accm = hostel;
        printf("Input hostel number: ");
        scanf("%d", &tmp->accom.hostel.num_host);
        printf("Input room number: ");
        scanf("%d", &tmp->accom.hostel.num_room);
    }
    return 0;
} // end of процедура ввода полей записи

int reading(student *table, int *count, char **name) // процедура чтения записей из файла
{
    int fd;
    int i = 0;
    char name_file[20];
    student tmp;
    printf("\nInput name of file: ");
    fscanf(stdin, "%s", name_file);
    fd = open(name_file, O_RDONLY, S_IREAD|S_IWRITE);
    if (fd == -1)
    {
        printf("File is not exist.\n");
    }
    strcpy(*name, name_file);
    while (!eof(fd))
    {
        read(fd, &tmp, sizeof(student));
        i++;
    }
    if (i > N)
    {
        printf("Too many records.");
        goto fin;
    }
    else
    {
        *count = i;
        lseek(fd, 0L, SEEK_SET);
        i = 1;
        while (!eof(fd))
        {
            read(fd, &table[i - 1], sizeof(student));
            i++;
        }
    }
    fin:
    close(fd);
    return 0;
} // end of процедура чтения записей из файла

int print_all(student *table, int count) // печать всех записей на экран
{
    int i;
    if (count == 0)
    {
        printf("No records loaded.\n");
        return - 1;
    }
    printf("\nNum|Lastname           |Sex   |Grw|Avrg|Accom |Street                   |H/H|F/R");
    printf("---|-------------------|------|---|----|------|-------------------------|---|---");
    for (i = 0; i < count; i++)
    {
        printf("%3d|", i + 1);
        print_record(table[i]);
        printf("---|-------------------|------|---|----|------|-------------------------|---|---");
    }
    return 0;
} // end of печать всех записей на экран

int save_file(student *table, int count) // сохранение информации в файл
{
    int fd;
    int i;
    char name_file[20];
    if (count == 0)
    {
        printf("Nothing to save.\n");
        return -1;
    }
    printf("Input name of file to save in: ");
    fscanf(stdin, "%s", name_file);
    fd = open(name_file, O_CREAT|O_EXCL|O_TRUNC|O_WRONLY, S_IREAD|S_IWRITE);
    if (fd == -1)
        fd = open(name_file, O_TRUNC|O_WRONLY, S_IREAD|S_IWRITE);
    for (i = 0; i < count; i++)
    {
        write(fd, &table[i], sizeof(student));
    }
    close(fd);
    return 0;
} // сохранение информации в файл

int print_hostel(student *table, int count) // вывод студентов, живущих в общежитии
{
    int i = 0;
    int flag = 0;
    if (count == 0)
    {
        printf("Nothing to print.\n");
        return -1;
    }
    printf("\nNum|Lastname           |Sex   |Grw|Avrg|Accom |Street                   |H/H|F/R");
    printf("---|-------------------|------|---|----|------|-------------------------|---|---");
    for (i = 0; i < count; i++)
    {
        if (table[i].accm == hostel)
        {
            printf("%3d|", i);
            print_record(table[i]);
            printf("---|-------------------|------|---|----|------|-------------------------|---|---");
            flag = 1;
        }
    }
    if (flag == 0)
        printf("No such students in table.\n");
    return 0;
} // end of вывод студентов, живущих в общежитии
