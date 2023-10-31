#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF (~0U >> 2)

int adjacent[101][101] = { 0, };

void FillAdjacent(int total_city_num)
{
	for (int y = 1; y <= total_city_num; ++y)
	{
		for (int x = 1; x <= total_city_num; ++x)
		{
			adjacent[y][x] = INF;
		}
	}
}

void SetAdjacent(int total_city_num)
{
	for (int i = 0; i < total_city_num; ++i)
	{
		int start_pos, target_pos, cost;
		scanf("%d%d%d", &start_pos, &target_pos, &cost);

		if (adjacent[start_pos][target_pos] > cost)
			adjacent[start_pos][target_pos] = cost;
	}
}

void PrintAdjacent(int total_city_num)
{
	for (int y = 1; y <= total_city_num; ++y)
	{
		for (int x = 1; x <= total_city_num; ++x)
		{
			if (adjacent[y][x] == INF)
			{
				printf("0 ");
			}
			else
			{
				printf("%d ", adjacent[y][x]);
			}
		}
		printf("\n");
	}
}

int main(void)
{
	// n: 도시의 개수, m: 버스의 개수
	int n, m;
	scanf("%d%d", &n, &m);
	FillAdjacent(n);
	SetAdjacent(m);
	
	for (int k = 1; k <= n; ++k)
	{
		for (int y = 1; y <= n; ++y)
		{
			for (int x = 1; x <= n; ++x)
			{
				if (x != y)
				{
					if (adjacent[y][x] > adjacent[y][k] + adjacent[k][x])
					{
						adjacent[y][x] = adjacent[y][k] + adjacent[k][x];
					}
				}
			}
		}
	}

	PrintAdjacent(n);
	return 0;
}