main.exe : main.c bnumb.c bnumb.h print_text.c print_text.h norm.c norm.h multiply.c multiply.h
	gcc -std=c99 -pedantic -Wall -Werror -o main.exe main.c bnumb.c print_text.c norm.c multiply.c
	
clean:
	$(RM) *.o *.exe