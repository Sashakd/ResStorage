main.exe : main.o
	gcc -o $@ $^

main.o : main.c
	gcc  -std=c99 -Wall -Werror -pedantic -ggdb -c $<
	
clean : 
	$(RM) *.o *.exe