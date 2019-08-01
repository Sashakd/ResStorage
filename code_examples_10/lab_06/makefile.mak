#ifeq ($(mode), debug)
#	CFLAGS += -g3
#endif

#ifeq ($(mode), release)
#	CFLAGS += -DNDEBUG -g0
#endif

main.exe : operations.c operations.h read.c read.h main.c
	gcc -std=c99 -std=c99 -ggdb -g3 -Wall -Werror -pedantic -o main.exe operations.c read.c main.c
	
clean:
	$(RM) *.o *.exe