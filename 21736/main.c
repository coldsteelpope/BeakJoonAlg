// DFS로 풀기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char map[601][601] = { 0, };
bool visited[601][601] = { 0, };

void Dfs(int y, int x, int M, int N, int* answer)
{
	if (y < 0 || x < 0 || y >= N || x >= M)
		return;
	
	if (visited[y][x] == true)
		return;

	if (map[y][x] == 'X')
		return;
	
	if (map[y][x] == 'P')
		++(*answer);

	visited[y][x] = true;

	Dfs(y, x + 1, M, N, answer);
	Dfs(y + 1, x, M, N, answer);
	Dfs(y, x - 1, M, N, answer);
	Dfs(y - 1, x, M, N, answer);
}


int main(void)
{
	int N, M; // N: 세로, M: 가로
	scanf("%d%d", &N, &M);

	int answer = 0;
	for (int i = 0; i < N; ++i)
		scanf("%s", map[i]);

	int start_y = -1;
	int start_x = -1;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (map[y][x] == 'I')
			{
				start_y = y;
				start_x = x;
			}
		}
	}

	Dfs(start_y, start_x, M, N, &answer);

	if (answer != 0)
		printf("%d\n", answer);
	else
		printf("TT\n");
	return 0;
}