#ifndef STRING_MY_H
#define STRING_MY_H

#include <stdio.h>
#include <stdlib.h>

int strlen_my(const char* str);                    // ОК

char* strcpy_my_why(const char* tmp);              // ОК

char* strncpy_my_why(const char* tmp, int mlen);   // ОК

int or_strcmp(const char* a, const char* b);       // ОК

int str_in_pos(const char* str, const char* mask);

int char_in_str(const char* mask, char ch);

char* get_word_from_str_bg(char* pnt, char** word, const char* mask);

#endif // STRING_MY_H