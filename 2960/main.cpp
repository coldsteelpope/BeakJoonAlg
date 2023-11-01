#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<bool> dp;
vector<int> primeNums;

int main(void)
{
	int N, K;
	cin >> N >> K;
	dp.resize(N + 1, false);
	
	int check = 0;
	int answer = -1;
	
	dp[0] = dp[1] = true;
	for (int num = 2; num <= N; ++num)
	{
		bool isFind = false;
		if (dp[num] == false)
		{
			for (int k = num; k <= N; k += num)
			{
				if (dp[k] == true)
					continue;
				dp[k] = true;
				++check;
				if (check == K)
				{
					isFind = true;
					answer = k;
					break;
				}
			}
		}
		if (isFind)
			break;
	}
	cout << answer << endl;

	return 0;
}