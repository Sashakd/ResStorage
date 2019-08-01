main.exe : graphbyp.c
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o main.exe graphbyp.c
	
clean : 
	cmd /C del *.o *.exe