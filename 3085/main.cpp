#include <iostream>
#include <vector>

using namespace std;

vector<string> map;

inline int GetMax(int a, int b)
{
	return a > b ? a : b;
}

void Swap(int y, int x, int n_y, int n_x)
{
	char temp = map[y][x];
	map[y][x] = map[n_y][n_x];
	map[n_y][n_x] = temp;
}

int max_value = 0;
void Search(int N)
{
	// 행 전부 찾기
	for (int i = 0; i < N; ++i)
	{
		int count = 1;
		for (int j = 0; j < N - 1; ++j)
		{
			if (map[i][j] == map[i][j + 1])
			{
				++count;
				max_value = GetMax(max_value, count);
			}
			else
			{
				count = 1;
			}
		}
	}
	// 열 전부 찾기
	for (int j = 0; j < N; ++j)
	{
		int count = 1;
		for (int i = 0; i < N - 1; ++i)
		{
			if (map[i][j] == map[i + 1][j])
			{
				++count;
				max_value = GetMax(max_value, count);
			}
			else
			{
				count = 1;
			}
		}
	}


}

void PrintMap(int N)
{
	printf("\n");
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			printf("%c ", map[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	int N;
	cin >> N;
	
	map.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> map[i];
	
	int dirs[4][2] = {
		{ +0, +1 },
		{ +1, +0 },
		{ +0, -1 },
		{ -1, +0 }
	};

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			for (int dir_i = 0; dir_i < 4; ++dir_i)
			{
				int next_y = y + dirs[dir_i][0];
				int next_x = x + dirs[dir_i][1];

				if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N)
					continue;

				Swap(y, x, next_y, next_x);

				Search(N);
				//printf("(x: %d, y: %d) // (next_x: %d, next_y: %d) \n", x, y, next_x, next_y);
				
				//PrintMap(N);
				Swap(y, x, next_y, next_x);
			}
		}
	}
	
	printf("%d", max_value);
	return 0;
}