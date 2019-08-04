/*Звучит как из шестнадцати сумм пяти чисел найти наибольшее*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<direct.h>
#include<cstring>
#include <fstream>
#include<io.h>
#define mode 0x10

using namespace std;

// Копипаста с интернетов поиска файлов в дирректориях
// Теперь встроим поиск конкретных пяти файлов
// Возвращает пять полных путей, но не проверяет их существование
// (может вернуть пустые строки)
void check_cash(char*dir, char* Cash1, char* Cash2, char* Cash3, char* Cash4, char* Cash5)
{
    struct _finddata_t f;
    char*add = new char[strlen("\\*.*") +1];
	strcpy(add, "\\*.*");
    intptr_t disc=0;
    char dirr[1000] = { 0 };
    sprintf(dirr, "%s%s", dir, "\\*.*");
    
    
    if ((disc = _findfirst(dirr, &f)) == -1L)
    {
        //cout << "can't open dir" << endl;
        return;
    }
    else
    {
        do
        {
			/*
            if(strcmp(f.name,".")!=0 && strcmp(f.name,"..")!=0)  // Если имя файла не "." и ".."
                cout << f.name << " " << f.size << endl;
			*/
			
			// Если найден один из перечисленных ниже файлов, запоминает их полное имя
			if(strcmp(f.name,"Cash1.txt") == 0)
			{
				char *buff = new char[strlen(dirr) + strlen(f.name) + 1]; // это верно
				strcpy(buff, dirr);
				buff[strlen(dirr)-1] = '\0';  buff[strlen(dirr)-2] = '\0';  buff[strlen(dirr)-3] = '\0';
				strcat(buff, f.name);
				strcpy(Cash1, buff);
			}
			if(strcmp(f.name,"Cash2.txt") == 0)
			{
				char *buff = new char[strlen(dirr) + strlen(f.name) + 1]; // это верно
				strcpy(buff, dirr);
				buff[strlen(dirr)-1] = '\0';  buff[strlen(dirr)-2] = '\0';  buff[strlen(dirr)-3] = '\0';
				strcat(buff, f.name);
				strcpy(Cash2, buff);
			}
			if(strcmp(f.name,"Cash3.txt") == 0)
			{
				char *buff = new char[strlen(dirr) + strlen(f.name) + 1]; // это верно
				strcpy(buff, dirr);
				buff[strlen(dirr)-1] = '\0';  buff[strlen(dirr)-2] = '\0';  buff[strlen(dirr)-3] = '\0';
				strcat(buff, f.name);
				strcpy(Cash3, buff);
			}
			if(strcmp(f.name,"Cash4.txt") == 0)
			{
				char *buff = new char[strlen(dirr) + strlen(f.name) + 1]; // это верно
				strcpy(buff, dirr);
				buff[strlen(dirr)-1] = '\0';  buff[strlen(dirr)-2] = '\0';  buff[strlen(dirr)-3] = '\0';
				strcat(buff, f.name);
				strcpy(Cash4, buff);
			}
			if(strcmp(f.name,"Cash5.txt") == 0)
			{
				char *buff = new char[strlen(dirr) + strlen(f.name) + 1]; // это верно
				strcpy(buff, dirr);
				buff[strlen(dirr)-1] = '\0';  buff[strlen(dirr)-2] = '\0';  buff[strlen(dirr)-3] = '\0';
				strcat(buff, f.name);
				strcpy(Cash5, buff);
			}
			
            if ((f.attrib & mode) != 0)
            {
                
                if (strcmp(f.name, ".") != 0 && strcmp(f.name, "..") != 0)  // Если имя файла не "." и ".."
				
                sprintf(dirr, "%s\\%s", dir, f.name);   
            }   
            check_cash(dirr, Cash1, Cash2, Cash3, Cash4, Cash5);
            
        } while (_findnext(disc, &f) == 0);
    }
    _findclose(disc);
}

