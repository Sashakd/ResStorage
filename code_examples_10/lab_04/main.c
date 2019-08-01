#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "structures.h"
#include "operations.h"

static const int COUNT_GONE = 1000;
static const int COUNT_ANALYSE = 100;

int main()
{
	FILE *f;

    struct elm *head = NULL; // список

	struct adress *add = NULL; // список добавленных элементов
	struct adress *del = NULL; // список удалённых элементов
    
	float head_mas[3000][2]; // массив

    int count = 0; // длина масива

    unsigned long long time_before = 0; // переменные для измерения времени
    unsigned long long time_after = 0;
    unsigned long long my_time_list = 0; // количество тактов на моделирование списком
    unsigned long long my_time_array = 0; // количество тактов на моделирование массивом

    float T1; // время прихода заявки первого типа
    float T2; // время обслуживания заявки первого типа
    float T3; // время обслуживания заявки второго типа
    float minT1 = 0; /* диапазон времени прихода */
    float maxT1 = 5; /* заявок первого типа ******/
    float minT2 = 0; /* диапазон времени обслуживания */
    float maxT2 = 4; /* заявок первого типа ***********/
    float minT3 = 0; /* диапазон времени обслуживания */
    float maxT3 = 4; /* заявок второго типа ***********/
    float cur_time = 0; // текущее время
    int count_serv1 = 0; // количество обслуженных заявок первого типа
    int flag = 0; // признак нахождения заявки второго типа в очереди
    int count_2 = 0; // количество обращений заявок второго типа
    float time_wait_all = 0; // время простоя аппарата
    int count_in = 0; // количество вошедших заявок первого типа
    int count_out = 0; // количество вышедших заявок первого типа
    int c_100 = 0; // количество сотен обработанных заявок
    int mid_length = 0; // средняя длина очереди
    int sum = 0; // сумма всех длин очередей после каждой обработанной сотни

    srand(time(NULL));



    /*for (int i = 0; i < 10; i++) // тестирование операций работы с очередью для массива
    {
        T3 = (float) rand() / RAND_MAX * (maxT3 - minT3) + minT3;
        push_end_mas(head_mas, &count, T3, 1);
    }
    view_mas(head_mas, count);
    push_4_mas(head_mas, &count, 1000);
    printf("\n\n");
    view_mas(head_mas, count);
    pop_mas(head_mas, &count);
    printf("\n\n");
    view_mas(head_mas, count);
    pop_mas(head_mas, &count);
    printf("\n\n");
    view_mas(head_mas, count);


    printf("\n\n\n");*/

    printf("******************   LIST MODELING   **********************\n\n");

    T3 = (float) rand() / RAND_MAX * (maxT3 - minT3) + minT3; // Заявка второго типа проходит через ОА и оставляет пустую очередь
    cur_time += T3;                                           //

    while (count_serv1 < COUNT_GONE)
    {
        __asm__ __volatile__ ("rdtsc" : "=A" (time_before));
        T1 = (float) rand() / RAND_MAX * (maxT1 - minT1) + minT1; // заявка первого типа поступает в очередь
        if (head == NULL)                                         //
            push_end(&head, T1, 1);                               //
        else                                                      //
            push_end(&head, last_time(head) + T1, 1);             //
        count_in++;
		__asm__ __volatile__ ("rdtsc" : "=A" (time_after));
		my_time_list = my_time_list + time_after - time_before;
		push_end_adress(&add, last_adress(head)); //*********************
		__asm__ __volatile__ ("rdtsc" : "=A" (time_before));
                                                                  //
        if (!flag)                                                // если заявка второго типа не в очереди, то она обслуживается в ОА до тех пор, пока не наступит время заявки первого типа
        {                                                         // после чего заявка вторго типа становится в очередь
            while (cur_time < head->numb)                         //
            {                                                     //
                T3 = (float) rand() / RAND_MAX * (maxT3 - minT3) + minT3; //
                cur_time += T3;                                           //
                count_2++;
            }                                                             //
            if (length(head) < 4)                                         //
                push_end(&head, 0, 2);                      //
            else                                                          //
                push_4(head, 0);                            //
            flag = 1;
			__asm__ __volatile__ ("rdtsc" : "=A" (time_after));
			my_time_list = my_time_list + time_after - time_before;
			push_end_adress(&add, last_adress(head)); //*******************************
			__asm__ __volatile__ ("rdtsc" : "=A" (time_before));
        }
		if (cur_time - last_time(head) > maxT1)
		{
			T1 = (float) rand() / RAND_MAX * (maxT1 - minT1) + minT1;
			push_end(&head, last_time(head) + T1, 1);
			count_in++;
		}
                                                                 //
        if (cur_time >= head->numb)                                       //  если подошло время заявки из очереди, то её вытаскивают и обрабатывают
        {                                                                 //
            if (head->type == 1)                                          //
            {                                                             //
                T2 = (float) rand() / RAND_MAX * (maxT2 - minT2) + minT2; //
                cur_time += T2;
                count_out++;//
                count_serv1++;                                            //                                           //
            }                                                             //
            else                                                          //
            {                                                             //
                flag = 0;                                                 //
                T3 = (float) rand() / RAND_MAX * (maxT3 - minT3) + minT3; //
                cur_time += T3;                                           //
                count_2++;
            }                                                             //
            pop(&head); 
			__asm__ __volatile__ ("rdtsc" : "=A" (time_after));
			my_time_list = my_time_list + time_after - time_before;
			push_end_adress(&del, head); //**********************************
			__asm__ __volatile__ ("rdtsc" : "=A" (time_before));
			if (cur_time - last_time(head) > maxT1)
			{
				T1 = (float) rand() / RAND_MAX * (maxT1 - minT1) + minT1;
				push_end(&head, last_time(head) + T1, 1);
				count_in++;
			}
        }                                                                 //
        else                                                              // в другом случае аппарат ждёт заявки из очереди
        {
            time_wait_all += head->numb - cur_time;
            cur_time = head->numb;
        }
        __asm__ __volatile__ ("rdtsc" : "=A" (time_after));
        my_time_list = my_time_list + time_after - time_before;
        if (count_serv1 % 100 == 0 && flag == 1)                          // вывод результатов при достижении каждой сотни обработанных элементов
        {
            printf("*** Served requests = %d ***\n\n", count_serv1);
            printf("current length = %d\n", length(head));
            c_100++;
            sum += length(head);
            mid_length = sum / c_100;
            printf("mid length = %d\n", mid_length);
            printf("requests in = %d\n", count_in);
            printf("requests out = %d\n\n", count_out);
        }
    }
    printf("*** Total information ***\n\n");                         // итоговый вывод
    printf("Time of modeling: %f\n", cur_time);
    printf("Count of requests of 2'nd type: %d\n", count_2);
    printf("Time of machine waiting: %f\n", time_wait_all);
    printf("Count of entering requests of 1'st type: %d\n", count_in);
    printf("Count of served requests of 1'st type %d\n\n\n", count_out);

    printf("******************   ARRAY MODELING   **********************\n\n");


    T1 = 0; // время прихода заявки первого типа
    T2 = 0; // время обслуживания заявки первого типа
    T3 = 0; // время обслуживания заявки второго типа
    minT1 = 0; /* диапазон времени прихода */
    maxT1 = 5; /* заявок первого типа ******/
    minT2 = 0; /* диапазон времени обслуживания */
    maxT2 = 4; /* заявок первого типа ***********/
    minT3 = 0; /* диапазон времени обслуживания */
    maxT3 = 4; /* заявок второго типа ***********/
    cur_time = 0; // текущее время
    count_serv1 = 0; // количество обслуженных заявок первого типа
    flag = 0; // признак нахождения заявки второго типа в очереди
    count_2 = 0; // количество обращений заявок второго типа
    time_wait_all = 0; // время простоя аппарата
    count_in = 0; // количество вошедших заявок первого типа
    count_out = 0; // количество вышедших заявок первого типа
    c_100 = 0; // количество сотен обработанных заявок
    mid_length = 0; // средняя длина очереди
    sum = 0; // сумма всех длин очередей после каждой обработанной сотни

    free(head);
    head = NULL;


    T3 = (float) rand() / RAND_MAX * (maxT3 - minT3) + minT3; // Заявка второго типа проходит через ОА и оставляет пустую очередь
    cur_time += T3;                                           //

    while (count_serv1 < COUNT_GONE)
    {
        __asm__ __volatile__ ("rdtsc" : "=A" (time_before));
        T1 = (float) rand() / RAND_MAX * (maxT1 - minT1) + minT1; // заявка первого типа поступает в очередь
        if (/*head == NULL*/ count == 0)                                         //
            //push_end(&head, T1, 1);                               //
            push_end_mas(head_mas, &count, T1, 1);
        else                                                      //
            //push_end(&head, last_time(head) + T1, 1);             //
            push_end_mas(head_mas, &count, head_mas[count - 1][0] + T1, 1);
        count_in++;
                                                                  //
        if (!flag)                                                // если заявка второго типа не в очереди, то она обслуживается в ОА до тех пор, пока не наступит время заявки первого типа
        {                                                         // после чего заявка вторго типа становится в очередь
            while (cur_time < /*head->numb*/ head_mas[0][0])                         //
            {                                                     //
                T3 = (float) rand() / RAND_MAX * (maxT3 - minT3) + minT3; //
                cur_time += T3;                                           //
                count_2++;
            }                                                             //
            if (/*length(head)*/ count < 4)                                         //
                //push_end(&head, 0, 2);                      //
                push_end_mas(head_mas, &count, 0, 2);
            else                                                          //
                //push_4(head, 0);                            //
                push_4_mas(head_mas, &count, 0);
            flag = 1;                                                     //
        }

		if (cur_time - /*last_time(head)*/ head_mas[count - 1][0] > maxT1)
		{
			T1 = (float) rand() / RAND_MAX * (maxT1 - minT1) + minT1;
			push_end_mas(head_mas, &count, head_mas[count - 1][0] + T1, 1);
			count_in++;
		}//

        if (cur_time >= /*head->numb*/ head_mas[0][0])                                       //  если подошло время заявки из очереди, то её вытаскивают и обрабатывают
        {                                                                 //
            if (/*head->type*/ head_mas[0][1] == 1)                                          //
            {                                                             //
                T2 = (float) rand() / RAND_MAX * (maxT2 - minT2) + minT2; //
                cur_time += T2;
                count_out++;//
                count_serv1++;                                            //                                           //
            }                                                             //
            else                                                          //
            {                                                             //
                flag = 0;                                                 //
                T3 = (float) rand() / RAND_MAX * (maxT3 - minT3) + minT3; //
                cur_time += T3;                                           //
                count_2++;
            }                                                             //
            /*pop(&head);*/ pop_mas(head_mas, &count); //
			if (cur_time - /*last_time(head)*/ head_mas[count - 1][0] > maxT1)
			{
				T1 = (float) rand() / RAND_MAX * (maxT1 - minT1) + minT1;
				push_end_mas(head_mas, &count, head_mas[count - 1][0] + T1, 1);
				count_in++;
			}//

        }                                                                 //
        else                                                              // в другом случае аппарат ждёт заявки из очереди
        {
            time_wait_all += /*head->numb*/ head_mas[0][0] - cur_time;
            cur_time = /*head->numb*/ head_mas[0][0];
        }
        __asm__ __volatile__ ("rdtsc" : "=A" (time_after));
        my_time_array = my_time_array + time_after - time_before;
        if (count_serv1 % 100 == 0 && flag == 1)                          // вывод результатов при достижении каждой сотни обработанных элементов
        {
            printf("*** Served requests = %d ***\n\n", count_serv1);
            printf("current length = %d\n", count);
            c_100++;
            sum += count;
            mid_length = sum / c_100;
            printf("mid length = %d\n", mid_length);
            printf("requests in = %d\n", count_in);
            printf("requests out = %d\n\n", count_out);
        }
    }
    printf("*** Total information ***\n\n");                         // итоговый вывод
    printf("Time of modeling: %f\n", cur_time);
    printf("Count of requests of 2'nd type: %d\n", count_2);
    printf("Time of machine waiting: %f\n", time_wait_all);
    printf("Count of entering requests of 1'st type: %d\n", count_in);
    printf("Count of served requests of 1'st type %d\n", count_out);

    printf("\nCount of tacts of LIST MODELING:  %llu\n", my_time_list); // вывод времени
    printf("\nCount of tacts of ARRAY MODELING: %llu\n", my_time_array);

	printf("\n\n\n");

	f = fopen("out.txt", "w");
	//fprintf(f, "%d", 2);
	view_adress(add, del, f);
    fclose(f);
    getchar();
    return 0;
}
