#include "matrix_gen.h"

int generate_rand_matrix(FILE* f, int r, int c, double percent)
{
	time_t t;
	
	srand((unsigned) time(&t));

	if ((r > 0) && (c > 0) && (percent > 0) && (percent <= 100))
	{
		// Обнуляем всю матрицу
		int* buff = calloc(r*c, sizeof(int));
		
		if (buff)
		{
			int need_cnt = abs(r*c*(percent/100.0)); // Округлить до первого
			
			if (need_cnt == 0)
				need_cnt = 1;
				
			fprintf(f, "r: %d c: %d\n", r, c);
			
			while (need_cnt > 0)
			{
				int q_i = 0;
				int q_j = 0;
				
				q_i = rand() % (r);
				q_j = rand() % (c);
				
				if (*(buff + q_i*c + q_j) == 0)
				{
                    *(buff + q_i*c + q_j) = 1 + rand() % 9;
					need_cnt--;
				}
			}
			
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
					fprintf(f, "%d ", *(buff + i*c + j));
				fprintf(f, "\n");
			}
			
			free(buff);
			
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}
