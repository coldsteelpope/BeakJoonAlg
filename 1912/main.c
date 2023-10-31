#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int num[100001] = { 0, };
int dp[100001] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i)
		scanf("%d", &num[i]);
	dp[1] = num[1];
	int max_value = dp[1];
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = GetMax(num[i], dp[i - 1] + num[i]);
		max_value = (max_value > dp[i]) ? max_value : dp[i];
	}

	printf("%d", max_value);
	return 0;
}