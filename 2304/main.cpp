#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> positions;

inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

int GetIdx(pair<int, int>& currentPos)
{
	for (int i = 0; i < positions.size(); ++i)
	{
		if (positions[i].first == currentPos.first && positions[i].second == currentPos.second)
		{
			return i;
		}
	}
}

int main(void)
{
	int N;
	int maxHeight = 0;
	int answer = 0;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int pos, height;
		cin >> pos >> height;
		maxHeight = GetMax(maxHeight, height);
		positions.push_back(make_pair(pos, height));
	}

	std::sort(positions.begin(), positions.end());

	int maxHeightMinPos = 0;
	pair<int, int> currentPos = positions[0];

	while (true)
	{
		stack<pair<int, int>> s;
		for (int sp = GetIdx(currentPos); sp < N; ++sp)
		{
			if (s.empty() == true || s.top().second < positions[sp].second)
			{
				s.push(positions[sp]);
			}
		}

		if (s.size() == 1 && s.top().second == maxHeight)
		{
			maxHeightMinPos = s.top().first;
			break;
		}
		else
		{
			while (s.size() != 2)
			{
				s.pop();
			}
			pair<int, int> nextPos = s.top();
			answer += ((currentPos.second) * (nextPos.first - currentPos.first));
			currentPos = nextPos;
		}
	}

	int maxHeightMaxPos = N - 1;
	currentPos = positions[N - 1];

	while (true)
	{
		stack<pair<int, int>> s;
		for (int sp = GetIdx(currentPos); sp >= 0; --sp)
		{
			if (s.empty() == true || s.top().second < positions[sp].second)
			{
				s.push(positions[sp]);
			}
		}

		if (s.size() == 1 && s.top().second == maxHeight)
		{
			maxHeightMaxPos = s.top().first;
			break;
		}
		else
		{
			while (s.size() != 2)
			{
				s.pop();
			}
			pair<int, int> nextPos = s.top();
			answer += ((currentPos.second) * (currentPos.first - nextPos.first));
			currentPos = nextPos;
		}
	}

	answer += ((maxHeight) * (maxHeightMaxPos - maxHeightMinPos + 1));
	cout << answer << "\n";
	return 0;
}