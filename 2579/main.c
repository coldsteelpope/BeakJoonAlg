#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int stairs[301] = { 0, };
int dp[301] = { 0, };

int GetMax(int a, int b)
{
	return (a > b) ? a : b;
}

int main(void)
{
	int stairs_num = 0;
	scanf("%d", &stairs_num);

	for (int stairs_index = 1; stairs_index <= stairs_num; ++stairs_index)
	{
		scanf("%d", &stairs[stairs_index]);
	}

	dp[0] = 0;
	dp[1] = stairs[1];
	dp[2] = stairs[2] + stairs[1];

	for (int i = 3; i <= stairs_num; ++i)
	{
		dp[i] = stairs[i] + GetMax(dp[i - 3] + stairs[i - 1], dp[i - 2]);
	}

	printf("%d", dp[stairs_num]);
	return 0;
}