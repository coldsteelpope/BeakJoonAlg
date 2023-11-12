#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int arr[10] = { 0, };
int dp[10] = { 0, };

void Solution(int N, int M, int index)
{
	if (index == M)
	{
		for (int i = 0; i < M; ++i)
			printf("%d ", dp[i]);
		printf("\n");
	}
	else
	{
		for (int num = 1; num <= N; ++num)
		{
			dp[index] = num;
			Solution(N, M, index + 1);
		}
	}
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	Solution(N, M, 0);
	return 0;
}