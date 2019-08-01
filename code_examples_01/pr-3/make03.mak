test2.exe : test2.c my_strndup.c my_strndup.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o test2.exe test2.c my_strndup.c
	
clean:
	$(RM) *.o *.exe