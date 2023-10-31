#include <iostream>

#define INF 999999999

using namespace std;

int colors[1001][3] = { 0, };
int dp[1001][3] = { 0, };

inline int GetMin(int a, int b)
{
	return a > b ? b : a;
}

void SetDP(int N)
{
	for (int i = 2; i <= N; ++i)
	{
		dp[i][0] = GetMin(dp[i - 1][1], dp[i - 1][2]) + colors[i][0];
		dp[i][1] = GetMin(dp[i - 1][0], dp[i - 1][2]) + colors[i][1];
		dp[i][2] = GetMin(dp[i - 1][0], dp[i - 1][1]) + colors[i][2];
	}
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> colors[i][0] >> colors[i][1] >> colors[i][2];

	int answer = INF;
	// r
	dp[1][0] = colors[1][0];
	dp[1][1] = dp[1][2] = INF;
	SetDP(N);
	answer = GetMin(answer, GetMin(dp[N][1], dp[N][2]));

	// g
	dp[1][1] = colors[1][1];
	dp[1][0] = dp[1][2] = INF;
	SetDP(N);
	answer = GetMin(answer, GetMin(dp[N][0], dp[N][2]));

	// b
	dp[1][2] = colors[1][2];
	dp[1][0] = dp[1][1] = INF;
	SetDP(N);
	answer = GetMin(answer, GetMin(dp[N][0], dp[N][1]));

	cout << answer << endl;
	return 0;
}