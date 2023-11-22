#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int board[51][51] = { 0, };
void SetBoard(int N, int M);
//void PrintBoard(int N, int M);

int dirs[4][2] = {
	{ -1, +0 },
	{ +0, +1 },
	{ +1, +0 },
	{ +0, -1 }
};

int answer = 0;

bool IsNotClean(int currentY, int currentX, int N, int M)
{
	bool result = false;
	for (int dirIdx = 0; dirIdx < 4; ++dirIdx)
	{
		int surroundingY = currentY + dirs[dirIdx][0];
		int surroundingX = currentX + dirs[dirIdx][1];
		
		/* 벽이 있는 경우 */
		if (board[surroundingY][surroundingX] == 1)
		{
			continue;
		}

		if (board[surroundingY][surroundingX] == 0)
		{
			result = true;
			break;
		}
	}
	return result;
}

void DFS(int currentY, int currentX, int currentDir, int N, int M)
{
	/* 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다. */
	if (board[currentY][currentX] == 0)
	{
		++answer;
		/* 2: clean status */
		board[currentY][currentX] = 2;
	}

	//PrintBoard(N, M, currentY, currentX, currentDir);

	bool isNotClean = IsNotClean(currentY, currentX, N, M);
	if (isNotClean == true)
	{
		/*
		현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
		1) 반시계 방향으로 90도 회전한다.
		2) 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
		3) 1번으로 돌아간다.
		*/

		int nextDir = currentDir;
		int nextY, nextX;
		for (int t = 0; t < 4; ++t)
		{
			nextDir = (nextDir == 0) ? 3 : (nextDir - 1);
			int nextY = currentY + dirs[nextDir][0];
			int nextX = currentX + dirs[nextDir][1];
			if (board[nextY][nextX] == 1 || board[nextY][nextX] == 2)
			{
				continue;
			}
			

			DFS(nextY, nextX, nextDir, N, M);
		}
	}
	else
	{
		/*
		현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
		1) 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
		2) 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
		*/

		int backwardDir = (currentDir + 2) % 4;
		int nextY = currentY + dirs[backwardDir][0];
		int nextX = currentX + dirs[backwardDir][1];
		if (board[nextY][nextX] == 1)
		{
			printf("%d\n", answer);
			exit(0);
		}

		DFS(nextY, nextX, currentDir, N, M);
	}
}

int main(void)
{
	int N, M, cleanerY, cleanerX, cleanerDir;
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &cleanerY, &cleanerX, &cleanerDir);
	SetBoard(N, M);
	DFS(cleanerY, cleanerX, cleanerDir, N, M);
	return 0;
}

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

//void PrintBoard(int N, int M, int currentY, int currentX, int currentDir)
//{
//	printf("\n");
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < M; ++j)
//		{
//			printf("%d ", board[i][j]);
//		}
//		printf("\n");
//	}
//	printf("anwer: %d (%d, %d) dir: %d\n", answer, currentY, currentX, currentDir);
//	printf("\n");
//}