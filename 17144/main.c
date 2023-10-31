#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct _NODE
{
	int _data;
	int _overlapped_data;
	bool _overlapped;
} Node;

Node map[51][51] = { 0, };


void SetMap(int N, int M)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			scanf("%d", &map[y][x]._data);
			map[y][x]._overlapped = false;
			map[y][x]._overlapped_data = 0;
		}
	}
}

void PrintMap(int N, int M)
{
	printf("\n");
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			printf("%d\t", map[y][x]._data);
		}
		printf("\n");
	}
	printf("\n");
}



void SetOverlapped(int N, int M)
{
	int dirs[4][2] = {
		{+0, +1},
		{+1, +0},
		{+0, -1},
		{-1, +0}
	};

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (map[y][x]._data != 0)
			{
				int diffusion_dirs_num = 0;
				int overlapped_data = map[y][x]._data / 5;

				for (int dirs_index = 0; dirs_index < 4; ++dirs_index)
				{
					int adjacentY = y + dirs[dirs_index][0];
					int adjacentX = x + dirs[dirs_index][1];

					if (adjacentX < 0 || adjacentY < 0 || adjacentX >= M || adjacentY >= N)
						continue;
					if (map[adjacentY][adjacentX]._data == -1)
						continue;

					map[adjacentY][adjacentX]._overlapped = true;
					map[adjacentY][adjacentX]._overlapped_data += overlapped_data;
					++diffusion_dirs_num;
				}
				map[y][x]._data = map[y][x]._data - (overlapped_data * diffusion_dirs_num);
			}
		}
	}
}

void ApplyOverlapped(int N, int M)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (map[y][x]._overlapped)
			{
				map[y][x]._data += map[y][x]._overlapped_data;
				map[y][x]._overlapped = false;
				map[y][x]._overlapped_data = 0;
			}
		}
	}
}

void SetDiffusion(int N, int M)
{
	SetOverlapped(N, M);
	ApplyOverlapped(N, M);
}

int GetUpperAirConditionPos(int N)
{
	int pos = -1;
	for (int y = 0; y < N; ++y)
	{
		if (map[y][0]._data == -1)
		{
			pos = y;
			break;
		}
	}
	return pos;
}

int GetLowerAirConditionPos(int N)
{
	int pos = -1;
	for (int y = N - 1; y >= 0; --y)
	{
		if (map[y][0]._data == -1)
		{
			pos = y;
			break;
		}
	}
	return pos;
}


void InitPos(int y, int x)
{
	map[y][x]._data = 0;
	map[y][x]._overlapped = false;
	map[y][x]._overlapped_data = 0;
}

void SwapNode(Node* n1, Node* n2)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memcpy(temp, n1, sizeof(Node));
	memcpy(n1, n2, sizeof(Node));
	memcpy(n2, temp, sizeof(Node));
	free(temp);
}

void SetUpperAirCondition(int M, int upper_air_condition_pos)
{
	// left to right
	Node temp1 = { 0, 0, false };
	Node temp2 = map[upper_air_condition_pos][1];
	bool toggle = true;

	for (int x = 1; x < M - 1; ++x)
	{
		if (toggle)
		{
			map[upper_air_condition_pos][x] = temp1;
			temp1 = map[upper_air_condition_pos][x + 1];
			toggle = false;
		}
		else
		{
			map[upper_air_condition_pos][x] = temp2;
			temp2 = map[upper_air_condition_pos][x + 1];
			toggle = true;
		}
	}

	// down to up
	// toggle true => temp1에 다음 node에 담길 data가 담김
	// toggle false => temp2에 다음 node에 담길 data가 담김
	if (toggle == false)
		SwapNode(&temp1, &temp2);
	toggle = true;

	for (int y = upper_air_condition_pos; y >= 1; --y)
	{
		if (toggle)
		{
			map[y][M - 1] = temp1;
			temp1 = map[y - 1][M - 1];
			toggle = false;
		}
		else
		{
			map[y][M - 1] = temp2;
			temp2 = map[y - 1][M - 1];
			toggle = true;
		}
	}

	// right to left
	if (toggle == false)
		SwapNode(&temp1, &temp2);
	toggle = true;
	for (int x = M - 1; x >= 1; --x)
	{
		if (toggle)
		{
			map[0][x] = temp1;
			temp1 = map[0][x - 1];
			toggle = false;
		}
		else
		{
			map[0][x] = temp2;
			temp2 = map[0][x - 1];
			toggle = true;
		}
	}



	// up to down
	if (toggle == false)
		SwapNode(&temp1, &temp2);
	toggle = true;
	for (int y = 0; y < upper_air_condition_pos; ++y)
	{
		if (toggle)
		{
			map[y][0] = temp1;
			temp1 = map[y + 1][0];
			toggle = false;
		}
		else
		{
			map[y][0] = temp2;
			temp2 = map[y + 1][0];
			toggle = true;
		}
	}
}

