main.exe : main.c read_arr.c read_arr.h print_arr.c print_arr.h m_insert_sort.c m_insert_sort.h filt.c filt.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o main.exe main.c read_arr.c print_arr.c m_insert_sort.c filt.c
	
clean:
	$(RM) *.o *.exe