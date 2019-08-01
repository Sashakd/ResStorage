main.exe : main.c tree_node.h tree_node.c tree_graphviz.h tree_graphviz.c read.h read.c balance.h balance.c
	gcc -std=c99 -pedantic -Wall -Werror -ggdb -o main.exe main.c tree_node.c tree_graphviz.c read.c balance.c
	
clean : 
	cmd /C del *.o *.exe