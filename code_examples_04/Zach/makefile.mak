main.exe : main.c
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o main.exe main.c
	
clean : 
	cmd /C del *.o *.exe