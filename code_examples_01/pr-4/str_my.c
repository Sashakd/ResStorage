#include "str_my.h"

int my_strlen(const char * s)
{
	int len = 0;
	
	while(s[len] != '\0')
		len++;
	
	return len;
}

// %s %o

// запоминание восьмеричного значения
// Подобно нижней по возвращаемому значению
int restore_08_value(char *str, size_t n, int value)
{
	int val_len = 0;
	int curr = value;
	int mult = 1;
	int printed = 0;
	
	while(curr)
	{
		curr = curr / 8;
		mult *= 8;
		val_len++;
	}
	
	// смещено вправо
	mult /= 8; // <=== ???	
	
	while((printed <= n) && (printed <= val_len))
	{
		if (!mult)
			mult = 1;
		str[printed] = (value / mult % 8) + '0';
		mult /= 8; // 15 - откуда?
		printed++;
	}
		
	if (printed)
		return printed-1;
	else
		return 0;

	
	if (printed > 0)
		return	printed-1;
	else
		return 0;
}


// Работает норм
int restore_STR_value(char *str, int n, char *value)
{
	int str_len = my_strlen(value);
	int printed = 0;
	
	while((printed <= n) && (printed <= str_len))
	{
		str[printed] = value[printed];
		printed++;
	}
	
	if (printed)
		return printed-1;
	else
		return 0;

}

// Буфер должен быть обнулён
// Возвращает длину строки не может быть 
// больше n, заполняет буфер насколько это возможно
// 
int my_snprintf(char *s, size_t n, const char *format, ... )
{
	va_list vl;
	char *buff_ptr = s;
	
	va_start(vl, format); // указываем на последний явный параметр
	
	const char *form_ptr = format;
	
	while((form_ptr != '\0') && ((buff_ptr - s) < n)) // проверить
	{
		if ((*form_ptr == '%') && ((*(form_ptr+1) == 's') || (*(form_ptr+1) == 'o')))
		{
			if (*(form_ptr+1) == 's')
			{
				int inc = 0;
				char* value = va_arg(vl, char *);
				
				inc = restore_STR_value(buff_ptr, n - (buff_ptr - s)-1, value);
				
				buff_ptr += inc; // длина строки	
			}
			else
			if (*(form_ptr+1) == 'o')
			{
				int inc = 0;
				int value = va_arg(vl, int);
				
				inc = restore_08_value(buff_ptr, n - (buff_ptr - s)-1, value);
				buff_ptr += inc;
			}
			
			form_ptr += 2;
		}
		else
		{
			*buff_ptr = *form_ptr;
			buff_ptr++;
			form_ptr++;
		}
	}
	
	va_end(vl);
	
	return my_strlen(s);
}