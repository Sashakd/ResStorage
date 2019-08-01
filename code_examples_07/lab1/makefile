lab1.exe : main.o io_huge.o
	gcc -o lab1.exe main.o io_huge.o
	
main.o : main.c io_huge.h
	gcc -std=c99 -Wall -Werror -pedantic -ggdb -c main.c
	
io_huge.o : io_huge.c io_huge.h
	gcc -std=c99 -Wall -Werror -pedantic -ggdb -c io_huge.c
	
clean :
	rm *.o *.exe