#ifndef __INTERFACES_H__

#define __INTERFACES_H__

#include <string.h>

#include "list_stack.h"

#define BUF (120)

void main_menu();
void sub_menu();
int prior(char op);
int canPop(char op, char st_op);
char read_op(char** str_ptr);
int read_num(char** str_ptr);
int endline(char** str_ptr);

int task_list();
int a_task_list();

#endif