#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> dp;

int BinarySearchLowerBound(int left, int right, int val)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (dp[mid] >= val)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

int main(void)
{
	int N;
	cin >> N;

	arr.resize(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	
	for (int i = 0; i < N; ++i)
	{
		if (dp.size() == 0 || dp.back() < arr[i])
		{
			dp.emplace_back(arr[i]);
		}
		else
		{
			int idx = BinarySearchLowerBound(0, dp.size() - 1, arr[i]);
			dp[idx] = arr[i];
		}
	}

	cout << dp.size() << "\n";
	return 0;
}