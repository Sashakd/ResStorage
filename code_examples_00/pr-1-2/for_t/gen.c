#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		FILE* f = NULL;
		int n = 0;
		int bf;
		
		f = fopen("OUTPUT.txt", "w");
		
		if (!f)
			return -1;
		
		srand(time(0));
		
		if ((strncmp(argv[1], "-drct", 5) == 0) || 
			(strncmp(argv[1], "-rvrs", 5) == 0) || 
			(strncmp(argv[1], "-rndm", 5) == 0))
		{
			printf("LEN: ");
			scanf("%d", &n);
			
			if (strncmp(argv[1], "-drct", 5) == 0)
				bf = 0;
				
			if (strncmp(argv[1], "-rvrs", 5) == 0)
				bf = n+1;
			
			for (int i = 0; i < n; i++)
			{
				if (strncmp(argv[1], "-drct", 5) == 0)
					bf++;
				
				if (strncmp(argv[1], "-rvrs", 5) == 0)
					bf--;
					
				if (strncmp(argv[1], "-rndm", 5) == 0)
					bf = -500 + rand() % 1001;
					
				fprintf(f, "%d ", bf);
			}
		}
		else
			printf("Arguments:	-drct -rvrs -rndm\n");
			
		fclose(f);
	}
	else
		printf("Help:\n	gen.exe (-arg)\n");
	
	return 0;
}