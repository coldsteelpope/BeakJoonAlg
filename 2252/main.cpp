#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> inDegree;
vector<vector<int>> adjacentList;


vector<int> TopologySort(int N)
{
	vector<int> result;
	
	queue<int> q;
	for (int node = 1; node <= N; ++node)
	{
		if (inDegree[node] == 0)
			q.push(node);
	}

	for (int t = 1; t <= N; ++t)
	{
		if (q.empty() == true)
		{
			cout << "사이클 발생" << endl;
			return result;
		}
		else
		{
			int node = q.front();
			q.pop();

			result.push_back(node);
			for (int there_idx = 0; there_idx < adjacentList[node].size(); ++there_idx)
			{
				int there_node = adjacentList[node][there_idx];
				--inDegree[there_node];
				if (inDegree[there_node] == 0)
				{
					q.push(there_node);
				}
			}
		}
	}
	return result;
}

void SetInDegree(int N)
{
	inDegree.resize(N + 1, 0);
}

void SetAdjacentList(int N, int M)
{
	adjacentList.resize(N + 1);
	for (int m = 0; m < M; ++m)
	{
		int start_node, target_node;
		cin >> start_node >> target_node;
		adjacentList[start_node].push_back(target_node);
		++inDegree[target_node];
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	SetInDegree(N);
	SetAdjacentList(N, M);
	
	vector<int> result;
	result = TopologySort(N);
	
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	return 0;
}