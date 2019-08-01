#include "my_strspn.h"

size_t my_strspn(const char *str, const char *sym)
{
	int i = 0;
	
	while (*(str+i) != '\0')
	{
		int j = 0;
		int cnt = 0;
		
		while (*(sym+j) != '\0')
		{
			if (*(str+i) == *(sym+j))
			{
				cnt++;
				break;
			}
			
			j++;
		}
		
		if (cnt == 0)
			break;
		
		i++;
	}
	
	return i;
}