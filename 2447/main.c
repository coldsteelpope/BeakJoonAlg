#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 6561
char board[MAX_LEN][MAX_LEN] = { 0, };


// 다음에는 이중 반복문을 사용해서 풀기
void InitBoard(int N);
void PrintBoard(int N);

void Draw(int startY, int startX, int N)
{
	if (N == 3)
	{
		board[startY][startX] = '*'; board[startY][startX + 1] = '*'; board[startY][startX + 2] = '*';
		board[startY + 1][startX] = '*'; board[startY + 1][startX + 1] = ' '; board[startY + 1][startX + 2] = '*';
		board[startY + 2][startX] = '*'; board[startY + 2][startX + 1] = '*'; board[startY + 2][startX + 2] = '*';
	}
	else
	{
		Draw(startY, startX, N / 3); 
		Draw(startY, startX + (N / 3), N / 3); 
		Draw(startY, startX + 2 * (N / 3), N / 3);

		Draw(startY + (N / 3), startX, N / 3); 
		Draw(startY + (N / 3), startX + 2 * (N / 3), N / 3);
		Draw(startY + 2 * (N / 3), startX, N / 3); Draw(startY + 2 * (N / 3), startX + (N / 3), N / 3);  Draw(startY + 2 * (N / 3), startX + 2 * (N / 3), N / 3);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	InitBoard(N);
	Draw(0, 0, N);
	PrintBoard(N);
	return 0;
}

void InitBoard(int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			board[i][j] = ' ';
		}
	}
}

void PrintBoard(int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}