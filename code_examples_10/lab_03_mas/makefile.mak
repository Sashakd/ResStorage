main.exe : main.c operations.c operations.h
	gcc -std=c99 -ggdb -g3 -Wall -Werror -pedantic -o main.exe main.c operations.c

clean:
	$(RM) *.o *.exe