int main(int argc, char *argv[])
{
    
    char*ch = new char[BUFSIZ]();
    strcpy(ch, argv[1]);
	
	// Полные имена файлов
	char Cash1[1000] = { 0 };
	char Cash2[1000] = { 0 }; 
	char Cash3[1000] = { 0 };
	char Cash4[1000] = { 0 };
	char Cash5[1000] = { 0 };
	
	int buff;
	
	check_cash(ch, Cash1, Cash2, Cash3, Cash4, Cash5);
	
	// Собственно файлы
	ifstream Ca1;
	ifstream Ca2;
	ifstream Ca3;
	ifstream Ca4;
	ifstream Ca5;
		
	Ca1.open(Cash1);
	Ca2.open(Cash2);
	Ca3.open(Cash3);
	Ca4.open(Cash4);
	Ca5.open(Cash5);
	
	// Если открыты все пять файлов
	if (Ca1.is_open() && Ca2.is_open() && Ca3.is_open() && Ca4.is_open() && Ca5.is_open())
	{
		float curr_sum = 0;
		float max = 0;
		float max_no = 0;
		
		char buff1[100];  // Сюда будем предварительно записывать из потока файла1
		char buff2[100];  // Сюда будем предварительно записывать из потока файла2
		char buff3[100];  // Сюда будем предварительно записывать из потока файла3
		char buff4[100];  // Сюда будем предварительно записывать из потока файла4
		char buff5[100];  // Сюда будем предварительно записывать из потока файла5
		
		// Запоминаем считанние числа
		float num1;
		float num2;
		float num3;
		float num4;
		float num5;
		
		// Здесь выполняем основные расчёты
		for (int i = 1; i < 17; i++)
		{
			if (!Ca1.eof() && !Ca2.eof() && !Ca3.eof() && !Ca4.eof() && !Ca5.eof())  // Проверяем не дошли ли мы конца файлов
			{
				Ca1.getline(buff1, 100);
				Ca2.getline(buff2, 100);
				Ca3.getline(buff3, 100);
				Ca4.getline(buff4, 100);
				Ca5.getline(buff5, 100);
				
				// Проверяем что считанные строки не пусты
				if ((strcmp(buff1, "") != 0) && (strcmp(buff2, "") != 0) && 
				    (strcmp(buff3, "") != 0) && (strcmp(buff4, "") != 0) &&
					(strcmp(buff5, "") != 0))
				{
					num1 = atof(buff1);
					num2 = atof(buff2);
					num3 = atof(buff3);
					num4 = atof(buff4);
					num5 = atof(buff5);
					
					// Собственно расчёты
					curr_sum = num1 + num2 + num3 + num4 + num5;
					
					if (i == 1)
					{
						max = curr_sum;
						max_no = 1;
					}
					else
					{
						if (curr_sum > max)
						{
							max = curr_sum;
							max_no = i;
						}
					}
				}
				else
				{
					Ca1.close();
					Ca2.close();
					Ca3.close();
					Ca4.close();
					Ca5.close();
					
					cout << "Line is empty\n";
					return 1;
				}
			}
			else  // Очевидно, что это ошибка
			{
				// Закрываем всё, что успели понаоткрывать
				Ca1.close();
				Ca2.close();
				Ca3.close();
				Ca4.close();
				Ca5.close();
				
				cout << "EOF reached\n";
				return 1;
			}
		}
		
		cout << max_no << "\n";
		
		Ca1.close();
		Ca2.close();
		Ca3.close();
		Ca4.close();
		Ca5.close();
		
		return 0;
	}
	else  // Иначе закрыть те, что успели открыться
	{
		if (Ca1.is_open())
			Ca1.close();
		if (Ca2.is_open())
			Ca2.close();
		if (Ca3.is_open())
			Ca3.close();
		if (Ca4.is_open())
			Ca4.close();
		if (Ca5.is_open())
			Ca5.close();
			
		cout << "Some files not found\n";
		return 1;
	}
	
    return 0;
}