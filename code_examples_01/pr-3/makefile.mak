main.exe : main.c my_strspn.c my_strspn.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o main.exe main.c my_strspn.c
	
clean:
	$(RM) *.o *.exe