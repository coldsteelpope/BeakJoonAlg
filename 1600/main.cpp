#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int iAdjacentDirs[4][2] = {
	{ -1, +0 },
	{ +0, +1 },
	{ +1, +0 },
	{ +0, -1 }
};

int iHorseDirs[8][2] = {
	{ -2, -1 },
	{ -1, -2 },
	{ -2, +1 },
	{ -1, +2 },
	{ +1, -2 },
	{ +2, -1 },
	{ +1, +2 },
	{ +2, +1 }
};

int iBoard[201][201] = { 0, };
int iDPTable[201][201] = { 0, };
bool bVisited[201][201] = { 0, };

void InitDPTable(int _iH, int _iW);
void SetBoard(int _iH, int _iW);

bool CanGo(int _iNextY, int _iNextX, int _iH, int _iW, int _iCurrentJump);

int main(void)
{
	int iK;
	int iW;
	int iH;

	cin >> iK;
	cin >> iW >> iH;
	
	SetBoard(iH, iW);
	InitDPTable(iH, iW);
	
	// <pos, <jump, k>>
	int iResult = INT32_MAX;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { 1, 1 }, { 0, iK } });
	
	while (q.empty() == false)
	{
		pair<int, int> currentPos = q.front().first;
		pair<int, int> currentStatus = q.front().second;
		q.pop();

		int iCurrentJump = currentStatus.first;
		int iCurrentK = currentStatus.second;

		if (iH == currentPos.first && iW == currentPos.second)
		{
			iResult = (iCurrentJump > iResult) ? iResult : iCurrentJump;
			continue;
		}
		
		iDPTable[currentPos.first][currentPos.second] = iCurrentJump;

		for (int i = 0; i < 4; ++i)
		{
			int iNextY = currentPos.first + iAdjacentDirs[i][0];
			int iNextX = currentPos.second + iAdjacentDirs[i][1];
			
			if (CanGo(iNextY, iNextX, iH, iW, iCurrentJump))
			{
				q.push({ {iNextY, iNextX}, { iCurrentJump + 1, iCurrentK } });
			}
		}

		if (iCurrentK > 0)
		{
			for (int i = 0; i < 8; ++i)
			{
				int iNextY = currentPos.first + iHorseDirs[i][0];
				int iNextX = currentPos.second + iHorseDirs[i][1];

				if (CanGo(iNextY, iNextX, iH, iW, iCurrentJump))
				{
					q.push({ {iNextY, iNextX}, {iCurrentJump + 1, iCurrentK - 1} });
				}
			}
		}

		bVisited[currentPos.first][currentPos.second] = true;
	}

	iResult = (iResult == INT32_MAX) ? -1 : iResult;
	cout << iResult << endl;
}

void InitDPTable(int _iH, int _iW)
{
	for (int i = 1; i <= _iH; ++i)
	{
		for (int j = 1; j <= _iW; ++j)
		{
			iDPTable[i][j] = INT32_MAX;
		}
	}
}

void SetBoard(int _iH, int _iW)
{
	for (int i = 1; i <= _iH; ++i)
	{
		for (int j = 1; j <= _iW; ++j)
		{
			cin >> iBoard[i][j];
		}
	}
}

bool CanGo(int _iNextY, int _iNextX, int _iH, int _iW, int _iCurrentJump)
{
	if (_iNextY <= 0 || _iNextX <= 0 || _iNextY > _iH || _iNextX > _iW)
	{
		return false;
	}

	if (iBoard[_iNextY][_iNextX] == 1)
	{
		return false;
	}

	if (bVisited[_iNextY][_iNextX] == true)
	{
		return false;
	}

	if (iDPTable[_iNextY][_iNextX] < _iCurrentJump + 1)
	{
		return false;
	}

	return true;
}