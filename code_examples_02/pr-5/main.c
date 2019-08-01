// Телепрограмма
/*
Канал
Время
Название передачи
*/

#include <stdio.h>

#include "unilist.h"

#define MAX_LEN

struct d_time
{
    int hours;   // от 0 до 23
    int minutes; // от 0 до 59
};

struct tv_program_line
{
    char channel[MAX_LEN];
    struct d_time time;
    char title[MAX_LEN];
};

int main()
{

    return 1;
}
