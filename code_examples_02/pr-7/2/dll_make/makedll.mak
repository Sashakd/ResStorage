arrx.dll : arrx.c arrx.h
	gcc -std=c99 -Wall -Werror -D EXAMPLE_EXPORTS -c arrx.c
	gcc -shared arrx.o -Wl,--subsystem,windows -o arrx.dll
	
clean :
	del *.exe *.o *.dll