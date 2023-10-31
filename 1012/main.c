#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int map[50][50] = { 0, };
bool visited[50][50] = { 0, };

void Dfs(int y, int x, int M, int N)
{
	if (y < 0 || x < 0 || x >= M || y >= N)
		return;
	if (visited[y][x] == true)
		return;
	if (map[y][x] == 0)
		return;
	visited[y][x] = true;

	Dfs(y - 1, x, M, N);
	Dfs(y + 1, x, M, N);
	Dfs(y, x + 1, M, N);
	Dfs(y, x - 1, M, N);
}

void DfsAll(int *earthworm_num, int M, int N)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (visited[y][x] == true)
				continue;
			if (map[y][x] == 0)
				continue;
			Dfs(y, x, M, N);
			++(*earthworm_num);
		}
	}
}

void SetMap(int y, int x)
{
	map[y][x] = 1;
}

void ClearMap(int M, int N)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			map[y][x] = 0;
			visited[y][x] = false;
		}
	}
}

void PrintMatrix(int M, int N)
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

int main(void)
{
	int T;
	scanf("%d", &T);
	
	for (int t = 0; t < T; ++t)
	{
		int M, N, K;
		scanf("%d%d%d", &M, &N, &K);
		ClearMap(M, N);
		
		int earthworm_num = 0;
		for (int k = 0; k < K; ++k)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			SetMap(y, x);
		}
		
		DfsAll(&earthworm_num, M, N);

		printf("%d\n", earthworm_num);
		//PrintMatrix(M, N);
	}
	return 0;
}