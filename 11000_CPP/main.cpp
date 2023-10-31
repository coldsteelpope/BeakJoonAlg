#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> schedulers;

int main(void)
{
	int N;
	cin >> N;

	
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; ++i)
	{
		int start_time, end_time;
		cin >> start_time >> end_time;
		schedulers.push_back({ start_time, end_time });
	}

	sort(schedulers.begin(), schedulers.end());
	
	pq.push(schedulers[0].second);

	for (int i = 1; i < N; ++i)
	{
		if (pq.top() > schedulers[i].first)
		{
			pq.push(schedulers[i].second);
			//pq.push({ schedulers[i].first, schedulers[i].second });
		}
		else
		{
			pq.pop();
			pq.push(schedulers[i].second);
			//pq.push({ schedulers[i].first, schedulers[i].second });
		}
	}

	cout << pq.size();
	return 0;
}