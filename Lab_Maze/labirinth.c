#include <stdio.h>
#include <stdlib.h>
#include "maze_rdy.h"

const int MAX_SZ = 1000; // при обработке "стены" занулить (NULL)

int main()
{
    FILE* f;
	
	f = fopen("a.txt", "r");
	
	if (f)
	{
	    int h, w;
		
        if (check_maze_file(f)) // check_maze_file(f)
		{
            int *arr;
			
            arr = get_maze_arr(f, &h, &w, MAX_SZ);

            get_maze_arr(f, &h, &w, MAX_SZ);

            if (arr)
            {
                printf("height = %d\n", h);
                printf("width  = %d\n", w);
			
                print_maze(arr, h, w);

                /*
                printf("Gets 1-4: %d\n", get_value_arr(arr, 0, 4, w));
                printf("Gets 5-5: %d\n", get_value_arr(arr, 5, 5, w));
                printf("Gets 5-5: %d\n", get_value_arr(arr, 5, 4, w));
                printf("Gets 5-5: %d\n", get_value_arr(arr, 4, 5, w));
                printf("Gets 4-1: %d\n", get_value_arr(arr, 4, 0, w));
                printf("Gets 3-9: %d\n", get_value_arr(arr, 3, 9, w));
                */

                /*
                for (int i = 0; i < 7; i++)
                {
                    for (int j = 0; j < 7; j++)
                    {
                        printf("Gets %d-%d: %d\n", i, j, get_value_arr(arr, i, j, w));
                    }
                }
                */

                free(arr);
            }
            else
                printf("Wrong array.\n");
		}
		else
		    printf("Error. Wrong size.\n");
		
		fclose(f);
	}
	else
	    printf("Error. Could not open [a.txt]\n");
	
	return 0;
}
