#include "multiply.h"

/*
ТЕСТЫ:
+0.00132400E+121




+0.00132400E+121
    *
+23457
    =
+0.23457E+6
+0.1324E+119
+0.0E+0

     +0.999999999999111111111111111111E+30
      *
     +9
      =
     +0.8999999999992E+31
*/

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

struct big_numb* multiply_FxI(struct big_numb* a, struct big_numb* b)
{
	struct big_numb* res = NULL;
	
	res = malloc(sizeof(struct big_numb));
	
	if (res)
	{
		// Нормализуем умножаемые числа
		a = normalize(a);
		b = normalize(b);
		
		int m_buff[BUFF_LEN] = {0,}; // По моей оценке этого достаточно
		
		// Предварительная инициализация
		if (a->sign_m == b->sign_m)
		    res->sign_m = '+';    // Знак мантисы
		else
			res->sign_m = '-';
		//char mant[30];  // Мантиса
		res->m_len = 30;     // Длина мантисы
		res->dot_pos = 1;   // Положение точки
		res->e = 0;
		
		if ((is_zero(a)) || (is_zero(b)))  // Это ноль
		{
			res->sign_m = '+';
			res->m_len = 1;
			res->dot_pos = 1;
			res->e = 0;
			
			return res;
		}
		
		// Умножение
		
		int st = 0;  // Смещение
		
			// Костное умножение без переносов в старший разряд
		for (int i = (b->m_len) - 1; i >= 0; i --) // len_b
		{
			int t = 0;
			
			for (int j = (a->m_len) - 1; j >= 0; j--)  // len_a
			{
				m_buff[BUFF_LEN - t+st - 1] += ((b->mant[i]) - '0') * ((a->mant[j]) - '0');
				t++;
			}
			
			st--;
		}
			
			// Все переносы
		for (int i = BUFF_LEN - 1; i >= 0; i--)
			if (m_buff[i] > 9)
			{
				m_buff[i-1] += m_buff[i]/10;
				m_buff[i]   = m_buff[i]%10;
			}                  
		
			// Копирование первых тридцати цифр (можно не учитывать нули после)
		    // Доходим до ненулевого а затем до тридцати или конца
		int rem = 0;
		
		for (int g = 0; g < 30; g++)
			res->mant[g] = '0';
		
		int y = 0;
			
		while (m_buff[y] == 0)
			y++;
			
		int k = 0;
			
		for ( ; k < 30; k++)
		{
			if (k + y < BUFF_LEN)
				res->mant[k] = m_buff[k+y] + '0';
			else
			{
				k--;
				
			    break;
			}
		}
		
		if ((k == 30) && (k+y < BUFF_LEN))
			rem = m_buff[k+y] + '0';
		
			// Округление
		if (rem >= '5')
		{
			(res->mant[29])++;
			m_buff[k+y-1]++;
			
				// Все переносы
			for (int i = BUFF_LEN - 1; i >= 0; i--)
				if (m_buff[i] > 9)
				{
					m_buff[i-1] += m_buff[i]/10;
					m_buff[i]   = m_buff[i]%10;
				}  
			
			for (int g = 0; g < 30; g++)
			res->mant[g] = '0';
			
			y = 0;
			
			while (m_buff[y] == 0)
				y++;
			
			k = 0;
			
			for ( ; k < 30; k++)
			{
				if (k + y < BUFF_LEN)
					res->mant[k] = m_buff[k+y] + '0';
				else
				{
					k--;
				
					break;
				}
			}
	        
		}
		
			// Перерасчёт разрядов
		///////////////////////////////////////////////
		if ((BUFF_LEN - y) >= (a->m_len + b->m_len))
			res->e = a->e + b->e;
		else
			res->e = a->e + b->e - 1;
		///////////////////////////////////////////////

		// Повторная нормализация и проверка
		res = normalize(res);
		
		if ((res->e < -99999) || (res->e > 99999))
		{
			free(res);
			return NULL;
		}
	}
	
	return res;
}