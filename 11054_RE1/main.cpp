#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> r_dp;
vector<int> l_dp;

inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

int main(void)
{
	int N;
	cin >> N;

	arr.resize(N, 0);
	r_dp.resize(N, 1);
	l_dp.resize(N, 1);

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j])
			{
				r_dp[i] = GetMax(r_dp[i], r_dp[j] + 1);
			}
		}
	}

	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = N - 1; j > i; --j)
		{
			if (arr[i] > arr[j])
			{
				l_dp[i] = GetMax(l_dp[i], l_dp[j] + 1);
			}
		}
	}

	int maxValue = 0;
	for (int i = 0; i < N; ++i)
	{
		int sum = r_dp[i] + l_dp[i];
		maxValue = GetMax(maxValue, sum);
	}
	cout << maxValue - 1 << endl;
	return 0;
}