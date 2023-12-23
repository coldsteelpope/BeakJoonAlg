#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> dp;

int BinarySearchLowerBound(int left, int right, int value)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (dp[mid] >= value)
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
	dp.resize(N, 1);

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int dpLen = 1;
	for (int i = 1; i < N; ++i)
	{
		if (dp[dpLen - 1] < arr[i])
		{
			dp[dpLen++] = arr[i];
		}
		else
		{
			int idx = BinarySearchLowerBound(0, dpLen - 1, arr[i]);
			dp[idx] = arr[i];
		}
	}

	cout << dpLen << "\n";
	return 0;
}