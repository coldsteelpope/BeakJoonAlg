#include <iostream>
using namespace std;

#define MAX_LEN 10001
// 어떻게 2차원 DP를 생각할 수 있을까?
int dp[MAX_LEN][4] = { 0, };

int main(void)
{
	dp[1][1] = 1;
	dp[2][1] = dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;
	

	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; ++testCase)
	{
		int N;
		cin >> N;
		for (int i = 4; i <= N; ++i)
		{
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
		}
		cout << dp[N][1] + dp[N][2] + dp[N][3] << endl;
	}
	return 0;
}