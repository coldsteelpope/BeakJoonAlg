#include <iostream>
#include <vector>

using namespace std;

vector<int> heights;
vector<int> dp;

int main(void)
{
	int N;

	cin >> N;
	
	heights.resize(N, 0);
	dp.resize(N, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> heights[i];
	}

	for (int i = 1; i < N ; ++i)
	{
		if (heights[i - 1] <= heights[i])
		{
			for (int p = dp[i - 1] - 1; p >= 0; --p)
			{
				if (heights[p] >= heights[i])
				{
					dp[i] = p + 1;
					break;
				}
			}
		}
		else
		{
			dp[i] = i;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		cout << dp[i] << " ";
	}
	return 0;
}