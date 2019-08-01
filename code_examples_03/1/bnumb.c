#include "bnumb.h"

int full_check_big_numb(const char* str, int* pse, int* psm, int* pp, int* pe, int* len)  // Работает без проблем
{
    int pos_s_e = 0;
	int pos_s_m = 0;
	int pos_p   = 0;
	int pos_e   = 0;
	int lenght  = 0;
	
	int si_cnt = 0;
	int p_cnt  = 0;
	int e_cnt  = 0;
	
	int i = 0;
	
	while((str[i] != '\n')&&(str[i] != '\0')&&(str[i] != EOF))
	{
	    // Проверка на наличие посторонних символов
	    if (((str[i] >= '0') && (str[i] <= '9')) || 
		     (str[i] == '+') || (str[i] == '-') ||
			 (str[i] == '.') || (str[i] == 'E'))
		{
		    if ((str[i] == '+') || (str[i] == '-'))
			{
			    si_cnt++;
				
			    if (e_cnt == 0)
				    pos_s_m = i+1;
				else
				    pos_s_e = i+1;
			}
			
			if (str[i] == '.')
			{
			    p_cnt++;
				
				pos_p = i+1;
			}
			
			if (str[i] == 'E')
			{
			    e_cnt++;
				
				pos_e = i+1;
			}
		}
		else
		    return 0;
			
		i++;
	}
	
	// Проверка количества символов + - . Е
	if ((si_cnt != 2) || (p_cnt > 1) || (e_cnt != 1))
	    return 0;
		
	// Проверка положения символов
	if (pos_s_m != 1)                      // Знак до Е
	    return 0;
		
	if (pos_p >= pos_e)                    // Точка и Е
	    return 0;
		
	if (pos_e >= pos_s_e)                  // E и знак после Е
	    return 0;
		
	lenght = i + 1;
		
	// Проверка положения цифр и их количества
	if (lenght < 5)
	    return 0;
	else
	{
	    if (p_cnt != 0)  // Проверка длины мантисы
		{
		    if (lenght < 6)
			    return 0;
			else
			{
			    if (((pos_e - pos_s_m - 2) <= 0) || ((pos_e - pos_s_m - 2) > 30))
				    return 0;
					
			}
		}
		else
		{
		    if (((pos_e - pos_s_m - 1) <= 0) || ((pos_e - pos_s_m - 1) > 30))
				return 0;
		}
		
		if (((lenght - pos_s_e - 1) <= 0) || ((lenght - pos_s_e - 1) > 5))  // Проверка длины порядка
			return 0;
	}
	
	// Возвращаем дополнительные параметры
	*pse = pos_s_e;
	*psm = pos_s_m;

	if (pos_p == -1)
	    *pp = 0;
	else
	    *pp = pos_p-1;

	*pe = pos_e;
	*len = lenght;
	
	return 1;
}

int get_mant_fr_str(const char* str, char* mantis, int pos_sign_m, int pos_e)  // Работает точно
{
    int j = 0;
	
	if (pos_sign_m >= pos_e)
	    return 0;
	
    for (int i = pos_sign_m; i < pos_e-1; i++)
	{
	    if ((*(str + i)) != '.')
		{
	        *(mantis + j) = *(str + i);
		    j++;
		}
	}
	
	return 1;
}

int get_e_from_str(char* bg, char* nd) // Работает без проблем
{
	int m = 1;
	int sum = 0;

	for ( int i = nd-bg-1; i >= 0; i--)
	{
	    sum += ((*(bg+i))-'0')*m;
		m = m*10;
	}

	return sum;
}

struct big_numb* get_big_numb(FILE* f)
{
	char str[MAX_LEN];
	
	int pos_s_e = 0;
	int pos_s_m = 0;
	int pos_p = 0;
	int pos_e = 0; 
	int len = 0;
	
	struct big_numb* buff;
	
	buff = malloc(sizeof(struct big_numb));
	
	if (!buff)
	    return NULL;
	
	fscanf(f, "%s", str);
	
	if (full_check_big_numb(str, &pos_s_e, &pos_s_m, &pos_p, &pos_e, &len))
	{
	    get_mant_fr_str(str, buff->mant, pos_s_m, pos_e);
		buff->sign_m = str[0];
		buff->dot_pos = (char) pos_p;
		buff->e = get_e_from_str(str+pos_s_e, str+len-1);
		
		if (str[pos_e] == '-')
		    buff->e = -buff->e;
		
		
		if (pos_p == -1)
		    buff->m_len = pos_e - pos_s_m - 1;
        else
		    buff->m_len = pos_e - pos_s_m - 2;
	}
	else
	    return NULL;

	return buff;
}

void print_mantis(char* m, char d, char len) // Работает без проблем
{
    if (d == 1)
	    printf("0.");
	
	d--;
	
	for (int i = 0; i < len; i++)
	{
		if ((d == i)&&(d != 0))
		    printf(".");
		
	    printf("%c", *(m+i));
	}
}

void print_big_numb(struct big_numb number)  // Работает без проблем
{
    printf("%c", number.sign_m);
	print_mantis(number.mant, number.dot_pos, number.m_len);
	if (number.e >= 0)
	    printf("E+%d", number.e);
	else
	    printf("E%d", number.e);
}

void print_i_big_numb(struct big_numb number)  // Работает без проблем
{
	printf("%c", number.sign_m);
	
	for (int i = 0; i < number.m_len; i++)
	    printf("%c", number.mant[i]);
}

int check_big_i_numb(const char* str, int* len)  // Работает без проблем
{
    int i = 0;

	if ((*str != '+')&&(*str != '-'))
        return 0;
		
	i++;

	while ((str[i] != '\n')&&(str[i] != '\0')&&(str[i] != EOF))
	{
		if (((*(str + i)) < '0') || ((*(str + i)) > '9'))
			return 0;
			
        i++;			
	}

	*len = i;
	
	if ((*len > 31) || (*len < 2))
	    return 0;
	
	return 1;
}

struct big_numb* get_i_big_numb(FILE* f) // Работает без проблем
{
	char str[MAX_LEN];
	int len = 0;
	
	struct big_numb* buff;

	buff = malloc(sizeof(struct big_numb));
	
	if (!buff)
	    return NULL;

	fscanf(f, "%s", str);
	
	if (check_big_i_numb(str, &len))
	{
	    get_mant_fr_str(str, buff->mant, 1, len+1);
		buff->sign_m = str[0];
		buff->dot_pos = len;
		buff->e = 0;
		
		buff->m_len = len - 1;	
	}
	else
	    return NULL;

	return buff;
}