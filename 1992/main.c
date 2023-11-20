#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int boardMap[64][64] = { 0, };

void PrintBoardMap(int N);
void SetBoardMap(int N);

bool IsPureSquare(int startY, int startX, int targetY, int targetX)
{
	bool isPure = true;
	int firstValue = boardMap[startY][startX];
	for (int y = startY; y <= targetY; ++y)
	{
		for (int x = startX; x <= targetX; ++x)
		{
			if (firstValue != boardMap[y][x])
			{
				isPure = false;
				break;
			}
		}
		if (isPure == false)
		{
			break;
		}
	}
	return isPure;
}

void DFS(int startY, int startX, int targetY, int targetX, int N)
{
	if (startY == targetY && startX == targetX)
	{
		printf("%d", boardMap[startY][startX]);
		return;
	}

	bool isPure = IsPureSquare(startY, startX, targetY, targetX);
	if (isPure == true)
	{
		printf("%d", boardMap[startY][startX]);
		return;
	}

	printf("(");
	DFS(startY, startX, targetY - N, targetX - N, N / 2);
	DFS(startY, startX + N, targetY - N, targetX, N / 2);
	DFS(startY + N, startX, targetY, targetX - N, N / 2);
	DFS(startY + N, startX + N, targetY, targetX, N / 2);
	printf(")");
	return;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	SetBoardMap(N);
	
	DFS(0, 0, N - 1, N - 1, N / 2);
	return 0;
}

void PrintBoardMap(int N)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			printf("%d ", boardMap[y][x]);
		}
		printf("\n");
	}
}

void SetBoardMap(int N)
{
	char board[64][64] = { 0, };
	int height = N;
	for (int y = 0; y < N; ++y)
	{
		scanf("%s", board[y]);
	}
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			boardMap[y][x] = board[y][x] - '0';
		}
	}
}