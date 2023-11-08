#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adjacentList;

int Dij(int start, int target, int N)
{
	//vector<bool> discovered(N + 1, false);
	vector<int> dist(N + 1, (~0U >> 2));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	
	int answer = 0;
	while (pq.empty() == false)
	{
		pair<int, int> here = pq.top();
		
		int hereCost = here.first;
		int herePos = here.second;
		pq.pop();
		
		if (hereCost > dist[herePos])
			continue;

		if (target == herePos)
			break;

		for (int thereIdx = 0; thereIdx < adjacentList[herePos].size(); ++thereIdx)
		{
			pair<int, int> there = adjacentList[herePos][thereIdx];
			int nextDist = there.first + hereCost;
			if (dist[there.second] > nextDist)
			{
				dist[there.second] = nextDist;
				pq.push({ nextDist, there.second });
			}
		}
	}

	return (dist[target] == (~0U >> 2)) ? 0 : dist[target];
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	adjacentList.resize(N + 1);
	for (int n = 0; n < N - 1; ++n)
	{
		int start, target, cost;
		cin >> start >> target >> cost;
		adjacentList[start].push_back({ cost, target });
		adjacentList[target].push_back({ cost, start });
	}

	for (int m = 0; m < M; ++m)
	{
		int start, target;
		cin >> start >> target;

		int answer = Dij(start, target, N);
		cout << answer << endl;
	}
	
	return 0;
}