t.exe : t.c time.c time.h ..\m_insert_sort.c ..\m_insert_sort.h ..\read_arr.c ..\read_arr.h ..\print_arr.c ..\print_arr.h
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o t.exe t.c time.c ..\m_insert_sort.c ..\read_arr.c ..\print_arr.c
	
clean:
	$(RM) *.o *.exe