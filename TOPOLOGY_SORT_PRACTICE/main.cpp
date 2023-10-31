#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> inDegree;
vector<vector<int>> adjacentList;

// n: ���� ����
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

	// ���� ������ ������ ����Ƿ���, ��Ȯ�� N���� ��带 �湮�ؾ� �Ѵ�.
	for (int i = 1; i <= n; ++i)
	{
		if (q.empty())
		{
			cout << "����Ŭ �߻�" << endl;
			return;
		}
		else
		{
			// ť���� ���Ҹ� ����, ����� ��� ������ �����մϴ�.
			int node = q.front();
			q.pop();

			result.push_back(node);
			// ���� ���� ���Ŀ� ���� ������ 0�� �� ������ ť�� �����մϴ�.
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
