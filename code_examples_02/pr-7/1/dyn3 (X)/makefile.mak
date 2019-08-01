main.exe : main.c
	gcc -std=c99 -Wall -Werror -c main.c
	gcc main.o -L. -larr -o main.exe

clean:
	del *.exe *.o *.dll