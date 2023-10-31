#include <iostream>

using namespace std;

unsigned long long dp[10001] = { 0, };

int main(void)
{
	int n;
	cin >> n;

	if (n == 0)
	{
		cout << 0 << endl;
	}
	else if (n == 1 || n == 2)
	{
		cout << 1 << endl;
	}
	else
	{
		dp[0] = 0;
		dp[1] = dp[2] = 1;
		for (int i = 3; i <= n; ++i)
			dp[i] = dp[i - 1] + dp[i - 2];
		cout << dp[n] << endl;
	}
	return 0;
}