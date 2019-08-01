test02.exe : module_test02.c print_arr.c print_arr.h read_arr.c read_arr.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o test02.exe module_test02.c print_arr.c read_arr.c
	
clean:
	$(RM) *.o *.exe