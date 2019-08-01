test01.exe : module_test01.c print_arr.c print_arr.h diff_numb.c diff_numb.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o test01.exe module_test01.c print_arr.c diff_numb.c
	
clean:
	$(RM) *.o *.exe