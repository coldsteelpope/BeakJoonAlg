#include <iostream>
#include <vector>

#define MAX_RELATED_NUM 5

using namespace std;

vector<vector<int>> adjacentList;
vector<bool> visited;

void DFS(int here, int count)
{
	if (count == MAX_RELATED_NUM)
	{
		// ���� ������ ���⼭ �ٷ� �����ϰ� �ߴ��� ����ߴ�. �� ���� �����?
		cout << 1 << "\n";
		exit(0);
	}
	
	for (int thereIdx = 0; thereIdx < adjacentList[here].size(); ++thereIdx)
	{
		int there = adjacentList[here][thereIdx];
		if (visited[there] == true)
		{
			continue;
		}
		visited[there] = true;
		DFS(there, count + 1);
		visited[there] = false;
	}
	// ������ ���� ������ �ش� ����� visited�� false�� �ٲ�����Ѵ�.
	// �� ������ ���ݰ� �ٸ� ���� �������� �ش� ��带 �湮�� �� �ֱ� �����̴�.
	/*
	�ݷ�)
	5 6
	0 1
	1 4
	1 2
	1 3
	2 4
	3 4
	output: 0
	answer: 1
	*/
}

void Check(int N)
{
	for (int node = 0; node < N; ++node)
	{
		visited.resize(N);
		visited[node] = true;
		DFS(node, 1);
		visited.clear();
	}
	cout << 0 << "\n";
}

void SetAdjacentList(int N, int M)
{
	adjacentList.resize(N);
	for (int i = 0; i < M; ++i)
	{
		int start, target;
		cin >> start >> target;
		adjacentList[start].emplace_back(target);
		adjacentList[target].emplace_back(start);
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	SetAdjacentList(N, M);
	Check(N);
	return 0;
}