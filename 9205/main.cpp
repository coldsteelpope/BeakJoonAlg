#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int start_x, start_y, target_x, target_y;
vector<pair<int, int>> stores;
vector<bool> visited;

inline int GetAbs(int a)
{
	return a > 0 ? a : -a;
}

void SetPos()
{
	int n;
	cin >> n;
	
	stores.resize(n + 1);
	visited.resize(n + 1, false);

	cin >> start_x >> start_y;
	
	for (int store_index = 1; store_index <= n; ++store_index)
	{
		int store_x, store_y;
		cin >> store_x >> store_y;
		stores[store_index].first = store_x;
		stores[store_index].second = store_y;
	}

	cin >> target_x >> target_y;
}

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	
	bool is_happy_now = false;
	while (q.empty() == false)
	{
		pair<int, int> current_pos = q.front();
		q.pop();

		if (GetAbs(current_pos.first - target_x) + GetAbs(current_pos.second - target_y) <= 1000)
		{
			is_happy_now = true;
			break;
		}

		for (int i = 1; i < stores.size(); ++i)
		{
			if (visited[i] == true)
				continue;

			int x_len = GetAbs(current_pos.first - stores[i].first);
			int y_len = GetAbs(current_pos.second - stores[i].second);

			if (x_len + y_len <= 1000)
			{
				visited[i] = true;
				q.push({ stores[i].first, stores[i].second });
			}
		}
	}

	if (is_happy_now == true)
		cout << "happy" << endl;
	else
		cout << "sad" << endl;
}

int main(void)
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		SetPos();
		BFS();
		stores.clear();
		visited.clear();
	}

	string str;
	true;
}