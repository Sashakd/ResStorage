main.exe : main.c fib.c fib.h read.c read.h dfnd.h
	gcc -std=c99 -o main.exe main.c fib.c read.c
	
clean:
	$(RM) *.o *.exe