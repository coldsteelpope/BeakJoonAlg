#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
	int n, w, L;
	cin >> n >> w >> L;

	int answer = 0;
	int bridgeSum = 0;
	deque<pair<int, int>> bridge;
	deque<int> trucks;


	for (int i = 0; i < n; ++i)
	{
		int truck;
		cin >> truck;
		trucks.push_back(truck);
	}

	while (trucks.empty() == false || bridge.empty() == false)
	{
		for (int i = 0; i < bridge.size(); ++i)
		{
			++bridge[i].first;
		}

		if (bridge.empty() == false && bridge.front().first == w)
		{
			bridgeSum -= bridge.front().second;
			bridge.pop_front();
		}

		if (trucks.empty() == false)
		{
			bool possibleUsingBridge = (trucks.front() + bridgeSum <= L) && (bridge.size() + 1 <= w);
			if (possibleUsingBridge == true)
			{
				bridgeSum += trucks.front();
				bridge.push_back(make_pair(0, trucks.front()));
				trucks.pop_front();
			}
		}
		++answer;
	}

	cout << answer << "\n";
	return 0;
}