#define _CRT_SECURE_NO_WARNINGS
#define INF		(~0U >> 2)
#define COLOR_NUM	3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dp[1001][COLOR_NUM + 1] = { 0 };
int input[1001][COLOR_NUM + 1] = { 0, };

int GetMin(int a, int b)
{
	return a > b ? b : a;
}

int main(void)
{	
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= COLOR_NUM; ++j)
			scanf("%d", &input[i][j]);
	
	dp[1][1] = input[1][1];
	dp[1][2] = input[1][2];
	dp[1][3] = input[1][3];

	for (int i = 2; i <= N; ++i)
	{
		dp[i][1] = GetMin(dp[i - 1][2], dp[i - 1][3]) + input[i][1];
		dp[i][2] = GetMin(dp[i - 1][1], dp[i - 1][3]) + input[i][2];
		dp[i][3] = GetMin(dp[i - 1][1], dp[i - 1][2]) + input[i][3];
	}

	int min_value = INF;
	for (int j = 1; j <= COLOR_NUM; ++j)
	{
		min_value = (dp[N][j] > min_value) ? min_value : dp[N][j];
	}

	printf("%d", min_value);
	return 0;
}