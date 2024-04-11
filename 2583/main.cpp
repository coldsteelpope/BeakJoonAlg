#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> areaStatus;
vector<vector<int>> iBoard;

typedef struct tagPoint
{
	int iY;
	int iX;
} Point;

void InitBoard(int _iM, int _iN, int _iK);
//void PrintBoard(int _iM, int _iN);
void DrawRectangle(Point topLeft, Point bottomRight);
void DyeArea(int _iCurrentY, int _iCurrentX, int _iCurrentNum, int _iM, int _iN, int* _iAreaNumber);

int main(void)
{
	int iM, iN, iK;
	cin >> iM >> iN >> iK;
	
	InitBoard(iM, iN, iK);
	
	int iCurrentNum = 1;
	for (int i = 0; i < iM; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (iBoard[i][j] == 0)
			{
				int iAreaNumber = 0;
				DyeArea(i, j, iCurrentNum, iM, iN, &iAreaNumber);
				++iCurrentNum;
				areaStatus.emplace_back(iAreaNumber);
			}
		}
	}

	cout << iCurrentNum - 1 << endl;
	std::sort(areaStatus.begin(), areaStatus.end());
	for (int status : areaStatus)
	{
		cout << status << " ";
	}
	return 0;
}

void DyeArea(int _iCurrentY, int _iCurrentX, int _iCurrentNum, int _iM, int _iN, int* _iAreaNumber)
{
	queue<pair<int, int>> q;
	q.push({ _iCurrentY, _iCurrentX });
	iBoard[_iCurrentY][_iCurrentX] = _iCurrentNum;
	++(*_iAreaNumber);

	int dirs[4][2] = {
		{-1, +0},
		{+0, +1},
		{+1, +0},
		{+0, -1}
	};

	while (q.empty() == false)
	{
		pair<int, int> currentPos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int iNextY = currentPos.first + dirs[i][0];
			int iNextX = currentPos.second + dirs[i][1];

			if (iNextY < 0 || iNextX < 0 || iNextY >= _iM || iNextX >= _iN)
			{
				continue;
			}

			if (iBoard[iNextY][iNextX] != 0)
			{
				continue;
			}
			iBoard[iNextY][iNextX] = _iCurrentNum;
			++(*_iAreaNumber);
			q.push({ iNextY, iNextX });
		}
	}
}

void InitBoard(int _iM, int _iN, int _iK)
{
	iBoard.resize(_iM, vector<int>(_iN, 0));
	
	for (int k = 0; k < _iK; ++k)
	{
		Point bottomLeft;
		Point topRight;

		cin >> bottomLeft.iX >> bottomLeft.iY;
		cin >> topRight.iX >> topRight.iY;
		DrawRectangle(bottomLeft, topRight);
	}
}

void DrawRectangle(Point bottomLeft, Point topRight)
{
	for (int i = bottomLeft.iY; i < topRight.iY; ++i)
	{
		for (int j = bottomLeft.iX; j < topRight.iX; ++j)
		{
			iBoard[i][j] = -1;
		}
	}
}

//void PrintBoard(int _iM, int _iN)
//{
//	cout << endl;
//	for (int i = 0; i < _iM; ++i)
//	{
//		for (int j = 0; j < _iN; ++j)
//		{
//			cout << iBoard[i][j] << "\t";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}