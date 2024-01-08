#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

vector<int> heights;
vector<int> dp;
stack<pair<int, int>> s;

int main(void)
{
	int N;
	cin >> N;
	
	heights.resize(N + 1, 0);
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> heights[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		if (s.empty() == true)
		{
			dp.emplace_back(0);
			s.push(make_pair(i, heights[i]));
		}
		else
		{
			while (s.empty() == false && s.top().second < heights[i])
			{
				s.pop();
			}

			if (s.empty() == true)
			{
				dp.emplace_back(0);
			}
			else
			{
				dp.emplace_back(s.top().first);
			}
			s.push(make_pair(i, heights[i]));
		}
	}

	for (int i = 0; i < N; ++i)
	{
		cout << dp[i] << " ";
	}
	return 0;
}