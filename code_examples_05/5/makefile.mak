main.exe : main.c matrix_gen.c matrix_gen.h array_matrix.c array_matrix.h struct_matrix.c struct_matrix.h time.c time.h
	gcc -std=c99 -pedantic -Werror -ggdb -o main.exe main.c matrix_gen.c array_matrix.c struct_matrix.c time.c
	
clean :
	$(RM) *.o *.exe