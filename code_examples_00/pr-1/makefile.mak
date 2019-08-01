main.exe : main.c read_arr.c read_arr.h print_arr.c print_arr.h diff_numb.c diff_numb.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o main.exe main.c read_arr.c print_arr.c diff_numb.c
	
clean:
	$(RM) *.o *.exe