#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define MAX_LEN 21

int board[MAX_LEN][MAX_LEN] = { 0, };
int dp[MAX_LEN][MAX_LEN] = { 0, };

int GetMin(int num1, int num2)
{
	return num1 > num2 ? num2 : num1;
}

void SetBoard(int N)
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &board[i][j]);
		}
	}
}

bool IsPossible(int d1, int d2, int r, int c, int N)
{
	bool result1 = (r + d1 + d2 <= N);
	bool result2 = (1 <= c - d1);
	bool result3 = (c + d2 <= N);
	return (result1 == true) && (result2 == true) && (result3 == true);
}

void PrintDP(int N)
{
	printf("\n");
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int SplitArea(int currentR, int currentC, int d1, int d2, int N)
{
	for (int i = 0; i <= d1; ++i)
	{
		dp[currentR + i][currentC - i] = 5;
		dp[currentR + d2 + i][currentC + d2 - i] = 5;
	}

	for (int i = 0; i <= d2; ++i)
	{
		dp[currentR + i][currentC + i] = 5;
		dp[currentR + d1 + i][currentC - d1 + i] = 5;
	}
	
	for (int r = 1; r < currentR + d1; ++r)
	{
		for (int c = 1; c <= currentC; ++c)
		{
			if (dp[r][c] == 5)
				continue;

			if (r >= -c + (currentR + currentC))
				continue;
			
			dp[r][c] = 1;
		}
	}

	for (int r = 1; r <= currentR + d2; ++r)
	{
		for (int c = currentC + 1; c <= N; ++c)
		{
			if (dp[r][c] == 5)
				continue;
			
			if (r >= c + (currentR - currentC))
				continue;

			dp[r][c] = 2;
		}
	}

	for (int r = currentR + d1; r <= N; ++r)
	{
		for (int c = 1; c < currentC - d1 + d2; ++c)
		{
			if (dp[r][c] == 5)
				continue;
			
			if (r <= c + ((currentR + d1) - (currentC - d1)))
				continue;
			
			dp[r][c] = 3;
		}
	}

	for (int r = currentR + d2 + 1; r <= N; ++r)
	{
		for (int c = currentC - d1 + d2; c <= N; ++c)
		{
			if (dp[r][c] == 5)
				continue;

			if (r <= -c + ((currentR + d2) + (currentC + d2)))
			{
				continue;
			}

			dp[r][c] = 4;
		}
	}


	int scores[6] = { 0, };
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (dp[i][j] == 0)
				dp[i][j] = 5;
			
			scores[dp[i][j]] += board[i][j];
		}
	}

	int minValue = scores[1];
	int maxValue = scores[1];
	for (int i = 1; i <= 5; ++i)
	{
		minValue = (minValue > scores[i]) ? scores[i] : minValue;
		maxValue = (maxValue > scores[i]) ? maxValue : scores[i];
	}
	
	int diff = maxValue - minValue;
	//PrintDP(N);
	//printf("diff: %d\n\n", diff);

	memset(dp, 0, sizeof(dp));
	return diff;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	SetBoard(N);

	int answer = (~0U >> 2);
	for (int d1 = 1; d1 <= N; ++d1)
	{
		for (int d2 = 1; d2 <= N; ++d2)
		{
			for (int r = 1; r <= N; ++r)
			{
				for (int c = 1; c <= N; ++c)
				{
					if (IsPossible(d1, d2, r, c, N) == true)
					{
						int minValue = SplitArea(r, c, d1, d2, N);
						answer = (answer > minValue) ? minValue : answer;
					}
				}
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}