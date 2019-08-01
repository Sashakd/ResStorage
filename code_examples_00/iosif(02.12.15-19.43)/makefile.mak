main.exe : main.c
	gcc -std=c99 -Wall -Werror -pedantic -ggdb -o main.exe main.c
	
clean:
	$(RM) *.o *.exe