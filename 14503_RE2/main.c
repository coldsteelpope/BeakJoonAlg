#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 51

int answer = 0;
int board[MAX_LEN][MAX_LEN] = { 0, };
int dirs[4][2] = {
	{ -1, +0 },
	{ +0, +1 },
	{ +1, +0 },
	{ +0, -1 }
};

void SetBoard(int N, int M)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &board[i][j]);
		}
	}
}

bool IsClear(int currentY, int currentX)
{
	bool isClear = true;
	for (int dirIdx = 0; dirIdx < 4; ++dirIdx)
	{
		int nextY = currentY + dirs[dirIdx][0];
		int nextX = currentX + dirs[dirIdx][1];

		if (board[nextY][nextX] == 0)
		{
			isClear = false;
		}
	}
	return isClear;
}

void DFS(int currentY, int currentX, int currentDir)
{
	if (board[currentY][currentX] == 0)
	{
		++answer;
		board[currentY][currentX] = 2;
	}

	bool isClear = IsClear(currentY, currentX);
	if (isClear == true)
	{
		int backDir = (currentDir + 2) % 4;

		int backY = currentY + dirs[backDir][0];
		int backX = currentX + dirs[backDir][1];

		if (board[backY][backX] == 1)
		{
			printf("%d\n", answer);
			exit(0);
		}
		else
		{
			DFS(backY, backX, currentDir);
		}
	}
	else
	{
		int nextDir = currentDir;
		int nextY = 0, nextX = 0;
		for (int i = 0; i < 4; ++i)
		{
			nextDir = (nextDir == 0) ? 3 : (nextDir - 1);
			nextY = currentY + dirs[nextDir][0];
			nextX = currentX + dirs[nextDir][1];

			if (board[nextY][nextX] == 0)
			{
				break;
			}
		}
		DFS(nextY, nextX, nextDir);
	}
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	int cleanerY, cleanerX, cleanerDir;
	scanf("%d%d%d", &cleanerY, &cleanerX, &cleanerDir);

	SetBoard(N, M);

	DFS(cleanerY, cleanerX, cleanerDir);
}