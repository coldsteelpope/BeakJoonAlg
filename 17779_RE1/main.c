/*
참고 영상
https://www.youtube.com/watch?v=e65okXmqtv8
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 실제 board
int board[21][21] = { 0, };



void SetBoard(int N)
{
	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= N; ++c)
		{
			scanf("%d", &board[r][c]);
		}
	}
}

void PrintBoardIdx(int N, int boardIdx[][21])
{
	printf("\n");
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			printf("%d ", boardIdx[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
	{
		return -1;
	}
	else if (*(int*)first < *(int*)second)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int SetBoardIdx(int current_r, int current_c, int d1, int d2, int N)
{
	// 인덱스를 위한 board
	int boardIdx[21][21] = { 0, };

	for (int i = 0; i <= d1; ++i)
	{
		boardIdx[current_r + i][current_c - i] = 5;
		boardIdx[current_r + d2 + i][current_c + d2 - i] = 5;
	}

	for (int i = 0; i <= d2; ++i)
	{
		boardIdx[current_r + i][current_c + i] = 5;
		boardIdx[current_r + d1 + i][current_c - d1 + i] = 5;
	}

	// 1 사분면
	// 직선 방정식을 활용해 구역을 나눈다.
	for (int r = 1; r < current_r + d1; ++r)
	{
		for (int c = 1; c <= current_c; ++c)
		{
			if (boardIdx[r][c] == 5)
			{
				continue;
			}

			if (r >= (-1 * c) + (current_r + current_c))
			{
				continue;
			}

			boardIdx[r][c] = 1;
		}
	}

	// 2 사분면
	for (int r = 1; r <= current_r + d2; ++r)
	{
		for (int c = current_c + 1; c <= N; ++c)
		{
			if (boardIdx[r][c] == 5)
			{
				continue;
			}
			
			if (r >= c + (current_r - current_c))
			{
				continue;
			}

			boardIdx[r][c] = 2;
		}
	}

	// 3 사분면
	for (int r = current_r + d1; r <= N; ++r)
	{
		for (int c = 1; c <= current_c - d1 + d2; ++c)
		{
			if (boardIdx[r][c] == 5)
			{
				continue;
			}
			
			if (r <= c + ((current_r + d1) - (current_c - d1)))
			{
				continue;
			}
			boardIdx[r][c] = 3;
		}
	}

	// 4 사분면
	for (int r = current_r + d2 + 1; r <= N; ++r)
	{
		for (int c = current_c - d1 + d2; c <= N; ++c)
		{
			if (boardIdx[r][c] == 5)
			{
				continue;
			}
			
			if (r <= (-1 * c) + ((current_r + d2) + (current_c + d2)))
			{
				continue;
			}
			boardIdx[r][c] = 4;
		}
	}

	int population[6] = { 0, };
	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= N; ++c)
		{
			int idx = boardIdx[r][c];
			if (idx == 0)
				idx = 5;
			population[idx] += board[r][c];
		}
	}
	
	int maxVal = population[1];
	int minVal = population[1];
	for (int i = 1; i <= 5; ++i)
	{
		maxVal = (maxVal < population[i]) ? population[i] : maxVal;
		minVal = (minVal > population[i]) ? population[i] : minVal;
	}

	//PrintBoardIdx(N, boardIdx);
	return maxVal - minVal;
}

bool IsPossible(int r, int c, int d1, int d2, int N)
{
	bool firstCondition = (r + d1 + d2 <= N);
	bool secondCondition = (1 <= c - d1);
	bool thirdCondition = (c + d2 <= N);
	return (firstCondition == true) && (secondCondition == true) && (thirdCondition == true);
}

int GetMin(int a, int b)
{
	return a > b ? b : a;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	SetBoard(N);

	int minDiff = (~0U >> 2);
	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= N; ++c)
		{
			for (int d1 = 1; d1 <= N; ++d1)
			{
				for (int d2 = 1; d2 <= N; ++d2)
				{
					if (IsPossible(r, c, d1, d2, N))
					{
						int result = SetBoardIdx(r, c, d1, d2, N);
						minDiff = GetMin(minDiff, result);
					}
				}
			}
		}
	}
	printf("%d", minDiff);
	return 0;
}