#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{

	int N;
	vector<pair<int, int>> schedules;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int startT, endT;
		cin >> startT >> endT;
		schedules.push_back({ endT, startT });
	}
	
	std::sort(schedules.begin(), schedules.end(), [](pair<int, int> a, pair<int, int> b)->bool {return a.second < b.second; });

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(schedules[0]);
	int maxValue = 1;
	for (int i = 1; i < N; ++i)
	{
		int startT = schedules[i].second;
		while (pq.empty() == false && pq.top().first <= startT)
		{
			pq.pop();
		}
		pq.push(schedules[i]);
		maxValue = (maxValue > pq.size()) ? maxValue : pq.size();
	}
	cout << maxValue << "\n";
	return 0;
}