#include <iostream>
#include <vector>
#include <queue>

#define MAX_LEN 101

using namespace std;

int g_iMinDist = INT32_MAX;
int iBoard[MAX_LEN][MAX_LEN] = { 0, };
bool bVisited[MAX_LEN][MAX_LEN] = { 0, };


void BFS(int _iN, int _iLabel);
void ClearVisited(int _iN);
void LabelBoardTotal(int _iN, int* _iLabel);
void LabelBoard(int _iCurrentY, int _iCurrentX, int _iN, int _iLabel);
void PrintBoard(int _iN);
void SetBoard(int _iN);

int main(void)
{
	int iN;
	int iLabel = 2;
	cin >> iN;
	SetBoard(iN);
	LabelBoardTotal(iN, &iLabel);
	
	for (int i = 2; i < iLabel; ++i)
	{
		BFS(iN, i);
	}
	
	cout << g_iMinDist << endl;
	return 0;
}

void LabelBoardTotal(int _iN, int* _iLabel)
{
	for (int i = 0; i < _iN; ++i)
	{
		for (int j = 0; j < _iN; ++j)
		{
			if (iBoard[i][j] == 1)
			{
				LabelBoard(i, j, _iN, (*_iLabel));
				++(*_iLabel);
			}
		}
	}
}

void LabelBoard(int _iCurrentY, int _iCurrentX, int _iN, int _iLabel)
{
	if (_iCurrentY < 0 || _iCurrentX < 0 || _iCurrentY >= _iN || _iCurrentX >= _iN)
	{
		return;
	}
	
	if (iBoard[_iCurrentY][_iCurrentX] != 1)
	{
		return;
	}

	iBoard[_iCurrentY][_iCurrentX] = _iLabel;
	LabelBoard(_iCurrentY - 1, _iCurrentX, _iN, _iLabel);
	LabelBoard(_iCurrentY, _iCurrentX + 1, _iN, _iLabel);
	LabelBoard(_iCurrentY + 1, _iCurrentX, _iN, _iLabel);
	LabelBoard(_iCurrentY, _iCurrentX - 1, _iN, _iLabel);
}

void PrintBoard(int _iN)
{
	cout << endl;
	for (int i = 0; i < _iN; ++i)
	{
		for (int j = 0; j < _iN; ++j)
		{
			cout << iBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void SetBoard(int _iN)
{
	for (int i = 0; i < _iN; ++i)
	{
		for (int j = 0; j < _iN; ++j)
		{
			cin >> iBoard[i][j];
		}
	}
}

void ClearVisited(int _iN)
{
	for (int i = 0; i < _iN; ++i)
	{
		for (int j = 0; j < _iN; ++j)
		{
			bVisited[i][j] = false;
		}
	}
}

void BFS(int _iN, int _iLabel)
{
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < _iN; ++i)
	{
		for (int j = 0; j < _iN; ++j)
		{
			if (iBoard[i][j] == _iLabel)
			{
				q.push({ 0, {i, j} });
				bVisited[i][j] = true;
			}
		}
	}

	int iDirs[4][2] = {
		{ -1, +0 },
		{ +0, +1 },
		{ +1, +0 },
		{ +0, -1 }
	};

	while (q.empty() == false)
	{
		pair<int, int> currentPos = q.front().second;
		int iCurrentDist = q.front().first;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int iNextY = currentPos.first + iDirs[i][0];
			int iNextX = currentPos.second + iDirs[i][1];

			if (iNextY < 0 || iNextX < 0 || iNextY >= _iN || iNextX >= _iN)
			{
				continue;
			}

			if (bVisited[iNextY][iNextX] == true)
			{
				continue;
			}

			if (iBoard[iNextY][iNextX] != 0)
			{
				g_iMinDist = (g_iMinDist > iCurrentDist) ? iCurrentDist : g_iMinDist;
			}

			q.push({ iCurrentDist + 1, { iNextY, iNextX} });
			bVisited[iNextY][iNextX] = true;
		}
	}
	ClearVisited(_iN);
}