#include <iostream>
using namespace std;

long long dp[16] = { 0, };

int main(void)
{
	dp[0] = 2;
	
	long long iMul = 1;
	for (int i = 1; i <= 15; ++i)
	{
		dp[i] = dp[i - 1] + iMul;
		iMul *= 2;
	}

	int iN;
	cin >> iN;
	long long llResult = dp[iN] * dp[iN];
	cout << llResult << endl;
	
	return 0;
}