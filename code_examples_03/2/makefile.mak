# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic -ggdb

main.exe : main.o
	$(CC) -o $@ $^

main.o : main.c
	$(CC)  $(CFLAGS) -c $<
	
clean : 
	$(RM) *.o *.exe