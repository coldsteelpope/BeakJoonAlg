#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char map[21][21] = { 0, };
int trackers[21][21] = { 0, };
bool visited[26] = { 0, };
int max_count = 0;

//void PrintTrackers(int R, int C)
//{
//	printf("\n");
//	for (int i = 0; i < R; ++i)
//	{
//		for (int j = 0; j < C; ++j)
//		{
//			printf("%d ", trackers[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

void Dfs(int y, int x, int R, int C, int count)
{
	if (y < 0 || x < 0 || y >= R || x >= C)
	{
		max_count = (max_count > count) ? max_count : count;
		return;
	}

	int alp_num = map[y][x] - 'A';
	if (visited[alp_num] == true)
	{
		max_count = (max_count > count) ? max_count : count;
		return;
	}
	else
	{
		visited[alp_num] = true;
		//trackers[y][x] = 1;
		//PrintTrackers(R, C);
		count += 1;
		Dfs(y, x + 1, R, C, count);
		Dfs(y + 1, x, R, C, count);
		Dfs(y, x - 1, R, C, count);
		Dfs(y - 1, x, R, C, count);
		
		visited[alp_num] = false;
	}
}

void SetMap(int R)
{
	for (int r = 0; r < R; ++r)
		scanf("%s", map[r]);
}

int main(void)
{
	int R, C;
	scanf("%d%d", &R, &C);
	SetMap(R);

	
	Dfs(0, 0, R, C, 0);
	printf("%d\n", max_count);
	return 0;
}