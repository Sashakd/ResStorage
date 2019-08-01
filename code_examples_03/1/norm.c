#include "norm.h"

/*
+0.1E+1
+4


*/

struct big_numb* move_mantis(struct big_numb*  num, char* side, char* rem)  // Работает
{
    if ((strncmp(side, "left", 4) == 0) || (strncmp(side, "right", 5) == 0))
	{
	    if (strncmp(side, "left", 4) == 0)  // Влево
		{
		    *rem = *(num->mant);
			
		    for (int i = 1; i < num->m_len; i++)
			    num->mant[i-1] = num->mant[i];
			
			(num->m_len)--; 
		}
		else                                // Вправо
		{
		    *rem = *(num->mant + num->m_len - 1);
			
			for (int i = num->m_len - 1; i > 0; i--)
			    num->mant[i] = num->mant[i-1];
			
			*(num->mant) = '0';
		}
	
		return num;
	}
	else
	    return NULL;
}

int is_zero(struct big_numb*  num)  // Работает
{
    for (int i = 0; i < num->m_len; i++)
	    if (num->mant[i] != '0')
		    return 0;
	
	return 1;
}

struct big_numb* normalize(struct big_numb*  num)
{
    // если не нули справа от точки и слева одни нули, то удалить нули слева до точки и справа до цифр
    // циклы слева и справа до точки
	
	char rem = 0;
 
    if (is_zero(num)) // Проверка на равенство нулю
	{
		num->sign_m = '+';
		num->m_len = 1;
		num->dot_pos = 1;
		num->e = 0;
	}
	else
	{
	    // Удаление лишних нулей посредством банального сдвига (порядок не меняется)
	    // Но меняется длина и положение точки
	    //int i = 0;
		while ((num->mant[num->m_len-1] == '0') && (num->m_len >= num->dot_pos))  // С конца
			(num->m_len)--;
		
		// Сдвигаем точку на первую позицию и меняем порядок
		if ((num->dot_pos == 0) || (num->dot_pos == -1))  // Если без точки
		{
		    num->dot_pos = 1;
			num->e += num->m_len;
		}
		else // С точкой  /// <================== ЗДЕСЬ
		{
		    num->e += num->dot_pos-1; // <===== что-то не так Если dot_pos == 1
			/*
			if (num->mant[0] == '0')  // <== сомнительно
			    (num->e)--;
			*/
			
			num->dot_pos = 1;
			
			// Кое-что не учтено
			
			// Сдвигаем влево пока на позиции точки окажется не ноль
			while (num->mant[0] == '0')
			{
				num = move_mantis(num, "left", &rem);
				(num->e)--;
			}
		}
	}
    
	return num;
}
