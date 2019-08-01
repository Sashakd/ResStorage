#include <stdio.h>
#include <tchar.h>
#include "queue.h"
#include "arr_queue.h"

#include "test.h"

unsigned long long tick(void) 
{
	unsigned long long d;

	__asm__ __volatile__("rdtsc" : "=A"(d));

	return d;
}

int main(void) 
{
	int ch=0; // переменная цикла
	unsigned long long t1, t2, tt1, tt2; // для замеров времени
	float diff; // относительная разница между массивом и списком
	int num; 
    struct l_queue *p = NULL; // для примера с адресами памяти
/*
    printf("Test for array func:\n");
    test_a();
    printf("\n\n");
    printf("Test for list func:\n");
    test_s();
*/
    while (ch != 4)
    {
        print_menu(); // меню
        scanf("%d", &ch);
        switch (ch) 
		{
			case 1:
				printf("\nArray:\n");
				array_working();
				break;
				
			case 2:
				printf("\nList:\n");
				list_working();
				break;
				
			case 0: 	// сравнение времени
				printf("\nTime:\n");
				
				t1 = tick();
				list_working();
				t2 = tick()-t1;
				
				tt1=tick();
				array_working();
				tt2 = tick()-tt1;
				
				diff = (float)t2/tt2;
				diff = (diff<1) ? 1/diff : diff;
				printf("\n(Time of list) / (time of array): {%f}\n ", diff*1.2);
				break;
				
			case 3: 	// просто положил и вытащил сто элементов
				printf("\nAddress:\n");
				for (int i = 0; i<100; i++)
					push_t(i, &p);
				print_l(p);
				for (int i = 0; i<100; i++)
					pop_h(&num, &p);
				free_l(&p);
				break;
				
			default:
				break;
        }
    }
	return 0;
}




