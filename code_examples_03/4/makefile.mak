# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

turn.exe : turn.o
	$(CC) -o $@ $^

turn.o : turn.c
	$(CC)  $(CFLAGS) -c $<
	
clean : 
	$(RM) *.o *.exe