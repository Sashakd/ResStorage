#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

double* init_q(int* len, const int mx_ln)
{
    double* buff = malloc(sizeof(double) * mx_ln);

    if (buff)  *len = 0;

    return buff;
}

void move_r_q(double* q, const int len) // <==========
{
    for (int i = 0; i < len; i++)
        q[i+1] = q[i];
}

int push_q(double* q, int* len, const int mx_ln, double tmp)
{
    if ((*len) < mx_ln)
    {
        move_r_q(q, *len);

        (*len)++;

        q[0] = tmp;

        return 1;
    }
    else
        return 0;
}

int pop_q(double* q, int* len, const int mx_ln, double tmp)
{
    if ((*len) > 0)
    {
        (*len)--;

        return 1;
    }
    else
        return 0;
}

int perc_perc(int* in_cnt, int* out_cnt, int* stayed, int* returned, int*r_fact)
{

}

int main()
{
    double* arr;
    int n;

    int za_cnt = 0;

    unsigned long long prev_t;
    unsigned long long time;
    double rem_in_t;
    double rem_out_t;
    int rev = 0;

    prev_t = tick();
    rem_in_t = rand()*8;
    rem_out_t = rand()*4;

    while (za_cnt < 1000)
    {
        time = tick();


        if ((prev_t + rem_in_t) >= time)
        {
            rem_in_t = rand()*8;

            if (push_q(arr, &n, MAX_LEN, prev_t + rem_in_t))
            {
                printf("-");
            }
            else
            {
                printf("FULL\n");
            }
        }

        rem_out_t = rand()*4;
        double a = tick() + rem_out_t;

        if (a >= time)
        {


            if (pop_q(arr, &n, MAX_LEN, a))
            {
                printf("-");
                za_cnt++;

                if (!rev)
                {
                    rev = 1;
                     if (push_q(arr, &n, MAX_LEN, prev_t + rem_in_t))
                     {

                     }
                     else
                     {

                     }
                }
                else
                    rev = 0;
            }
            else
            {
                printf("EMPTY\n");
            }
        }

        ////////////////


        ////////////////

        prev_t = time;
    }


    return 0;
}
