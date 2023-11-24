#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board [64][64] = { 0, };

void SetBoard(int N);
void PrintBoard(int N);

void DFS(int startY, int startX, int N)
{
	char currentValue = board[startY][startX];
	for (int i = startY; i < startY + N; ++i)
	{
		for (int j = startX; j < startX + N; ++j)
		{
			if (currentValue != board[i][j])
			{
				printf("(");
				DFS(startY, startX, N / 2);
				DFS(startY, startX + N / 2, N / 2);
				DFS(startY + N / 2, startX, N / 2);
				DFS(startY + N / 2, startX + N / 2, N / 2);
				printf(")");
				return;
			}
		}
	}
	printf("%c", currentValue);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	SetBoard(N);
	DFS(0, 0, N);
	return 0;
}

void SetBoard(int N)
{
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", board[i]);
	}
}