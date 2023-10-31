#include <iostream>
#include <vector>
#define INF 10000

using namespace std;

vector<int> items;
vector<vector<int>> adjacentMatrix;

inline int GetMin(int a, int b)
{
	return a > b ? b : a;
}

int main(void)
{
	// n: 지역의 개수
	// m: 수색 범위
	// r: 길의 개수
	int n, m, r;
	cin >> n >> m >> r;

	items.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> items[i];

	adjacentMatrix = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < r; ++i)
	{
		int start, target, cost;
		cin >> start >> target >> cost;
		adjacentMatrix[start][target] = cost;
		adjacentMatrix[target][start] = cost;
	}
	
	for (int i = 1; i <= n; ++i)
		adjacentMatrix[i][i] = 0;

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				adjacentMatrix[i][j] = GetMin(adjacentMatrix[i][j], adjacentMatrix[i][k] + adjacentMatrix[k][j]);
			}
		}
	}

	int max_items_num = 0;
	for (int here = 1; here <= n; ++here)
	{
		int items_num = items[here];
		for (int there = 1; there <= n; ++there)
		{
			int dist = adjacentMatrix[here][there];
			if (dist <= m && here != there)
			{
				items_num += items[there];
			}
		}
		max_items_num = (items_num > max_items_num) ? items_num : max_items_num;
	}

	cout << max_items_num << endl;
	return 0;
}