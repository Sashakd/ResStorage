#ifndef BNUMB_H
#define BNUMB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 80

struct big_numb
{
    char sign_m;    // Знак мантисы
    char mant[30];  // Мантиса
	char m_len;     // Длина мантисы
	char dot_pos;   // Положение точки
	int e;          // Порядок
};

int full_check_big_numb(const char* str, int* pse, int* psm, int* pp, int* pe, int* len);

struct big_numb* get_big_numb(FILE* f);

void print_mantis(char* m, char d, char len);

void print_big_numb(struct big_numb number);

void print_i_big_numb(struct big_numb number);

int check_big_i_numb(const char* str, int* len);

struct big_numb* get_i_big_numb(FILE* f);

#endif  // BNUMB_H