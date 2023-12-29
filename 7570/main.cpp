#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
vector<int> dp;

inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

int main(void)
{
	int N;
	cin >> N;
	
	nums.resize(N + 1, 0);
	dp.resize(N + 1, 0);
	
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	int maxSequence = 0;
	for (int i = 0; i < N; ++i)
	{
		dp[nums[i]] = dp[nums[i] - 1] + 1;
		maxSequence = GetMax(maxSequence, dp[nums[i]]);
	}

	cout << N - maxSequence << "\n";
	return 0;
}