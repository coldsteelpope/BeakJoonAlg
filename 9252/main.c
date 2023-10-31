#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int dp[1001][1001] = { 0, };

inline int GetMax(int a, int b)
{
	return a >= b ? a : b;
}

int LCS(char* str1, char* str2, int i, int j)
{
	for (int m = 0; m <= i; ++m)
		dp[m][0] = 0;
	for (int n = 0; n <= j; ++n)
		dp[0][n] = 0;

	for (int m = 1; m <= i; ++m)
	{
		for (int n = 1; n <= j; ++n)
		{
			if (str1[m - 1] == str2[n - 1])
			{
				dp[m][n] = dp[m - 1][n - 1] + 1;
			}
			else
			{
				//dp[m][n] = GetMax(dp[i][j - 1], dp[i - 1][j]);
				if (dp[m][n - 1] >= dp[m - 1][n])
					dp[m][n] = dp[m][n - 1];
				else
					dp[m][n] = dp[m - 1][n];
				//dp[i][j] = GetMax(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	return dp[i][j];
}

void TraceBack(char* str1, char* str2, int m, int n, char* LCS)
{
	if (m == 0 || n == 0)
		return;
	
	if
	(
		dp[m][n] > dp[m][n - 1] &&
		dp[m][n] > dp[m - 1][n] &&
		dp[m][n] > dp[m - 1][n - 1]
		//dp[i][j] > dp[i - 1][j - 1] &&
		//dp[i][j] > dp[i - 1][j] &&
		//dp[i][j] > dp[i][j - 1]
	)
	{
		char TempLCS[1001];
		strcpy(TempLCS, LCS);
		sprintf(LCS, "%c%s", str1[m - 1], TempLCS);

		TraceBack(str1, str2, m - 1, n - 1, LCS);
	}
	else if(
		//dp[i][j] == dp[i][j - 1] && dp[i][j] > dp[i - 1][j]
		dp[m][n] > dp[m - 1][n] &&
		dp[m][n] == dp[m][n - 1]
	)
	{
		TraceBack(str1, str2, m, n - 1, LCS);
	}
	else
	{
		TraceBack(str1, str2, m - 1, n, LCS);
	}
}

void PrintDP(int str1Len, int str2Len)
{
	printf("\n");
	for (int i = 0; i <= str1Len; ++i)
	{
		for (int j = 0; j <= str2Len; ++j)
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	char str1[1001] = { 0, };
	char str2[1001] = { 0, };
	scanf("%s", str1);
	scanf("%s", str2);
	//gets(str1);
	//gets(str2);
	
	int str1Len = strlen(str1);
	int str2Len = strlen(str2);

	int LCS_LEN = LCS(str1, str2, str1Len, str2Len);
	//int LCS_LEN = dp[str1Len][str2Len];
	//PrintDP(str1Len, str2Len);

	char result[1001] = { 0, };
	TraceBack(str1, str2, str1Len, str2Len, result);

	printf("%d\n", LCS_LEN);
	printf("%s\n", result);
	return 0;
}