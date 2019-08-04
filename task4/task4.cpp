#include <iostream>
#include <set>
#include <list>
#include <cstring>
#include <cstdio>
#include <iterator>
#include <fstream>

using namespace std;

/*
	Функция преобразует строку с записью времени
	длиной 4 или 5 в целое число, корректность
	входных данных не проверяется.
*/
// (Не проверяет есть ли в полученной строке цифры)
// Преобразует время из строки в int специфическим
// образом, однако отношения вида > < = сохранятся
int spec_conv_time_char_to_int(char * char_time)
{
	if ((strlen(char_time) == 4) || (strlen(char_time) == 5))
	{
		if (strlen(char_time) == 5)  // Если 5 символов
		{
			char lf_part[3] = {0};  //  левая часть строки времени 
			char rt_part[3] = {0};  // правая часть строки времени 
			
			lf_part[0] = char_time[0];
			lf_part[1] = char_time[1];
			
			rt_part[0] = char_time[3];
			rt_part[1] = char_time[4];
			
			// Нижнее и верхнее значение числа
			int top_i = atoi(lf_part);
			int bot_t = atoi(rt_part);
			
			// Возвращаем число
			int num = top_i * 100 + bot_t;
			
			return num;
		}
		else  // Если 4 символов
		{
			char lf_part[3] = {0};  //  левая часть строки времени 
			char rt_part[3] = {0};  // правая часть строки времени 
			
			lf_part[0] = char_time[0];
			
			rt_part[0] = char_time[2];
			rt_part[1] = char_time[3];
			
			// Нижнее и верхнее значение числа
			int top_i = atoi(lf_part);
			int bot_t = atoi(rt_part);
			
			// Возвращаем число
			int num = top_i * 100 + bot_t;
			
			return num;
		}
	}
	else  // Если длина не соответствует необходимой
		return -1;
	
	return -2;
}

// Функция построения таймлайна
// Просто будем заполнять массив чисел
// или что-то в этом духе


// Структура посетителя
class visitor
{
	public:
		int time_in;
		int time_out;
		
	visitor(int t1, int t2)
	{
		time_in = t1;
		time_out = t2;
	}
};

