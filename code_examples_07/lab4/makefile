lab4.exe : main.o test.o arr_queue.o queue.o
	gcc -o lab4.exe main.o test.o arr_queue.o queue.o
	
main.o : main.c test.h arr_queue.h queue.h
	gcc -std=c99 -Wall -Werror -pedantic -ggdb -c main.c
	
test.o : test.c test.h arr_queue.h queue.h
	gcc -std=c99 -Wall -Werror -pedantic -ggdb -c test.c
	
arr_queue.o : arr_queue.c arr_queue.h
	gcc -std=c99 -Wall -Werror -pedantic -ggdb -c arr_queue.c

queue.o : queue.c queue.h
	gcc -std=c99 -Wall -Werror -pedantic -ggdb -c queue.c
	
clean :
	rm *.o *.exe