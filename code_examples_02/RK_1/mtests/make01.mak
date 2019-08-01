main.exe : main.c string_my.c string_my.h list_el.c list_el.h
	gcc -std=c99 -Wall -Werror -pedantic -o main.exe main.c string_my.c list_el.c
	
clean:
	$(RM) *.o *.exe