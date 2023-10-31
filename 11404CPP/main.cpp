#include <iostream>
#include <vector>

#define INF (~0U >> 2)

using namespace std;


int main(void)
{

	int n, m;
	cin >> n;
	cin >> m;

	vector<vector<int>> adjacent(n + 1, vector<int>(n + 1, INF));

	for (int i = 0; i < m; ++i)
	{
		int start_pos, target_pos, cost;
		cin >> start_pos >> target_pos >> cost;
		if (adjacent[start_pos][target_pos] > cost)
			adjacent[start_pos][target_pos] = cost;
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int y = 1; y <= n; ++y)
		{
			for (int x = 1; x <= n; ++x)
			{
				if (y != x)
				{
					if (adjacent[y][x] > adjacent[y][k] + adjacent[k][x])
						adjacent[y][x] = adjacent[y][k] + adjacent[k][x];
				}
			}
		}
	}

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			if (adjacent[y][x] == INF)
			{
				cout << "0" << " ";
			}
			else
			{
				cout << adjacent[y][x] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}