#ifndef __IO_HUGE__H__

#define __IO_HUGE__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N (30)
// ��� �����
struct huge_num
{
	char sign;     // ���� ��������: 0 - '-', 1 - '+'
	int m[N];      // ��������
	int power;     // �������
	char iszero;   // ���� ����
};

int get_sign(char *str);
int convert_float(struct huge_num *float_num, char *str);
int convert_int(struct huge_num *int_num, char *str);
void autofill(struct huge_num *num);
void err_msg(int code);
int lmul(struct huge_num *float_num, struct huge_num *int_num, char *answer);

#endif