#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
vector<int> nums;

inline int GetMax(int a, int b)
{
	return a > b ? a : b;
}

void SetDP(int n)
{
	dp[0] = nums[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i] = GetMax(nums[i], GetMax(nums[i] + nums[i - 1], nums[i] + dp[i - 1]));
	}
}

void SetNums(int n)
{
	nums.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
}

int main(void)
{
	int n;
	cin >> n;
	SetNums(n);
	SetDP(n);
	
	int maxValue = dp[0];
	for (int i = 1; i < n; ++i)
	{
		maxValue = GetMax(maxValue, dp[i]);
	}

	cout << maxValue << "\n";
	return 0;
}