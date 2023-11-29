#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


char g_num[1000001] = { 0, };

int GetStrLen()
{
	int len = 0;
	while (g_num[len] != '\0')
	{
		++len;
	}
	return len;
}

int main(void)
{
	scanf("%s", g_num);
	
	char currentNum = g_num[0];
	int one_num = 0;
	int zero_num = 0;

	if (currentNum == '0')
	{
		++zero_num;
	}
	else
	{
		++one_num;
	}

	int N = GetStrLen();
	for (int i = 0; i < N; ++i)
	{
		if (currentNum == g_num[i])
		{
			continue;
		}
		if (g_num[i] == '0')
		{
			++zero_num;
		}
		else
		{
			++one_num;
		}
		currentNum = g_num[i];
	}

	int result = (one_num > zero_num) ? zero_num : one_num;
	printf("%d", result);
	return 0;
}