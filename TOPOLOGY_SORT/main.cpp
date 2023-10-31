#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

// inDegree: 진입 차수를 의미한다.
int n, inDegree[MAX];
// a => 각 정점에 연결되어 있는 모든 노드 정보들을 담을 수 있도록 만들어준다.
vector<int> a[MAX];

void topologySort()
{
	int result[MAX];
	queue<int> q;

	// 진입 차수가 0인 노드를 큐에 삽입한다.
	for (int i = 1; i <= n; ++i)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}

	// 위상 정렬이 완전히 수행되려면, 정확히 N개의 노드를 방문해야 한다.
	for (int i = 1; i <= n; ++i)
	{
		// n개를 방문하기 전에 큐가 빈다면 사이클이 발생한 것이다.
		if (q.empty())
		{
			cout << "사이클이 발생했습니다." << endl;
			return;
		}
		int x = q.front();
		q.pop();

		result[i] = x;
		for (int i = 0; i < a[x].size(); ++i)
		{
			int y = a[x][i];
			--inDegree[y];
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입합니다.
			if (inDegree[y] == 0)
			{
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << result[i] << " ";
	}
}

int main(void)
{
	n = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	topologySort();
	
}