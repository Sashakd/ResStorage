det_test.exe : determ_test.c ..\basic_matrix.c ..\basic_matrix.h ..\math_matrix.c ..\math_matrix.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -O0 -o det_test.exe determ_test.c ..\basic_matrix.c ..\math_matrix.c
	
clean:
	$(RM) *.o *.exe
