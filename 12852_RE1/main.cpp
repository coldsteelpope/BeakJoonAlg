#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

inline int GetMin(int num1, int num2)
{
	return num1 > num2 ? num2 : num1;
}

int main(void)
{
	int N;
	cin >> N;
	dp.resize(N + 1, 1);
	
	dp[1] = 0;
	for (int num = 4; num <= N; ++num)
	{
		dp[num] = num;
	}

	for (int num = 4; num <= N; ++num)
	{
		if (num % 3 == 0)
		{
			dp[num] = GetMin(dp[num], dp[num / 3]);
		}

		if (num % 2 == 0)
		{
			dp[num] = GetMin(dp[num], dp[num / 2]);
		}

		dp[num] = GetMin(dp[num], dp[num - 1]) + 1;
	}

	cout << dp[N] << "\n";

	while (N != 0)
	{
		cout << N << " ";

		if (N == 1)
		{
			break;
		}

		if (dp[N] == dp[N - 1] + 1)
		{
			N = N - 1;
		}
		else if (N % 2 == 0 && dp[N] == dp[N / 2] + 1)
		{
			N = N / 2;
		}
		else if (N % 3 == 0 && dp[N] == dp[N / 3] + 1)
		{
			N = N / 3;
		}
	}

	return 0;
}