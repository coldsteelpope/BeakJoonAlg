#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> dp;

inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
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

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = GetMax(dp[i], dp[j] + 1);
			}
		}
	}

	int maxValue = 0;
	for (int i = 0; i < dp.size(); ++i)
	{
		maxValue = GetMax(maxValue, dp[i]);
	}
	cout << maxValue << endl;
	return 0;
}