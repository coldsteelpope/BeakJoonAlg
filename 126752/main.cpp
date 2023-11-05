#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> walls;
int main(void)
{
	int H, W;
	cin >> H >> W;

	for (int w = 0; w < W; ++w)
	{
		int wall; cin >> wall;
		walls.push_back(wall);
	}

	stack<int> s;

	int sum = 0;
	int wallIdx = 0;
	int pivotWall = 0;
	bool pivotWallSetting = false;

	while (wallIdx < W)
	{
		if (pivotWallSetting == false)
		{
			pivotWall = walls[wallIdx];
			pivotWallSetting = true;
			++wallIdx;
		}
		else
		{
			int currentWall = walls[wallIdx];
			if (currentWall <= pivotWall)
			{
				s.push(walls[wallIdx++]);
			}
			else
			{
				pivotWallSetting = false;
				while (s.empty() == false)
				{
					int topWall = s.top();
					if (pivotWall > topWall)
						sum += (pivotWall - topWall);
					else
						pivotWall = topWall;
					s.pop();
				}
			}
		}
	}

	if (s.empty() == false)
	{
		if (s.top() < pivotWall)
		{
			pivotWall = s.top();
		}

		while (s.empty() == false)
		{
			int topWall = s.top();
			if (pivotWall > topWall)
			{
				sum += (pivotWall - topWall);
			}
			else if(pivotWall < topWall)
			{
				pivotWall = topWall;
			}
			s.pop();
		}
	}

	cout << sum << endl;
	return 0;
}