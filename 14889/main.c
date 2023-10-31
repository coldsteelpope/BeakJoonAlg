#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF (~0U >> 2)

bool visited[21] = { 0, };
int matrix[21][21] = { 0, };

int min_value = INF;

int GetAbs(int a)
{
	return a < 0 ? -a : a;
}

int GetMin(int a, int b)
{
	return a > b ? b : a;
}

void DFS(int depth, int idx, int N)
{
	if (depth != (N / 2))
	{
		for (int i = idx; i <= N; ++i)
		{
			visited[i] = true;
			DFS(depth + 1, i + 1, N);
			visited[i] = false;
		}
		return;
	}
	else
	{
		if (visited[1] == true && visited[3] == true && visited[6] == true)
		{
			int a = 3;
		}

		int star_team = 0;
		int link_team = 0;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = i + 1; j <= N; ++j)
			{
				if (visited[i] == true && visited[j] == true)
				{
					star_team += matrix[i][j];
					star_team += matrix[j][i];
				}
				else if(visited[i] == false && visited[j] == false)
				{
					link_team += matrix[i][j];
					link_team += matrix[j][i];
				}
			}
		}
		min_value = GetMin(min_value, GetAbs(star_team - link_team));
		return;
	}
}


void SetMatrix(int N)
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	SetMatrix(N);
	DFS(0, 1, N);
	printf("%d", min_value);
	return 0;
}