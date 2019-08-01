#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insert(char *str, char* sub_str, int start, char *str_res, int res_len)
{
	int len_str = strlen(str);
	int len_sub = strlen(sub_str);
	int len_rln = len_str + len_sub + 1;
	
	if ((len_rln <= res_len) && (start <= len_str+1) && (start > 0))
	{
		memmove(str_res, str, start-1);
		memmove(str_res + start-1, sub_str, len_sub);
		memmove(str_res + start + len_sub-1, str + start-1, len_str - start+1);
		memmove(str_res + len_str + len_sub, "\0", 1);
	}
	else
		return 0;
	
	return len_rln;
}

int main()
{
	char str1[] = "ABNCMDKF"; // 8
	//char str1[] = "";
	char str2[] = "12346789901222"; // 15
	//char str2[] = "";
	char str3[23] = {'\0'};
	int len = 0;
	
	len = insert(str1, str2, 2, str3, 23);
	printf("[%s] len = %d", str3, len);
	
	return 0;
}