#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

int N;
vector<int> adjacentList[MAX];
bool discovered[MAX] = { 0, };
int parent[MAX] = { 0, };

void bfs()
{
	queue<int> q;
	q.push(1);
	discovered[1] = true;

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < adjacentList[here].size(); ++i)
		{
			int there = adjacentList[here][i];
			if (!discovered[there])
			{
				parent[there] = here;
				discovered[there] = true;
				q.push(there);
			}
		}
	}
}



int main(void)
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		adjacentList[x].push_back(y);
		adjacentList[y].push_back(x);
	}

	bfs();
	for (int i = 2; i <= N; ++i)
		cout << parent[i] << "\n";

	return 0;
}