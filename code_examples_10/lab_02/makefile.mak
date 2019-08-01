main.exe : changing.c changing.h read.c read.h sorting.c sorting.h structures.h main.c
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -g3 -o main.exe changing.c read.c sorting.c main.c
	
clean:
	$(RM) *.o *.exe