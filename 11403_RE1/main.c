#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define MAX_LEN 101

int adjacentMatrix[MAX_LEN][MAX_LEN] = { 0, };
int result[MAX_LEN][MAX_LEN] = { 0, };
bool visited[MAX_LEN] = { 0, };

void SetAdjacentMatrix(int N);
void PrintResult(int N);

void DFS(int here, int start, int target, int N, int depth)
{
	//if (here == target && depth != 0)
	//{
	//	result[start][target] = 1;
	//}

	visited[here] = true;
	for (int there = 0; there < N; ++there)
	{
		if (adjacentMatrix[here][there] == 0)
			continue;

		if (there == target)
		{
			result[start][target] = 1;
		}

		if (visited[there] == true)
			continue;

		DFS(there, start, target, N, depth + 1);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	SetAdjacentMatrix(N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			DFS(i, i, j, N, 0);
			memset(visited, false, sizeof(visited));
		}
	}
	PrintResult(N);
	return 0;
}

void SetAdjacentMatrix(int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &adjacentMatrix[i][j]);
		}
	}
}

void PrintResult(int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}