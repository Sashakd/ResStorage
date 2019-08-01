# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

graphbyp.exe : graphbyp.o
	$(CC) -o $@ $^

graphbyp.o : graphbyp.c
	$(CC)  $(CFLAGS) -c $<
	
clean : 
	$(RM) *.o *.exe