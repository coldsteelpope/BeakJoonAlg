#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF (~0U >> 2)

using namespace std;

vector<vector<int>> map;
vector<vector<int>> dist;

void PrintDist(int N)
{
	cout << endl;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cout << dist[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Dij(int N)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ map[0][0], {0,0}});
	dist[0][0] = map[0][0];
	
	while (pq.empty() == false) 
	{
		pair<int, pair<int, int>> here = pq.top();
		pq.pop();

		if (here.first > dist[here.second.first][here.second.second])
			continue;

		int dirs[4][2] = {
			{ +0, +1 },
			{ +1, +0 },
			{ +0, -1 },
			{ -1, +0 }
		};

		for (int dirs_i = 0; dirs_i < 4; ++dirs_i)
		{
			int next_y = here.second.first + dirs[dirs_i][0];
			int next_x = here.second.second + dirs[dirs_i][1];

			if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= N)
				continue;
			
			int pathLen = here.first + map[next_y][next_x];

			if (pathLen < dist[next_y][next_x])
			{
				dist[next_y][next_x] = pathLen;
				pq.push({ pathLen, { next_y, next_x } });
			}
		}

		//PrintDist(N);
	}
}

void SetMap(int N)
{
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> map[y][x];
}

int main(void)
{
	int answer_num = 1;
	while (1)
	{
		int N;
		cin >> N;

		if (N == 0)
		{
			break;
		}
		else
		{
			map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
			dist = vector<vector<int>>(N + 1, vector<int>(N + 1, INF));

			SetMap(N);
			Dij(N);
			cout << "Problem " << answer_num << ": " << dist[N - 1][N - 1] << endl;
			map.clear();
			dist.clear();
			++answer_num;
		}
	}

	return 0;
}