#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX_USER 101

using namespace std;

vector<int> g_adjacentList[MAX_USER];

void SetAdjacentList(int N, int M)
{
	for (int i = 0; i < M; ++i)
	{
		int start, target;
		cin >> start >> target;
		g_adjacentList[start].emplace_back(target);
		g_adjacentList[target].emplace_back(start);
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	SetAdjacentList(N, M);

	vector<pair<int, int>> FriendDists;
	
	for (int node = 1; node <= N; ++node)
	{
		vector<int> DistArr(N + 1, (~0U >> 2));
		
		queue<pair<int, int>> Queue;
		Queue.push({ 0, node });
		DistArr[node] = 0;

		while (Queue.empty() == false)
		{
			pair<int, int> Here = Queue.front();
			int HerePos = Here.second;
			int HereDist = Here.first;

			Queue.pop();

			if (DistArr[HerePos] < HereDist)
			{
				continue;
			}

			for (int ThereIdx = 0; ThereIdx < g_adjacentList[HerePos].size(); ++ThereIdx)
			{
				int NextPos = g_adjacentList[HerePos][ThereIdx];
				if (DistArr[NextPos] > DistArr[HerePos] + 1)
				{
					DistArr[NextPos] = DistArr[HerePos] + 1;
					Queue.push({ DistArr[NextPos], NextPos });
				}
			}
		}

		int Sum = 0;
		for (int node = 1; node <= N; ++node)
		{
			Sum += DistArr[node];
		}

		FriendDists.push_back({ Sum, node });
	}

	std::sort(FriendDists.begin(), FriendDists.end());
	cout << FriendDists.front().second << endl;

	return 0;
}