test01.exe : test01.c ..\filt.c ..\filt.h ..\m_insert_sort.c ..\m_insert_sort.h ..\print_arr.c ..\print_arr.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o test01.exe test01.c ..\filt.c ..\m_insert_sort.c ..\print_arr.c
	
clean:
	$(RM) *.o *.exe