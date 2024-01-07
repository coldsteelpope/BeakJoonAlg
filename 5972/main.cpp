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
	queue ��� priority_queue�� ����ϸ� 140ms -> 120ms �� �ð��� �پ���.
	queue�� ����ϸ� ��� ��忡 �����Ͽ� �ּ� ����� ã�´�.
	priority_queue�� ����ϸ� �׻� �ּ� ����� ������ ��忡 �����Ѵ�.
	�̸� �ּ� ������� lens�� �����ϱ� ������, ���߿� ū ����� ��� ��忡 �����ص� �ٷ� ���ð� �����ϴ�.
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