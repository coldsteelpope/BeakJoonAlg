#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<pair<int, int>> schedules;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int startT, endT;
		cin >> startT >> endT;
		schedules.push_back({ startT, endT });
	}

	std::sort(schedules.begin(), schedules.end(), [](pair<int, int> a, pair<int, int> b)->bool { 
		if (a.second == b.second)
		{
			return a.first < b.first;
		}
		else
		{
			return a.second < b.second;
		}
	});
	
	int cur = 0;
	int answer = 1;
	int schedulesSize = schedules.size();
	for (int i = 1; i < schedulesSize; ++i)
	{
		// 현재 사용 중인 회의실의 끝난 시간과 앞으로 할 회의 시작 시간을 비교한다.
		if (schedules[cur].second <= schedules[i].first)
		{
			// 만약 회의실 끝난 시간이 시작 시간보다 작거나 같다면 회의 시작 가능하다.
			cur = i;
			++answer;
		}
	}
	cout << answer << "\n";
	return 0;
}