void SetLowerAirCondition(int N, int lower_air_condition_pos, int M)
{
	// left to right
	Node temp1 = { 0, 0, false };
	Node temp2 = map[lower_air_condition_pos][1];
	bool toggle = true;

	for (int x = 1; x < M - 1; ++x)
	{
		if (toggle)
		{
			map[lower_air_condition_pos][x] = temp1;
			temp1 = map[lower_air_condition_pos][x + 1];
			toggle = false;
		}
		else
		{
			map[lower_air_condition_pos][x] = temp2;
			temp2 = map[lower_air_condition_pos][x + 1];
			toggle = true;
		}
	}

	// up to down
	// toggle true => temp1에 다음 node에 담길 data가 담김
	// toggle false => temp2에 다음 node에 담길 data가 담김
	if (toggle == false)
		SwapNode(&temp1, &temp2);
	toggle = true;

	for (int y = lower_air_condition_pos; y < N - 1; ++y)
	{
		if (toggle)
		{
			map[y][M - 1] = temp1;
			temp1 = map[y + 1][M - 1];
			toggle = false;
		}
		else
		{
			map[y][M - 1] = temp2;
			temp2 = map[y + 1][M - 1];
			toggle = true;
		}
	}

	// right to left
	if (toggle == false)
		SwapNode(&temp1, &temp2);
	toggle = true;
	for (int x = M - 1; x >= 1; --x)
	{
		if (toggle)
		{
			map[N - 1][x] = temp1;
			temp1 = map[N - 1][x - 1];
			toggle = false;
		}
		else
		{
			map[N - 1][x] = temp2;
			temp2 = map[N - 1][x - 1];
			toggle = true;
		}
	}

	// up to down
	if (toggle == false)
		SwapNode(&temp1, &temp2);
	toggle = true;
	for (int y = N - 1; y > lower_air_condition_pos; --y)
	{
		if (toggle)
		{
			map[y][0] = temp1;
			temp1 = map[y - 1][0];
			toggle = false;
		}
		else
		{
			map[y][0] = temp2;
			temp2 = map[y - 1][0];
			toggle = true;
		}
	}
}

void SetAirCondition(int N, int M, int upper_air_condition_pos, int lower_air_condition_pos)
{
	// upper-side
	SetUpperAirCondition(M, upper_air_condition_pos);
	// lower-side
	SetLowerAirCondition(N, lower_air_condition_pos, M);
}

int GetSum(int N, int M)
{
	int sum = 0;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (map[y][x]._data == -1)
				continue;
			sum += map[y][x]._data;
		}
	}
	return sum;
}

int main(void)
{
	// N = height, M = width
	int N, M, T;
	scanf("%d%d%d", &N, &M, &T);
	SetMap(N, M);

	int upper_air_condition_pos = GetUpperAirConditionPos(N);
	int lower_air_condition_pos = GetLowerAirConditionPos(N);
	
	for (int t = 0; t < T; ++t)
	{
		SetDiffusion(N, M);
		SetAirCondition(N, M, upper_air_condition_pos, lower_air_condition_pos);
	}
	int sum = GetSum(N, M);
	printf("%d\n", sum);
	
	// 검증하기 testcase로
	return 0;
}