#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN (~0U >> 2)

int map[7][7] = { 0, };

int answer = MIN;
void DFS(int y, int x, int N, int M, char ex_dir, int cost)
{
	if (y < 0 || x < 0 || x >= M || y >= N)
		return;

	if (y == N - 1)
	{
		answer = (answer > cost) ? cost : answer;
		return;
	}
	
	if (ex_dir == 'G')
	{
		DFS(y + 1, x, N, M, 'F', cost + map[y + 1][x]);
		DFS(y + 1, x - 1, N, M, 'L', cost + map[y + 1][x - 1]);
		DFS(y + 1, x + 1, N, M, 'R', cost + map[y + 1][x + 1]);
	}
	else if (ex_dir == 'F')
	{
		DFS(y + 1, x - 1, N, M, 'L', cost + map[y + 1][x - 1]);
		DFS(y + 1, x + 1, N, M, 'R', cost + map[y + 1][x + 1]);
	}
	else if (ex_dir == 'L')
	{
		DFS(y + 1, x, N, M, 'F', cost + map[y + 1][x]);
		DFS(y + 1, x + 1, N, M, 'R', cost + map[y + 1][x + 1]);
	}
	else if (ex_dir == 'R')
	{
		DFS(y + 1, x, N, M, 'F', cost + map[y + 1][x]);
		DFS(y + 1, x - 1, N, M, 'L', cost + map[y + 1][x - 1]);
	}
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d", &map[i][j]);

	for (int j = 0; j < M; ++j)
	{
		DFS(0, j, N, M, 'G', map[0][j]);
	}

	printf("%d", answer);
	return 0;
}