#include <iostream>
#include <vector>

using namespace std;

int max_height = 0;
vector<vector<int>> g_map;
vector<vector<bool>> g_visited;

void DFS(int y, int x, int N, int current_height)
{
	if (y < 0 || x < 0 || x >= N || y >= N)
		return;
	if (g_visited[y][x] == true)
		return;
	if (g_map[y][x] <= current_height)
		return;
	
	g_visited[y][x] = true;
	DFS(y, x + 1, N, current_height);
	DFS(y + 1, x, N, current_height);
	DFS(y, x - 1, N, current_height);
	DFS(y - 1, x, N, current_height);
}

void InitVisited(int N)
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			g_visited[i][j] = false;
}

int GetMaxValue(int N)
{
	int answer = 0;
	for (int height = max_height; height >= 0; --height)
	{
		int current_height = height;
		int the_number_of_safe_zone = 0;
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (g_map[i][j] <= current_height)
					continue;
				if (g_visited[i][j] == true)
					continue;
				
				++the_number_of_safe_zone;
				DFS(i, j, N, current_height);
			}
		}
		answer = (answer > the_number_of_safe_zone) ? answer : the_number_of_safe_zone;
		InitVisited(N);
	}
	return answer;
}

void SetMap(int N)
{
	g_map.resize(N, vector<int>(N, 0));
	g_visited.resize(N, vector<bool>(N, false));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> g_map[i][j];
			max_height = (max_height > g_map[i][j]) ? max_height : g_map[i][j];
		}
	}
}

int main(void)
{
	int N;
	cin >> N;

	SetMap(N);
	int answer = GetMaxValue(N);
	cout << answer << endl;
	return 0;
}