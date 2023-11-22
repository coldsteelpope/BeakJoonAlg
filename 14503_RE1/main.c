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
		
		/* ���� �ִ� ��� */
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
	/* ���� ĭ�� ���� û�ҵ��� ���� ���, ���� ĭ�� û���Ѵ�. */
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
		���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �ִ� ���,
		1) �ݽð� �������� 90�� ȸ���Ѵ�.
		2) �ٶ󺸴� ������ �������� ���� ĭ�� û�ҵ��� ���� �� ĭ�� ��� �� ĭ �����Ѵ�.
		3) 1������ ���ư���.
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
		���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� ���� ���,
		1) �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �� �ִٸ� �� ĭ �����ϰ� 1������ ���ư���.
		2) �ٶ󺸴� ������ ���� ĭ�� ���̶� ������ �� ���ٸ� �۵��� �����.
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