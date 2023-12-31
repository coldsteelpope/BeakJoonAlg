#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<pair<int, int>> heights;

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int pos, height;
		cin >> pos >> height;
		heights.push_back(make_pair(pos, height));
	}

	stack<int> s;
	int answer = 0;

	for (int i = 0; i < N; ++i)
	{
		int height = heights[i].second;
		if ((s.empty() == true || s.top() <= height))
		{
			if (height != 0)
			{
				s.push(height);
			}
		}
		else
		{
			int currentHeight = s.top();
			while (s.empty() == false && s.top() > height)
			{
				if (currentHeight != s.top())
				{
					currentHeight = s.top();
					++answer;
				}
				else
				{
					s.pop();
				}
			}
			++answer;

			if (height != 0)
			{
				s.push(height);
			}
		}
	}

	if (s.empty() == false)
	{
		int currentHeight = s.top();
		while (s.empty() == false)
		{
			if (currentHeight != s.top())
			{
				currentHeight = s.top();
				++answer;
			}
			else
			{
				s.pop();
			}
		}
		++answer;
	}

	cout << answer << "\n";
	return 0;
}