#include "tree_graphviz.h"

void PrintTree(struct tree_node* T, FILE* f) // работает верно // <===
{
    if (T) 
	{ 
	    PrintTree(T->left, f);
		if (T->left != NULL)
		{
		    printf("%s -> %s;\n", T->data, T->left->data);
            fprintf(f, "%s -> %s;\n", T->data, T->left->data);
        }			
		if (T->right != NULL)
		{
		    printf("%s -> %s;\n", T->data, T->right->data);
            fprintf(f, "%s -> %s;\n", T->data, T->right->data);
		}
        PrintTree(T->right, f);
	}
}

int create_tree_graph(struct tree_node* root, const char* gv_name, const char* png_name)
{
    FILE* f;
	
	f = fopen(gv_name, "w");  // "out.gv"
	
	if (f)
	{
		fprintf(f, "digraph tree_create_result {\n");
		// печать дерева
		PrintTree(root, f);
		fprintf(f, "}");
		
		fclose(f);
		char* cmd_str;

		cmd_str = malloc((19 + strlen(gv_name) + strlen(png_name))*sizeof(char));

		if (cmd_str)    
		{
		    strcpy(cmd_str, "dot.exe ");
		    strcat(cmd_str, gv_name);
		    strcat(cmd_str, " -Tpng -o ");
		    strcat(cmd_str, png_name);
			*(cmd_str + 18 + strlen(gv_name) + strlen(png_name)) = '\0';
		
		
		    system(cmd_str);
            system(png_name);  // "graph.png"
			//system("CLS");
		
		    free(cmd_str);
		}
		else
            return 0;
		
		return 1;
	}
	else
	    return 0;
}