#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, bool> discovered;
vector<int> min_time(100001, 2147483647);

int main(void)
{
	int N, K;
	cin >> N >> K;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, N });
	discovered[N] = true;
	min_time[N] = 0;

	while (pq.empty() == false)
	{
		pair<int, int> here = pq.top();
		
		int current_loc = here.second;
		int current_t = here.first;

		discovered[here.second] = true;

		if (here.second == K)
		{
			// 다시 돌아갈 수 있을 때 => break 문이 없다.
			// 다시 돌아갈 수 없을 때 => break 문이 없다.
			min_time[K] = (min_time[K] > current_t) ? current_t : min_time[K];
		}

		if (current_loc + 1 <= 100000 && discovered[current_loc + 1] == false)
			pq.push({ current_t + 1, current_loc + 1 });
		if (current_loc - 1 >= 0 && discovered[current_loc - 1] == false)
			pq.push({ current_t + 1, current_loc - 1 });
		if (current_loc * 2 <= 100000 && current_loc != 0 && discovered[current_loc * 2] == false)
			pq.push({ current_t, current_loc * 2 });
		pq.pop();
	}

	cout << min_time[K] << endl;
	return 0;
}