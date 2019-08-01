test.exe : test.c libarr.a
	gcc -std=c99 -Wall -Werror test.c libarr.a -o test.exe

arr_lib.o : arr_lib.c arr_lib.h
	gcc -std=c99 -Wall -Werror -c arr_lib.c

libarr.a : arr_lib.o
	ar rc libarr.a arr_lib.o
	ranlib libarr.a

clean:
	del *.exe *.o *.a