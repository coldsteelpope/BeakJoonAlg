#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> budget;

int main(void)
{
	cin >> n;
	for (auto i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		budget.push_back(x);
	}

	cin >> m;
	std::sort(budget.begin(), budget.end());
	
	int start = 0;
	int end = budget[n - 1];
	int result(0);

	while (start <= end)
	{
		int sum(0);
		int mid = (start + end) / 2;
		for (auto i = 0; i < n; ++i)
		{
			sum += min(budget[i], mid);
		}

		if (m >= sum)
		{
			result = mid;
			start = mid + 1;
		}
		else
		{
			// 차피 mid로 m을 만들 수 없기 때문에
			end = mid - 1;
		}
	}

	cout << result << endl;
	return 0;
}