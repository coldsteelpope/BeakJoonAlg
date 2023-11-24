#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void Solution()
{
	int N;
	scanf("%d", &N);
	char str[64] = { 0, };
	char stack[64] = { 0, };
	scanf("%s", str);
	int stackPointer = 0;
	int strLen = strlen(str);
	
	for (int i = 0; i < strLen; ++i)
	{
		if (stackPointer == 0)
		{
			stack[stackPointer++] = str[i];
		}
		else
		{
			if (stack[stackPointer - 1] == '(' && str[i] == ')')
			{
				--stackPointer;
			}
			else
			{
				stack[stackPointer++] = str[i];
			}
		}
	}
	if (stackPointer == 0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; ++testCase)
	{
		Solution();
	}
	return 0;
}