#include <iostream>
#include <vector>

#define INF (~0U >> 2)

using namespace std;

vector<vector<int>> dist;

int main(void)
{
	int V, E;
	cin >> V >> E;

	dist.resize(V + 1, vector<int>(V + 1, INF));
	for (int i = 0; i < E; ++i)
	{
		int start_pos, target_pos, cost;
		cin >> start_pos >> target_pos >> cost;
		dist[start_pos][target_pos] = cost;
	}
	
	for (int k = 1; k <= V; ++k)
	{
		for (int i = 1; i <= V; ++i)
		{
			for (int j = 1; j <= V; ++j)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int answerLen = INF;
	for (int i = 1; i <= V; ++i)
	{
		answerLen = (answerLen > dist[i][i]) ? dist[i][i] : answerLen;
	}

	if (answerLen == INF)
		cout << -1 << endl;
	else
		cout << answerLen << endl;

	return 0;
}