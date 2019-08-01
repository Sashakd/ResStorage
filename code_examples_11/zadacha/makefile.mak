main.exe : main.c read.c read.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o main.exe main.c read.c
	
clear :
	$(RM) *.o *.exe