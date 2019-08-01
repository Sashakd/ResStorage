#ifndef __TEST_H__
#define __TEST_H__

#include <stdio.h>
#include "queue.h"
#include "arr_queue.h"

void test_a();
void test_s();

void print_menu(); //
void print_new_results(int *num_out, float *tin1, float *tout1, int *sub, int *info, int works); //
void list_working(); // 
float do_this_time_l(float tr, struct l_queue **o1, int *num_out, float *tin1, 
								float *tout1, int *sub, int *info, int *works, int *i); //
void array_working(); //
float do_this_time_a(float tr, struct a_queue **o1, int *num_out, float *tin1, 
								float *tout1, int *sub, int *info, int *works, int *i);

#endif
