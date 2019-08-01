test01.exe : test.c my_strspn.c my_strspn.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o test01.exe test.c my_strspn.c
	
clean:
	$(RM) *.o *.exe