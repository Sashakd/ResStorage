uny.exe : main.c list.c list.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o uny.exe main.c list.c
	
clean:
	$(RM) *.o *.exe