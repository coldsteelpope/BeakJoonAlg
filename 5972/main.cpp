#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<pair<int, int>>> adjacentList;
vector<int> lens;

int main(void)
{
	int N, M;
	cin >> N >> M;

	adjacentList.resize(N + 1);
	lens.resize(N + 1, (~0U >> 2));

	for (int i = 0; i < M; ++i)
	{
		int start, target, cost;
		cin >> start >> target >> cost;
		adjacentList[start].push_back(make_pair(target, cost));
		adjacentList[target].push_back(make_pair(start, cost));
	}

	/*
	queue 대신 priority_queue를 사용하면 140ms -> 120ms 로 시간이 줄어든다.
	queue를 사용하면 모든 노드에 접근하여 최소 비용을 찾는다.
	priority_queue를 사용하면 항상 최소 비용을 가지는 노드에 접근한다.
	미리 최소 비용으로 lens을 갱신하기 때문에, 나중에 큰 비용이 드는 노드에 접근해도 바로 무시가 가능하다.
	*/
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//queue<pair<int, int>> q;
	pq.push(make_pair(1, 0));
	lens[1] = 0;
	
	while (pq.empty() == false)
	{
		pair<int, int> here = pq.top();
		
		int herePos = here.first;
		int hereLen = here.second;

		pq.pop();

		if (hereLen > lens[herePos])
		{
			continue;
		}

		for (int i = 0; i < adjacentList[herePos].size(); ++i)
		{
			pair<int, int> there = adjacentList[herePos][i];

			int therePos = there.first;
			int thereCost = there.second;

			int nextLen = hereLen + thereCost;
			if (nextLen < lens[therePos])
			{
				lens[therePos] = nextLen;
				pq.push(make_pair(therePos, nextLen));
			}
		}
	}

	cout << lens[N] << "\n";
	return 0;
}