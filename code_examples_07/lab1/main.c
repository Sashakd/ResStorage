#include "io_huge.h"

int main(void)
{
	int rc=0;
	char *str1 = malloc(50*sizeof(char)); //строка для ввода первого числа
	char *str2 = malloc(50*sizeof(char)); //строка для ввода второго числа
	struct huge_num *float_num = malloc(sizeof(struct huge_num)); // первое число	
	struct huge_num *int_num = malloc(sizeof(struct huge_num)); // второе число
	char *answer = malloc(50*sizeof(char)); //строка для ответа
	
	autofill(float_num);
	autofill(int_num);
	
	printf("\nLONG MULTIPLICATION\n");
	printf("\nReal number - in format (+/-)m.nE(+/-)K ,\n");
	printf("\t(m+n) - up to 30 digits, K - up to 5 digits \n");
	printf("Integer -  up to 30 decimal digits \n");
	printf("\nInput the real number:       |\n");
	gets(str1);
	
	rc = convert_float(float_num, str1);
	if (!rc)
	{	
		printf("\nInput the integer:           |\n");
		gets(str2);	
		rc = convert_int(int_num, str2);
	}
	if (!rc)	
		rc = lmul(float_num, int_num, answer);
	if (!rc)
		printf("\nResult = %s\n", answer);
	else
		err_msg(rc);
	
	free(float_num);
	free(str1);
	free(int_num);
	free(str2);
	free(answer);

	return rc;
}