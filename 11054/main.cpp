#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> sum;
vector<int> dp;

inline int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int N;
	cin >> N;

	arr.resize(N);
	dp.resize(N);
	sum.resize(N);
	
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = GetMax(dp[i], dp[j] + 1);
			}
		}
		sum[i] += dp[i];
	}

	for (int i = N - 1; i >= 0; --i)
	{
		dp[i] = 1;
		for (int j = N - 1; j > i; --j)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = GetMax(dp[i], dp[j] + 1);
			}
		}
		sum[i] += dp[i];
	}

	int max_num = 0;
	for (int i = 0; i < sum.size(); ++i)
		max_num = (max_num > sum[i]) ? max_num : sum[i];

	cout << max_num - 1 << endl;
	return 0;
}