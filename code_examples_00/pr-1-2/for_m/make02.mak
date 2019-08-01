test02.exe : test02.c ..\m_insert_sort.c ..\m_insert_sort.h ..\print_arr.c ..\print_arr.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o test02.exe test02.c ..\m_insert_sort.c ..\print_arr.c
	
clean:
	$(RM) *.o *.exe