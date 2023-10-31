#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int start_x, start_y;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int target_x, target_y;

inline int GetAbs(int a)
{
	return a > 0 ? a : -a;
}

void SetPos()
{
	int n;
	cin >> n;
	cin >> start_x >> start_y;
	for (int store_i = 0; store_i < n; ++store_i)
	{
		int store_x, store_y;
		cin >> store_x >> store_y;
		int len = GetAbs(store_x) + GetAbs(store_y);

	}
}

int main(void)
{
	int T;
	cin >> T;
	
}