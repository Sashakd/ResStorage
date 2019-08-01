#include "io_huge.h"

// определение знака OK
int get_sign(char *str)
{
	if (str[0] == '-')
	{
		memmove(str, str+1, strlen(str));
		return 0;
	}

	if (str[0] == '+')
		memmove(str, str+1, strlen(str));
	return 1;
}

// определение порядка OK
int get_pow(char *pow, struct huge_num *float_num)
{
	for (int i = 0; i < strlen(pow); i++) 	//проверяем корректность порядка
		if (!(isdigit(pow[i]) || (i==0 && (pow[i]=='+' || pow[i]=='-'))))
			return -2;

	int int_val = atoi(pow);
	if (int_val < -99999) 	// машинный ноль
		return -3;
	if (int_val > 99999)	// переполнение
		return -4;
	float_num->power = int_val;

	return 0;
}

// переносим за точку все цифры OK
void del_point(char *str, struct huge_num *float_num)
{
	if (strchr(str, '.'))
	{
		float_num->power++; // место, где стоит точка, оказывается за точкой
		for (int i = (strchr(str, '.') - str); i > 0; i--)
		{
			str[i] = str[i-1];
			float_num->power++;
		}
		str[0] = '0';
	}
	else
		float_num->power += strlen(str);
}

// нормализуем число OK
void normalisation(char *str, struct huge_num *float_num)
{
	while (str[0] == '0')
	{
		memmove(str, str+1, strlen(str));
		float_num->power--;
	}
}

// переносим цифры в конец массива, отведенного под мантиссу OK
int thread_to_mas(char *str, struct huge_num *float_num)
{
	int int_val = strlen(str);

	for (int i = 0; i < int_val; i++)
		if (isdigit(str[int_val-i-1]))
		{
			if (str[int_val-i-1] != '0')
				float_num->iszero = 0;
			float_num->m[N-i-1] = str[int_val-i-1]-'0';
		}
		else
			return -2;

	return 0;
}

// отбрасываем незначащие нули мантиссы OK
void cut_zero(struct huge_num *float_num)
{
	if (float_num->iszero == 0)
		while (float_num->m[N-1] == 0)
		{
			for (int i = N-1; i > 0; i--)
				float_num->m[i] = float_num->m[i-1];
			float_num->m[0] = 0;
		}
}

// заполнение начальными значениями OK
void autofill(struct huge_num *num)
{
	num->sign = 1;
	memset(num->m, 0, sizeof(num->m));
	num->power = 0;
	num->iszero = 1;
}

// проверка корректности действительного числа OK
int convert_float(struct huge_num *float_num, char *str)
{
	char *pow; // строка под порядок числа
	int rc;

	if (strlen(str) == 0)
		return -5;

	float_num->sign = get_sign(str);
	if (strchr(str, 'E') != NULL) 	// выделяем порядок
	{
		pow = strchr(str, 'E')+1;
		*(pow - 1) = '\0';
		if ((rc=get_pow(pow, float_num))!=0)
			return rc;
	}
	if (strchr(str, '.') != strrchr(str, '.'))
		return -2;

	del_point(str, float_num);
	normalisation(str, float_num);
	if (strlen(str) > N)
		return -1;

	if ((rc=thread_to_mas(str, float_num))!=0)
		return rc;
	cut_zero(float_num);

	return 0;
}

// проверка корректности целого числа ОК
int convert_int(struct huge_num *int_num, char *str)
{
	int rc=0;

	int_num->sign = get_sign(str);
	if (strlen(str) == 0)
		return -5;
	if (strlen(str) > N)
		return -1;
	if ((rc=thread_to_mas(str, int_num))!=0)
		return rc;
	if (int_num->iszero == 0)
		int_num->power = strlen(str);
	cut_zero(int_num);

	return 0;
}

// вывод сообщения об ошибке OK
void err_msg(int code)
{
	printf("\nError ");
	switch (code)
	{
		case -1:
			printf("'Too large length of mantiss'\n");
			break;
		case -2:
			printf("'Some symbols are not digits'\n");
			break;
		case -3:
			printf("'Machine zero'\n");
			break;
		case -4:
			printf("'Too large power (overflow)'\n");
			break;
		case -5:
			printf("'Input empty'\n");
			break;
	}
}

// строка с ответом ОК
int answertostr(char sign, int *m, int size, int power, char *answer)
{
	int count = size;

	memset(answer, '\0', 50);
	if (power < -99999)
		return -3;
	if (power > 99999)
		return -4;

	switch (sign)
	{
		case 0:
			answer[0] = '-';
			break;
		case 1:
			answer[0] = '+';
			break;
	}
	while (m[count-1] == 0)
		count--;
	answer[1] = '0';
	answer[2] = '.';
	for (int i = 0; i < count; i++)
		answer[3+i] = m[i]+48;
	answer[strlen(answer)] = 'E';
	if (power < 0)
		answer[strlen(answer)] = '-';
	sprintf(answer+strlen(answer), "%d", abs(power));

	return 0;
}

// получение количества значащих цифр числа ОК
int get_size_num(struct huge_num *num)
{
	int size = N;
	while ((num->m[size-1] != 0) && (size > 0))
		size--;
	return N - size;
}

// поразрядный перенос OK
void byte_thread(int *m, int size)
{
	int bt = 0; // поразрядный перенос
	//выполняем поразрядный перенос
	for (int i = size; i > 0; i--)
	{
		m[i-1] += bt;
		bt = m[i-1]/10;
		m[i-1] = m[i-1]%10;
	}
}

// округляем мантиссу до 30 знаков
void round_huge(int *m, int size)
{
	if (size > N)
		for (int i = size; i > N; i--)
		{
			if (m[i-1] >=5)
				m[i-2]++;
			m[i-1] = 0;
		}
}

// Умножение длинного действительного числа на длинное целое число
int lmul(struct huge_num *float_num, struct huge_num *int_num, char *answer)
{
	int size_float = get_size_num(float_num); // число значащих цифр в мантиссе действ. числа
	int size_int = get_size_num(int_num); // число значащих цифр в целом числе
	int max_size = size_float + size_int; // максимальная длина мантиссы произведения
	char sign = 0;    								// знак произведения: 0 - '-', 1 - '+'
	int m[max_size];                                // мантисса
	int power = float_num->power + int_num->power;  // порядок произведения

	if ((float_num->iszero == 1) || (int_num->iszero == 1))
	{
		strcpy(answer, "+0.0E0");
		return 0;
	}
	if (float_num->sign == int_num->sign) 	// знак произведения
		sign = 1;
	memset(m, 0, max_size*sizeof(int));
	for (int j = N-size_int; j<N; j++)
		for (int k = N-size_float; k<N; k++)
			m[max_size-(N+N-1-j-k)] += int_num->m[j] * float_num->m[k];

	byte_thread(m, max_size);
	for (int i = 0; i < max_size; i++) 	// отбрасываем незначащие нули
	{
		if (m[0] != 0)
			break;
		for (int j = 0; j<max_size-1; j++)
			m[j] = m[j+1];
		m[max_size-1] = 0;
		power--;
	}

	round_huge(m, max_size);
	if (max_size>N)
		max_size = N;
	byte_thread(m, max_size);

	return answertostr(sign, m, max_size, power, answer);
}


