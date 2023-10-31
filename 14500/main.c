#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int answer = 0;
int map[501][501] = { 0, };
bool visited[501][501] = { 0, };

int dirs[4][2] = {
	{+0, +1},
	{+1, +0},
	{+0, -1},
	{-1. +0}
};

int mountain_dirs[4][4][2] = {
	{
		// ㅜ
		{0, 0}, {0, 1}, {1,1}, {0, 2}
	},
	{
		// ㅗ
		{0, 0}, {0, 1}, {-1,1}, {0, 2}
	},
	{
		// ㅓ
		{0, 0}, {0, 1}, {-1, 1}, {1, 1}
	},
	{
		// ㅏ
		{0, 0}, {0, -1}, {-1,-1}, {1, -1}
	}
};

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

// ㅗ 제외 나머지
void Dfs(int y, int x, int sum, int len, int N, int M)
{
	if (len == 4)
	{
		answer = GetMax(answer, sum);
		return;
	}
	else
	{
		for (int dir_index = 0; dir_index < 4; ++dir_index)
		{
			int next_y = y + dirs[dir_index][0];
			int next_x = x + dirs[dir_index][1];

			// N = 세로 크기
			// M = 가로 크기
			if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
				continue;
			if (visited[next_y][next_x] == true)
				continue;

			visited[next_y][next_x] = true;
			Dfs(next_y, next_x, sum + map[next_y][next_x], len + 1, N, M);
			visited[next_y][next_x] = false;
		}
	}
}

void MountainDfs(int y, int x, int N, int M)
{
	for (int shape = 0; shape < 4; ++shape)
	{
		int len = 0;
		int sum_value = 0;
		
		for (int i = 0; i < 4; ++i)
		{
			int next_y = y + mountain_dirs[shape][i][0];
			int next_x = x + mountain_dirs[shape][i][1];

			if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
				continue;
			
			sum_value += map[next_y][next_x];
			++len;
		}

		if (len == 4)
			answer = GetMax(answer, sum_value);
	}
}

void PrintMap(int N, int M)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			printf("%d\t", map[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetMap(int N, int M)
{
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			scanf("%d", &map[y][x]);
}

int main(void)
{
	// N = 세로 크기
	// M = 가로 크기
	int N, M;
	scanf("%d%d", &N, &M);
	
	SetMap(N, M);
	//PrintMap(N, M);

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			visited[y][x] = true;
			Dfs(y, x, map[y][x], 1, N, M);
			visited[y][x] = false;
			MountainDfs(y, x, N, M);
		}
	}

	printf("%d", answer);
	return 0;
}