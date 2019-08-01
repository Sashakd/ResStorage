#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef struct
{
    char lastname[20];
    int number;

} key;

typedef struct // тип записи
{
    char lastname[20];
    enum {male, female} sex;
    int  growth;
    float average;
    enum {house, hostel} accm;
    union
    {
        struct
        {
            char street[26];
            int num_house;
            int num_flat;
        } house;
        struct
        {
            int num_host;
            int num_room;
        } hostel;
    } accom;
} student; // end of тип записи

#endif // STRUCTURES_H
