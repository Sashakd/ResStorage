// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <list>
#include <cstdlib>
#include <cstring>
#include <string>
//#include <sstream>

using namespace std;
/* Если файл с данными будет оканчиваться числом
   с символом "\n", то он прочтёт и следующую строку
   как 0*/
// ------------------------------------------ нужно это как-то исправить

/* И да я знаю, что все расчёты можно провести за один 
   проход по списку, но я лучше разобью это на несколько
   функций для лучшей читаемости кода*/
   
/* В промежуточных расчётах short int не использовать,
   т.к. сумма может достигать значения в несколько
   десятков миллионов. Лучше использовать только для
   хранения в списке*/

double func_round100(double num)
{
	double buff = round(num *100) / 100;
	return buff;
}

// Функция расчёта 90-перцентиля
// Может принимать список длинной 1 и более
// Не проверяет список на пустоту
double func_perc90(list <short int> numbers)
{
	double perc_n = 0.9 * (numbers.size() - 1) + 1;
	int perc_n_div = floor(perc_n);  // Целая часть порядкового номера искомого
	double perc_n_mod = perc_n - perc_n_div;    // дробная часть искомого числа
	double perc = 0;  // Значение перцентиля
	double buff_a = 0;
	double buff_b = 0;
	
	int cnt = 0;
		
	for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
	{ 
		if (cnt + 1 == perc_n_div)
			buff_a = *iter;
		
		if (cnt == perc_n_div)
		{
			buff_b = *iter;
			break;
		}
			
		cnt++;
	}
			
	perc = buff_a + perc_n_mod * (buff_b - buff_a);  // Подсчёт по формуле		
	
	return perc;
}

// Функция находит медиану и возвращает это значение
double func_median(list <short int> numbers)
{
	// От одного элемента в списке
	if (numbers.size() % 2 == 1)  // Нечётное число элементов ряда
	{
		int med_n = (numbers.size() + 1) / 2;
		int cnt = 0;
		
		for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
		{ 
			if (cnt + 1 == med_n)
				return *iter;  // Возможно так делать не безопасно (проверить)
				
			cnt++;
		}
	}
	else                            // Чётное число элементов ряда
	{
		int med_n1 = numbers.size() / 2;
		int med_n2 = med_n1 + 1;
		double median1;
		double median2;
		int cnt = 0;
		
		for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
		{ 
			if (cnt + 1 == med_n1)
				median1 = *iter;
			
			if (cnt == med_n1)
			{
				median2 = *iter;
				break;
			}
				
			cnt++;
		}
		
		return (median1 + median2) / 2.0;
	}
	
	return 0;
}

/* А вот максимальное, минимальное и среднее вполне 
   можно найти и вместе в одной функции*/
   
// Функция находит минимум, максимум и среднее;
// возвращает 1 - если успешно, 0 - если возникла ошибка
// результаты вычислений возвращаются через аргументы функции
int func_max_min_mid(list <short int> numbers, double &min, double &mid, double &max)
{
	if (numbers.size() > 1)  // число элементов списка больше одного
	{
		min = numbers.front();
		max = numbers.front();
		mid = 0;
		
		for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
		{ 
			if (*iter > max)
				max = *iter;
			if (*iter < min)
				min = *iter;
			mid += *iter;
		}
		
		mid = mid / double(numbers.size());
		
		return 1;
	}
	else  // число элементов списка либо равно 0 или 1
	{
		if (numbers.size() == 1)  // число элементов = 1
		{
			min = numbers.front();
			max = min;
			mid = min;
			
			return 1;
		}
		else   // число элементов = 0
			return 0;
	}
}

int main(int argc, char* argv[])  //argc - кол-во аргументов, argv[] - аргумент
{
	if (argc == 2)
	{
		ifstream fin;

		fin.open(argv[1]);

		if (fin.is_open())  // Файл открылся
		{
			list <short int> numbers;  // Очередь, куда мы будем складывать числа
			short int buff;            // "Числа в файле в пределах от -32 768 до 32 767"
			char buff1[100];           // Строковый буфер
			//            (Я так понимаю, что имелось в виду, что эти числа целочисленные)
			
			while (!fin.eof())
			{
				fin.getline(buff1, 100);  // Считываем строку
				
				if (strcmp(buff1, "") != 0) // Убеждаемся, что строка не пуста
				{
					buff = atoi(buff1);
					numbers.push_back(buff);  // Добавляем число в очередь
				}	
			}
			
			fin.close();  // Закрываем файл
			
			numbers.sort();  // Сортируем

			// Основные расчёты
			// 90-прецентиль
			if (numbers.size() != 0)  // Если в файле вообще есть числа
			{
				double perc = func_perc90(numbers);
				perc = func_round100(perc);
				
				cout << perc << "\n";  // Вывод значения перцентиля
				
				// Медиана. Так как список упорядочен, то будет достаточно выбрать средний элемент
				double median = func_round100(func_median(numbers));
				
				cout << median << "\n";  // Вывод значения медианы
				
				// Находим минимум, максимум и среднее
				double min = 0;
				double mid = 0;
				double max = 0;
				
				func_max_min_mid(numbers, min, mid, max);  // (без проверки длины списка)
				
				min = func_round100(min);
				mid = func_round100(mid);
				max = func_round100(max);
				
				cout << max << "\n";  // Вывод максимального значения
				cout << min << "\n";  // Вывод минимального значения
				cout << mid << "\n";  // Вывод среднего значения
			}
			else
			{
				cout << "Error! No numbers" << endl;
				return 1;	
			}
			
			// Освобождаем очередь
			while (!numbers.empty())
				numbers.pop_front();
		}
		else
		{
			cout << "Error! No file" << endl;
			return 1;
		}
	}
	else
	{
		cout << "Error! No argument" << endl;
		return 1;
	}

	return 0;
}
