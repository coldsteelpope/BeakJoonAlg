#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

map<int, vector<pair<int, int>>> shortcuts;

int GetMin(int num1, int num2)
{
	return num1 > num2 ? num2 : num1;
}

void SetShortcuts(int N)
{
	for (int n = 0; n < N; ++n)
	{
		int startPos, targetPos, shortDistance;
		cin >> startPos >> targetPos >> shortDistance;
		shortcuts[startPos].push_back({ targetPos, shortDistance });
	}
}

int main(void)
{
	int N, D;
	cin >> N >> D;
	SetShortcuts(N);

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	
	int minValue = (~0U >> 2);

	while (q.empty() == false)
	{
		pair<int, int> here = q.front();
		q.pop();

		if (here.first > D)
		{
			continue;
		}

		if (here.first == D)
		{
			minValue = GetMin(minValue, here.second);
			continue;
		}

		vector<pair<int, int>> theres = shortcuts[here.first];
		for (int i = 0; i < theres.size(); ++i)
		{
			int therePos = theres[i].first;
			int thereDist = theres[i].second;

			if (therePos > D)
			{
				continue;
			}
			q.push({ therePos, here.second + thereDist });
		}
		q.push({ here.first + 1, here.second + 1 });
	}

	cout << minValue << endl;
	return 0;
}