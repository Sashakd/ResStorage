lab3.exe : main.o list_stack.o interfaces.o
	gcc -o lab3.exe main.o list_stack.o interfaces.o
	
main.o : main.c list_stack.h interfaces.h
	gcc -std=c99 -Wall -Werror -pedantic -ggdb -c main.c
	
interfaces.o : interfaces.c interfaces.h list_stack.h
	gcc -std=c99 -Wall -Werror -pedantic -ggdb -c interfaces.c
	
list_stack.o : list_stack.c list_stack.h interfaces.h
	gcc -std=c99 -Wall -Werror -pedantic -ggdb -c  list_stack.c
	
clean :
	rm *.o *.exe