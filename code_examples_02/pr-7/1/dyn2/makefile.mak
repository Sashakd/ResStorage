main.exe : main.o arr.dll
	gcc main.o -L. -larr -o main.exe
	
main.o : main.c
	gcc -std=c99 -Wall -Werror -c main.c
	
arr.dll : arr_lib.c
	gcc -std=c99 -Wall -Werror -D ARR_EXPORTS -c arr_lib.c
	gcc -shared arr_lib.o -Wl,--subsystem,windows -o arr.dll
	
clean:
	del *.exe *.o *.dll