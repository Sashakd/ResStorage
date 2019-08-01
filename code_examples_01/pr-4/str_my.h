#ifndef STR_MY_H
#define STR_MY_H

#include <stdarg.h>
#include <stdlib.h>

/**
@brief Функция нахождения длины строки
@param s Строка
@return Длина строки
*/
int my_strlen(const char * s);

/**
@brief Функция вставки восьмеричного числа в строку
@detailed Получает целое типа int и записывает
в буфер str в виде восьмеричного насколько позволяет 
размер буфера n
@param str Строка (буфер для записи)
@param n   Размер буфера для записи
@param value целое типа int, для записи в восмьмеричной форме
@return Длина строки (буфера для записи)
*/
int restore_08_value(char *str, size_t n, int value);

/**
@brief Функция вставки строки
@detailed Получает строку и записывает в буфер str 
насколько позволяет размер буфера n
@param str Строка (буфер для записи)
@param n   Размер буфера для записи
@param value строка для записи в буфер
@return Длина строки (буфера для записи)
*/
int restore_STR_value(char *str, int n, char *value);

/**
@brief Функция, формирующая строку для печати.
@detailed Аналогична по действию функции sprintf, однако
результат записывает в буфер s насколько позволяет размер 
буфера n; ограничена по функционалу (доступно: %s %o);
при не соответствии спецификаторов в строке форматирования
аргументам функции, идущих после неё, ожидается неопределённое
поведение; не отслеживается.
@param str Строка (буфер для записи)
@param n   Размер буфера для записи
@param format Cтрока форматирования
@return Длина строки (буфера для записи)
*/
int my_snprintf(char *s, size_t n, const char *format, ... );

#endif  // STR_MY_H