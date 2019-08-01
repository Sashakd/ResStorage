arr.dll : arr_lib.c arr_lib.h
	gcc -std=c99 -Wall -Werror -c arr_lib.c
	gcc -shared arr_lib.o -Wl,--subsystem,windows -o arr.dll

clean:
	del *.exe *.o *.dll