int main(int argc, char *argv[])
{
	if (argc == 2) // Если указан файл с данными
	{
		FILE *fin;
		
		fin = fopen(argv[1], "r");
		
		if (fin != NULL)
		{
			// Наш таймлайн 8:00 - 20:00
			// будем запоминать время как целые числа,
			// но просто будем проводить специфические
			// операции, 
			
			// Посетителей будем заносить в список
			list <class visitor> visitors;
			
			set<int> time_line;  // Сюда будем записывать всё
			// упомянутые промежутки времени
			
			char *char_time1 = new char[10];
			char *char_time2 = new char[10];
			int time1 = 0;
			int time2 = 0;
			
			while (!feof(fin))  // Пока не конец файла будем считывать
			{
				fscanf(fin, "%s %s\n", char_time1, char_time2);
				
				if ((strcmp(char_time1, "") != 0) && (strcmp(char_time2, "") != 0))  // Убеждаемся, что строка не пуста
				{
					// Конвертируем данные в нужный нам формат
					time1 = spec_conv_time_char_to_int(char_time1);
					time2 = spec_conv_time_char_to_int(char_time2);
					
					// Заносим в множество упомянутое время
					time_line.insert(time1);
					time_line.insert(time2);
					//cout << time1 << '\n';
					//cout << time2 << '\n';
					
					// Заносим в список посетителя
					visitors.push_back(visitor(time1, time2));
				}
			}
			
			fclose(fin);
			
			//copy( time_line.begin(), time_line.end(), ostream_iterator<int>(cout, " "));
			
			//cout << "\n";

			// Кол-во временных промежутков:
			int n_count = time_line.size() - 1;
			
			// Переносим данные из множества в массив
			// Выделяем массив под хранение таймлайна
			int *time_line_i = new int[n_count+1];
			
			// Выделяем массив для подсчёта людей во временных
			// промежутках
			int *humons_mid_time = new int[n_count];
			
			int k = 0;
			
			// (антивирус руинит то, что происходит в этм цикле)
			for (auto it = time_line.begin(); it != time_line.end(); ++it)
			{
				time_line_i[k] = *it;	
			    k++;
			}
			
			time_line.clear();  // Очищаем множество, оно нам больше не понадобится
			
			// Инициализируем массив меток посещения
			
			for (int i = 0; i < n_count; i++)
				humons_mid_time[i] = 0;
			
			// Основные расчёты
			// Есть массив с таймлайном и список клиентов
			// осталось найти сколько человек в каждом 
			// временном промежутке и найти максимум (если 
			// не одино, то это тоже учесть)
			
			for (auto it = visitors.begin(); it!= visitors.end(); ++it)  // Для каждого посетителя
			{
				for (int i = 0; i < n_count; i++)  // Просматриваем весь таймлайн
				{
					// И отмечаем все его посещения на отрезках
					if ((time_line_i[i] >= it->time_in) && (it->time_out >= time_line_i[i+1]))
						humons_mid_time[i]++;
				}
			}
			/*
			for (int i = 0; i <n_count; i++)
				cout << humons_mid_time[i] << "=h\n";
			*/
			// Ищем значение максимума
			int max = humons_mid_time[0];
			
			for (int i = 0; i < n_count; i++)
			{
				if (humons_mid_time[i] > max)
					max = humons_mid_time[i];
			}
			
			// Отлично, теперь осталось выписать последовательность из отрезков,
			// но нужно учесть, что некоторые идут подряд и их надо объединить
			//---------------------------------------
			int buff_beg = -1;
			int buff_end = -1;
			
			for (int i = 0; i < n_count; i++)
			{
				if (humons_mid_time[i] == max)  // Если максимальное число клиентов
				{
					if (buff_beg == -1)  // Если флаг начала сброшен, то
						buff_beg = time_line_i[i];  // запомнить начало отрезка
					// Если это конец отрезка, то запомнить конец
					if ((i < n_count-1) && (humons_mid_time[i+1] != max))
						buff_end = time_line_i[i+1];
					else
						if (i == n_count-1)
							buff_end = time_line_i[i+1];
				}
				
				// Если отрезок полностью определён
				if ((buff_beg != -1) && (buff_end != -1))
				{
					//cout << buff_beg << " " << buff_end << "\n";
					int beg1 = buff_beg / 100;
					int beg2 = buff_beg % 100;
					
					int end1 = buff_end / 100;
					int end2 = buff_end % 100;
					
					// Выводим ответ в привычном формате
					cout << beg1 << ":";
					if (beg2 > 9)
						cout << beg2;
					else
						cout << "0" << beg2;
					cout << " " << end1 << ":";
					if (end2 > 9)
						cout << end2;
					else
						cout << "0" << end2;
					cout << "\n";
					
					buff_beg = -1;
					buff_end = -1;
				}
			}
			
			visitors.clear();  // Очищаем список посетителей
			
			delete(time_line_i);
			delete(humons_mid_time);
			
			return 0;
		}
		else
		{
			cout << "No file\n";
			
			return 1;
		}
	}
	else
	{
		cout << "No argument\n";
		
		return 1;
	}
}

/*
char t1[6] = "8:00";
			char t2[6] = "10:20";
			
			
			set<int> time_line;  // Сюда будем записывать всё
			// упомянутые промежутки времени
			
			int tt1 = spec_conv_time_char_to_int(t1);
			int tt2 = spec_conv_time_char_to_int(t2);
			
			time_line.insert(tt2);
			time_line.insert(tt1);
			time_line.insert(tt2);
			time_line.insert(1002);
			time_line.insert(2215);
			time_line.insert(2001);
			time_line.insert(1002);
			time_line.insert(2215);
			
			copy( time_line.begin(), time_line.end(), ostream_iterator<int>(cout, " "));
			
			// Кол-во временных промежутков:
			int n_count = time_line.size() - 1;
			
			cout << n_count << "\n";
			
			// Выделяем массив под хранение таймлайна
			int *time_line_i = new int(n_count+1);
			
			// Выделяем массив для подсчёта людей во временных
			// промежутках
			int *humons_mid_time = new int(n_count);
			
			int cnt = 0;
			cout << endl;
			
			for (auto it = time_line.begin(); it != time_line.end(); ++it)
			{
			   cout << *it << endl;
			   time_line_i[cnt] = *it;
			   cnt++;
			}
			cout << endl;
			
			time_line.clear();  // Очищаем множество, оно нам больше не понадобится
			
			for (int i = 0; i < n_count+1; i++)
				cout << time_line_i[i] << endl;
			
			// Теперь для каждого человека обходим временные промежутки, отмечае,
			// где он появился
			
			
			cout << tt1 << "\n";
			cout << tt2 << "\n";
			
			
			delete(time_line_i);
			delete(humons_mid_time);
*/