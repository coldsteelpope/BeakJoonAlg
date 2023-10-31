#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> inDegree;
vector<vector<int>> adjacentList;

// n: 정점 개수
vector<int> topologySort(int n)
{
	vector<int> result;
	result.resize(n + 1, 0);

	queue<int> q;

	for (int i = 1; i <= n; ++i)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	// 위상 정렬이 완전히 수행되려면, 정확히 N개의 노드를 방문해야 한다.
	for (int i = 1; i <= n; ++i)
	{
		if (q.empty())
		{
			cout << "사이클 발생" << endl;
			return;
		}
		else
		{
			// 큐에서 원소를 꺼내, 연결된 모든 간선을 제거합니다.
			int node = q.front();
			q.pop();

			result.push_back(node);
			// 간선 제거 이후에 진입 차수가 0이 된 정점을 큐에 삽입합니다.
			for (int there_idx = 0; there_idx < adjacentList[node].size(); ++there_idx)
			{
				int next_node = adjacentList[node][there_idx];
				--inDegree[next_node];
				if (inDegree[next_node] == 0)
					q.push(next_node);
			}
		}
	}
}
