#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int map[1000][1000] = { 0, };
bool visited[1000] = { 0, };

void Dfs(int node, int N)
{
	if (visited[node - 1] == true)
		return;
	visited[node - 1] = true;
	for (int other_node = 1; other_node <= N; other_node++)
	{
		if (map[node - 1][other_node - 1] == 0)
			continue;
		if (visited[other_node - 1] == true)
			continue;
		Dfs(other_node, N);
	}
}

void DfsAll(int N, int* answer)
{
	for (int node = 1; node <= N; ++node)
	{
		if (visited[node - 1] == false)
		{
			Dfs(node, N);
			(*answer)++;
		}
	}
}

void SetMap(int y, int x)
{
	map[y - 1][x - 1] = 1;
	map[x - 1][y - 1] = 1;
}

void PrintMap(int N)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			printf("%d\t", map[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	int N, M;
	int answer = 0;
	scanf("%d%d", &N, &M);
	
	for (int i = 0; i < M; ++i)
	{
		int y, x;
		scanf("%d%d", &y, &x);
		SetMap(y, x);
	}

	DfsAll(N, &answer);
	
	printf("%d\n", answer);

	return 0;
}