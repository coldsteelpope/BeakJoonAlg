#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char infix[20] = {0,};
char g_ops[3] = { ' ', '+', '-' };

void Solution(int N, int num, int index)
{
	infix[index] = num + '0';
	if (num == N)
	{
		infix[index + 1] = '\0';
		
		int infixStrLen = strlen(infix);
		char noSpaceInfix[20] = { 0, };
		int noSpaceInfixPointer = 0;
		for (int i = 0; i < infixStrLen; ++i)
		{
			if (infix[i] == ' ')
			{
				continue;
			}
			noSpaceInfix[noSpaceInfixPointer++] = infix[i];
		}
		noSpaceInfix[noSpaceInfixPointer] = '\0';
		
		char container_nums[10][10] = { 0, };
		char container_ops[10] = { 0, };
		
		int container_nums_i = 0;
		int container_nums_inner_i = 0;
		int container_ops_i = 0;

		int tempIdx = 0;
		while (tempIdx < noSpaceInfixPointer)
		{
			if (noSpaceInfix[tempIdx] != '+' && noSpaceInfix[tempIdx] != '-')
			{
				container_nums[container_nums_i][container_nums_inner_i++] = noSpaceInfix[tempIdx];
			}
			else
			{
				container_nums[container_nums_i][container_nums_inner_i] = '\0';
				++container_nums_i;
				container_nums_inner_i = 0;
				container_ops[container_ops_i++] = noSpaceInfix[tempIdx];
			}
			++tempIdx;
		}


		int beforeValue = atoi(container_nums[0]);
		for (int i = 0; i < container_ops_i; ++i)
		{
			int value = atoi(container_nums[i + 1]);
			if (container_ops[i] == '+')
			{
				beforeValue += value;
			}
			else if (container_ops[i] == '-')
			{
				beforeValue -= value;
			}
		}

		if (beforeValue == 0)
		{
			printf("%s\n", infix);
		}
		return;
	}
	else
	{
		for (int op_i = 0; op_i < 3; ++op_i)
		{
			infix[index + 1] = g_ops[op_i];
			Solution(N, num + 1, index + 2);
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; ++testCase)
	{
		int N;
		scanf("%d", &N);
		Solution(N, 1, 0);
		printf("\n");
	}
}