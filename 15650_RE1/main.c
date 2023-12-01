#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int g_selectedNums[8] = { 0, };

void Solution(int index, int startNum, int N, int M)
{
	if (index == M)
	{
		for (int i = 0; i < M; ++i)
		{
			printf("%d ", g_selectedNums[i]);
		}
		printf("\n");
		return;
	}
	else
	{
		for (int num = startNum; num <= N; ++num)
		{
			g_selectedNums[index] = num;
			Solution(index + 1, num + 1, N, M);
		}
	}
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	Solution(0, 1, N, M);
	return 0;
}