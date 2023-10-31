#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int map[52][52] = { 0, };

typedef struct CLEAN_MACHINE
{
	int _y;
	int _x;
	int _count;
	int _dir;
} CleanMachine;

void SetMap(int N, int M)
{
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			scanf("%d", &map[y][x]);
}

int dirs[4][2] = {
	{ -1, +0 },
	{ +0, +1 },
	{ +1, +0 },
	{ +0, -1 }
};

int GetNextDir(int currentDir)
{
	int next_rotate_dir = 0;
	switch (currentDir)
	{
	case 0:
		next_rotate_dir = 3;
		break;
	case 1:
		next_rotate_dir = 0;
		break;
	case 2:
		next_rotate_dir = 1;
		break;
	case 3:
		next_rotate_dir = 2;
		break;
	default:
		break;
	}
	return next_rotate_dir;
}

bool CheckSurroundingClean(int current_pos_y, int current_pos_x)
{
	bool result = true;
	for (int dir_i = 0; dir_i < 4; ++dir_i)
	{
		int next_y = current_pos_y + dirs[dir_i][0];
		int next_x = current_pos_x + dirs[dir_i][1];

		if (map[next_y][next_x] == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}

void PrintMap(int N, int M, CleanMachine* cleanMachine)
{
	printf("\n");
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			printf("%d ", map[y][x]);
		}
		printf("\n");
	}
	printf("y: %d, x: %d, dir: %d, count: %d \n", cleanMachine->_y, cleanMachine->_x, cleanMachine->_dir, cleanMachine->_count);
	printf("\n");
}

void DFS(CleanMachine* cleanMachine, int N, int M)
{
	int current_pos_y = cleanMachine->_y;
	int current_pos_x = cleanMachine->_x;
	int current_machine_dir = cleanMachine->_dir;



	if (map[current_pos_y][current_pos_x] == 0)
	{
		++cleanMachine->_count;
		map[current_pos_y][current_pos_x] = 2;
	}

	//PrintMap(N, M, cleanMachine);

	bool isSurroundingClean = CheckSurroundingClean(current_pos_y, current_pos_x);

	if (isSurroundingClean == true)
	{
		/*
		1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
		2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
		*/

		int behind_dir = (current_machine_dir + 2) % 4;
		int next_y = current_pos_y + dirs[behind_dir][0];
		int next_x = current_pos_x + dirs[behind_dir][1];

		if (next_y < 0 && next_x < 0 && next_y >= N && next_x >= M)
			return;
		else
		{
			if (map[next_y][next_x] == 1)
			{
				return;
			}
			else
			{
				cleanMachine->_y = next_y;
				cleanMachine->_x = next_x;
				DFS(cleanMachine, N, M);
			}
		}
	}
	else
	{
		/*
		// 1. 반시계 방향으로  $90^\circ$ 회전한다.
		2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
		3. 1번으로 돌아간다.
		*/
		
		int next_dir = current_machine_dir;
		for (int i = 0; i < 4; ++i)
		{
			next_dir = GetNextDir(next_dir);
			int next_y = current_pos_y + dirs[next_dir][0];
			int next_x = current_pos_x + dirs[next_dir][1];

			if (map[next_y][next_x] == 0)
			{
				cleanMachine->_y = next_y;
				cleanMachine->_x = next_x;
				cleanMachine->_dir = next_dir;
				DFS(cleanMachine, N, M);
				break;
			}
		}
	}
}



int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);

	CleanMachine cleanMachine;
	cleanMachine._count = 0;
	scanf("%d%d%d", &cleanMachine._y, &cleanMachine._x, &cleanMachine._dir);

	SetMap(N, M);
	DFS(&cleanMachine, N, M);

	printf("%d", cleanMachine._count);
	return 0;
}