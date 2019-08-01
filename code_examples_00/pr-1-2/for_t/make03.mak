gen.exe : gen.c
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o gen.exe gen.c
	
clean:
	$(RM) *.o *.exe