#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adjacentList;

// discovered �迭�� ����ص� ������
// parents �迭�� ����ؼ�, �湮 ���θ� Ȯ���� �� �ִ�.
// ���� ���, 0�̸� �湮���� ���� ���, 0�� �ƴ� �ٸ� ���� �湮�� ���

vector<bool> discovered;
vector<int> parents;

void SetAdjacentList(int N)
{
	adjacentList.resize(N + 1);
	discovered.resize(N + 1, false);
	parents.resize(N + 1, 0);

	for (int n = 0; n < N - 1; ++n)
	{
		int start, target;
		cin >> start >> target;
		adjacentList[start].emplace_back(target);
		adjacentList[target].emplace_back(start);
	}
}

int main(void)
{
	int N; cin >> N;
	SetAdjacentList(N);

	queue<int> q;
	q.push(1);
	discovered[1] = true;
	
	while (q.empty() == false)
	{
		int parent = q.front();
		q.pop();

		for (int thereIdx = 0; thereIdx < adjacentList[parent].size(); ++thereIdx)
		{
			int there = adjacentList[parent][thereIdx];
			if (discovered[there] == true)
			{
				continue;
			}
			discovered[there] = true;
			parents[there] = parent;
			q.push(there);
		}
	}
	
	for (int node = 2; node <= N; ++node)
	{
		cout << parents[node] << "\n";
	}
	return 0;
}