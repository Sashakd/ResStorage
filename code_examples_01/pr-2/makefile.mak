Det.exe : main.c
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o Det.exe main.c 
	
clean:
	$(RM) *.o *.exe