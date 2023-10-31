#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>

#define INF (~0U >> 2)

using namespace std;

vector<vector<pair<int, int>>> adjacent(1001);
vector<int> go_distance(1001, INF);
vector<int> come_distance(1001, INF);

void SetAdjacent(int M)
{
	for (int i = 0; i < M; ++i)
	{
		int start, target, cost;
		cin >> start >> target >> cost;
		adjacent[start].push_back({ cost, target });
	}
}

void GoBFS(int init_pos, int target_pos)
{
	vector<int> dis(1001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, init_pos });
	dis[init_pos] = 0;
	
	while (pq.empty() == false)
	{
		pair<int, int> here_pair = pq.top();
		int here_cost = here_pair.first;
		int here_pos = here_pair.second;
		pq.pop();

		if (here_pos == target_pos)
		{
			go_distance[init_pos] = (go_distance[init_pos] > here_cost) ? here_cost : go_distance[init_pos];
		}
		

		if (here_cost > dis[here_pos])
			continue;
		
		for (int there_index = 0; there_index < adjacent[here_pos].size(); ++there_index)
		{
			pair<int, int> there_pair = adjacent[here_pos][there_index];
			int path = here_cost + there_pair.first;
			if (dis[there_pair.second] > path)
			{
				dis[there_pair.second] = path;
				pq.push({ path, there_pair.second });
			}
		}
	}
}

void ComeBFS(int target_pos, int init_pos)
{
	vector<int> dis(1001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, target_pos });
	dis[target_pos] = 0;

	while (pq.empty() == false)
	{
		pair<int, int> here_pair = pq.top();
		int here_cost = here_pair.first;
		int here_pos = here_pair.second;
		pq.pop();

		if (here_pos == init_pos)
		{
			come_distance[init_pos] = (come_distance[init_pos] > here_cost) ? here_cost : come_distance[init_pos];
		}

		if (here_cost > dis[here_pos])
			continue;

		for (int there_index = 0; there_index < adjacent[here_pos].size(); ++there_index)
		{
			pair<int, int> there_pair = adjacent[here_pos][there_index];
			int path = here_cost + there_pair.first;
			if (dis[there_pair.second] > path)
			{
				dis[there_pair.second] = path;
				pq.push({ path, there_pair.second });
			}
		}
	}
}

int main(void)
{
	// N: 학생 수
	// M: 단방향 도로 수
	// X: 모이는 마을
	int N, M, X;
	cin >> N >> M >> X;
	
	SetAdjacent(M);
	
	for (int i = 1; i <= N; ++i)
	{
		GoBFS(i, X);
		ComeBFS(X, i);
	}
	
	int max_value = 0;
	for (int i = 1; i <= N; ++i)
	{
		int total_distance = go_distance[i] + come_distance[i];
		max_value = (max_value > total_distance) ? max_value : total_distance;
	}

	cout << max_value << "\n";
	return 0;
}