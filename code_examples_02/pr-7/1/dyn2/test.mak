test.exe : test.o arr.dll
	gcc test.o -L. -larr -o test.exe
	
test.o : test.c
	gcc -std=c99 -Wall -Werror -c test.c
	
arr.dll : arr_lib.c
	gcc -std=c99 -Wall -Werror -D ARR_EXPORTS -c arr_lib.c
	gcc -shared arr_lib.o -Wl,--subsystem,windows -o arr.dll
	
clean:
	del *.exe *.o *.dll