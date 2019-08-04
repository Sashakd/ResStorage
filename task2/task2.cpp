/*
Решим как задачу 3-ного пространства с векторами.
очевидно, что при рассмотрении пары векторов мы будем
иметь тройки векторов, лежащих в одной плоскости, вида: 
(x1, y1, 0), (x2, y2, 0). Отсюда их векторное произведение 
будет иметь вид: (0, 0, x1*y2 - y1*x2), если рассматривать 
вектор стороны многоугольника и вектора, проведённого от 
одной из вершин многоугольника, то величина x1*y2 - y1*x2 
будет характеризовать её положение относительно стороны 
многоугольника.

Т.о. используем векторное произведение
*/

/*
Раз про то с какой точностью это считать не сказано, 
то я пожалуй сделаю вид, что это делать не нужно.
*/
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

// Определяет положение точки относительно прямой, возвращает полученное 
// векторное произведение
// (не проверяет, является ли отрезок вырожденным)
/*
	K = 0 - на прямой
	K > 0 - слева ("снаружи")
	K < 0 - справа ("внутри")
*/
float det_loc_line(float x1, float y1, float x2, float y2, float cx, float cy)
{
	float K = (x2 - x1) * (cy - y1) - (y2 - y1) * (cx - x1);
	return K;
}

// Функция определяет находится ли точка на отрезке
// (не проверяет, является ли отрезок вырожденным)
/*
	1 - на отрезке
	0 - не на отрезке
*/
int is_on_segm(float x1, float y1, float x2, float y2, float cx, float cy)
{
	if (det_loc_line(x1, y1, x2, y2, cx, cy) == 0)  // Если точка минимум на прямой
	{
		// Определяем границы области в которой должна находиться точка
		// так как мы не передаём эти параметры по ссылке, то с ними ничего
		// не случится
		if (x2 < x1)
			swap(x1, x2);
		if (y2 < y1)
			swap(y2, y1);
		
		if ((x1 <= cx) && (cx <= x2) && (y1 <= cy) && (cy <= y2))
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

// Определяет положение точки относительно течырёхугольника
/*
	0 - точка на одной из вершин
	1 - точка на одной из сторон
	2 - точка внутри
	3 - точка снаружи
*/
int det_loc_quad(float x1, float y1, float x2, float y2, float x3, float y3, 
				 float x4, float y4, float cx, float cy)
{
	if (((cx == x1) && (cy == y1)) || 
	    ((cx == x2) && (cy == y2)) || 
		((cx == x3) && (cy == y3)) || 
		((cx == x4) && (cy == y4)))  // Точка на одной из вершин
		return 0;
	else   // Точка не на одной из вершин
	{
		if (is_on_segm(x1, y1, x2, y2, cx, cy) ||
			is_on_segm(x2, y2, x3, y3, cx, cy) ||
			is_on_segm(x3, y3, x4, y4, cx, cy) ||
			is_on_segm(x4, y4, x1, y1, cx, cy))  // Точка на одной из сторон
			return 1;
		else
		{
			if ((det_loc_line(x1, y1, x2, y2, cx, cy) < 0) &&
				(det_loc_line(x2, y2, x3, y3, cx, cy) < 0) &&
				(det_loc_line(x3, y3, x4, y4, cx, cy) < 0) &&
				(det_loc_line(x4, y4, x1, y1, cx, cy) < 0))  // Точка внутри
				return 2;
			else  // Точка снаружи
				return 3;
		}
	}
}

int main(int argc, char* argv[])  //argc - кол-во аргументов, argv[] - аргумент
{
	if (argc == 3)
	{
		ifstream fin_quad;    // Файл с четырёхугольником
		ifstream fin_points;  // Файл с точками
		
		fin_quad.open(argv[1]);

		if (fin_quad.is_open())  // Если файл с четырёхугольником открыт
		{
			// Отлично, теперь нам надо всего лишь запомнить 8 значений
			// просто обычных переменных будет достаточно
			float x1, y1;
			float x2, y2;
			float x3, y3;
			float x4, y4;
			
			// Будем делать рассчёты по ходу чтения, так что это тоже подойдёт
			float xc, yc;
			
			// Считываем 4 точки (их наличие не проверяется)
			fin_quad >> x1 >> y1;
			fin_quad >> x2 >> y2;
			fin_quad >> x3 >> y3;
			fin_quad >> x4 >> y4;
			
			fin_quad.close();  // Закрываем файл
			
			fin_points.open(argv[2]);
			
			if (fin_points.is_open())  // Если файл с точками открыт
			{
				char buff1[100];           // Строковый буфер
				char buff2[100];
			
				while (!fin_points.eof())  // Считываем до конца файла
				{
					fin_points.get(buff1, 100, ' ');
					fin_points.getline(buff2, 100);  // Считываем строку
					
					if ((strcmp(buff1, "") != 0) && (strcmp(buff2, "") != 0)) // Убеждаемся, что строка не пуста
					{
						xc = atof(buff1);
						yc = atof(buff2);
						
						// Выполняем вычисление положения точки
						// (Проверка на вырожденность четырёхугольника не применяется)
						int res = det_loc_quad(x1, y1, x2, y2, x3, y3, x4, y4, xc, yc);
						cout << res << "\n";
					}	
				}
				
				fin_points.close();
			}
			else
			{
				cout << "Error! No file2" << endl;
				return 1;
			}
		}
		else
		{
			cout << "Error! No file1" << endl;
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