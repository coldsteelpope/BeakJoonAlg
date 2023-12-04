#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<int>> adjacentList;
vector<int> distances;

void SetAdjacentList(int N, int M)
{
	adjacentList.resize(N + 1);
	distances.resize(N + 1, (~0U >> 2));
	for (int i = 0; i < M; ++i)
	{
		int start, target;
		cin >> start >> target;
		adjacentList[start].push_back(target);
	}
}

int main(void)
{
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	SetAdjacentList(N, M);

	queue<pair<int, int>> q;
	q.push({ 0, X });
	// ��� ���� X���� ��� ���� X�� ���� �ִ� �Ÿ��� �׻� 0�̶�� �����Ѵ�.
	// �� ������ �����ϰ� Ǯ����.
	distances[X] = 0;

	while (q.empty() == false)
	{
		pair<int, int> here = q.front();
		int hereDist = here.first;
		int herePos = here.second;

		q.pop();

		if (hereDist > distances[herePos])
		{
			continue;
		}

		for (int thereIdx = 0; thereIdx < adjacentList[herePos].size(); ++thereIdx)
		{
			int nextDist = hereDist + 1;
			int there = adjacentList[herePos][thereIdx];
			if (nextDist < distances[there])
			{
				distances[there] = nextDist;
				q.push({ nextDist, there });
			}
		}
	}
	
	vector<int> answers;
	for (int node = 1; node <= N; ++node)
	{
		if (distances[node] == K)
		{
			answers.emplace_back(node);
		}
	}
	
	if (answers.size() == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		// ������������ �����ؼ� ����ؾ� �Ѵٴ� ������ �� ���� ���ߴ�.
		std::sort(answers.begin(), answers.end());
		for (int i = 0; i < answers.size(); ++i)
		{
			cout << answers[i] << endl;
		}
	}

	return 0;
}