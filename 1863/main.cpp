#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> positions;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int currentPosition, height;
		cin >> currentPosition >> height;
		positions.push_back(make_pair(currentPosition, height));
	}

	stack<int> heights;
	int answer = 0;
	int positionsLen = positions.size();
	for (int i = 0; i < positionsLen; ++i)
	{
		pair<int, int> here = positions[i];
		if (heights.empty() == true || heights.top() <= here.second)
		{
			if (here.second != 0)
			{
				heights.push(here.second);
			}
		}
		else
		{
			int currentTop = heights.top();
			while (heights.empty() == false && here.second < heights.top())
			{
				if (currentTop == heights.top())
				{
					heights.pop();
				}
				else
				{
					currentTop = heights.top();
					++answer;
				}
			}
			++answer;
			if (here.second != 0)
			{
				heights.push(here.second);
			}
		}
	}


	if (heights.empty() == false)
	{
		int currentTop = heights.top();
		while (heights.empty() == false)
		{
			if (currentTop == heights.top())
			{
				heights.pop();
			}
			else
			{
				currentTop = heights.top();
				++answer;
			}
		}
		++answer;
	}

	cout << answer << "\n";
	return 0;
}