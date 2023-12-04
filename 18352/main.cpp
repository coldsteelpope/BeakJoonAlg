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
	// 출발 도시 X에서 출발 도시 X로 가는 최단 거리는 항상 0이라고 가정한다.
	// 이 문장을 무시하고 풀었다.
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
		// 오름차순으로 정렬해서 출력해야 한다는 지문을 잘 읽지 못했다.
		std::sort(answers.begin(), answers.end());
		for (int i = 0; i < answers.size(); ++i)
		{
			cout << answers[i] << endl;
		}
	}

	return 0;
}