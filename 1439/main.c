#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char str[1000001] = { 0, };

int GetMin(int a, int b) 
{
	return a > b ? b : a;
}

int main(void)
{
	scanf("%s", str);
	
	int strLen = strlen(str);

	if (strLen == 1)
	{
		printf("%d", 0);
	}
	else
	{
		int con_one = 0;
		int con_zero = 0;

		bool is_con_one = false;
		bool is_con_zero = false;

		for (int i = 0; i < strLen; ++i)
		{
			if (str[i] == '1' && is_con_one == false)
			{
				++con_one;
				is_con_one = true;
				is_con_zero = false;
			}
			else if (str[i] == '0' && is_con_zero == false)
			{
				++con_zero;
				is_con_zero = true;
				is_con_one = false;
			}
		}
		int answer = GetMin(con_one, con_zero);
		printf("%d", answer);
	}


	return 0;
}