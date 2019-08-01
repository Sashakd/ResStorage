main.exe : main.c operations.c operations.h read.c read.h
	gcc -std=c99 -ggdb -g3 -Wall -Werror -pedantic -o main.exe main.c operations.c read.c 
	
clean:
	$(RM) *.o *.exe