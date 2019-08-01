test.exe : test.c
	gcc -std=c99 -Wall -Werror -c test.c
	gcc test.o -L. -larr -o test.exe

clean:
	del *.exe *.o *.a *.dll