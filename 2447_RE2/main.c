#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 6561

char board[MAX_LEN][MAX_LEN] = { 0, };

void Draw(int N, int startY, int startX)
{
	if (N == 3)
	{
		board[startY][startX] = '*';
		board[startY][startX + 1] = '*';
		board[startY][startX + 2] = '*';

		board[startY + 1][startX] = '*';
		board[startY + 1][startX + 2] = '*';

		board[startY + 2][startX] = '*';
		board[startY + 2][startX + 1] = '*';
		board[startY + 2][startX + 2] = '*';
	}
	else
	{
		Draw(N / 3, startY, startX);
		Draw(N / 3, startY, startX + (N / 3));
		Draw(N / 3, startY, startX + 2 * (N / 3));

		Draw(N / 3, startY + (N / 3), startX);
		Draw(N / 3, startY + (N / 3), startX + 2 * (N / 3));

		Draw(N / 3, startY + 2 * (N / 3), startX);
		Draw(N / 3, startY + 2 * (N / 3), startX + (N / 3));
		Draw(N / 3, startY + 2 * (N / 3), startX + 2 * (N / 3));
	}
}


int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			board[i][j] = ' ';
		}
	}
	Draw(N, 0, 0);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}