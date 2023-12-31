#include <iostream>
#include <vector>
#include <utility>

using namespace std;

inline int GetMin(int num1, int num2)
{
	return num1 > num2 ? num2 : num1;
}

int main(void)
{
	int N;
	cin >> N;

	vector<int> dp;
	dp.resize(N + 1, 1);

	dp[0] = 0;
	dp[1] = 0;
	for (int num = 4; num <= N; ++num)
	{
		dp[num] = num;
	}

	for (int num = 2; num <= N; ++num)
	{
		if (num % 2 == 0)
		{
			dp[num] = GetMin(dp[num], dp[num / 2]);
		}
		if (num % 3 == 0)
		{
			dp[num] = GetMin(dp[num], dp[num / 3]);
		}
		dp[num] = GetMin(dp[num], dp[num - 1]) + 1;
	}

	cout << dp[N] << "\n";
	return 0;
}