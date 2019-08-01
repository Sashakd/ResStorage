# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic -ggdb

hash.exe : hash.o findtime.o usltree.o baltree.o
	$(CC) -o $@ $^
	
hash.o : hash.c findtime.h usltree.h baltree.h
	$(CC)  $(CFLAGS) -c $<
	
findtime.o : findtime.c findtime.h
	$(CC)  $(CFLAGS) -c $<
	
usltree.o : usltree.c usltree.h
	$(CC)  $(CFLAGS) -c $<
	
baltree.o : baltree.c baltree.h
	$(CC)  $(CFLAGS) -c $<
	
clean : 
	$(RM) *.o *.exe
