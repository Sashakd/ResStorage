main.exe : main.c str_my.h str_my.c
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o main.exe main.c str_my.c
	
clean:
	del *.o *.exe