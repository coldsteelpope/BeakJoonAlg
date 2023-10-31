#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

int map[100][100] = { 0, };
int answer[100][100] = { 0, };
bool visited[100][100] = {0,};

void Dfs(int here, int N, int root_num)
{
	for (int there = 0; there < N; ++there)
	{
		if (map[here][there] == 0)
			continue;
		if (visited[here][there] == true)
			continue;

		visited[here][there] = true;
		answer[root_num][there] = 1;
		Dfs(there, N, root_num);
	}
}

void DfsAll(int N)
{
	for (int here = 0; here < N; ++here)
	{
		memset(visited, 0, sizeof(visited));
		Dfs(here, N, here);
	}
}

void PrintAnswer(int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", answer[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			scanf("%d", &map[y][x]);
		}
	}

	DfsAll(N);
	PrintAnswer(N);

	return 0;
}