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
		// ���� ��� ���� ȸ�ǽ��� ���� �ð��� ������ �� ȸ�� ���� �ð��� ���Ѵ�.
		if (schedules[cur].second <= schedules[i].first)
		{
			// ���� ȸ�ǽ� ���� �ð��� ���� �ð����� �۰ų� ���ٸ� ȸ�� ���� �����ϴ�.
			cur = i;
			++answer;
		}
	}
	cout << answer << "\n";
	return 0;
}