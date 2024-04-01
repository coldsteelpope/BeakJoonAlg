#include <iostream>
#include <queue>
#include <utility>
#include <memory>

using namespace std;

#define		MAX_LEN		50


int g_iR = 0;
int g_iC = 0;

char cBoard[MAX_LEN][MAX_LEN] = { 0, };
bool bVisited[MAX_LEN][MAX_LEN] = { 0, };

pair<int, int> housePos;
pair<int, int> hedgehogPos;

int iDirs[4][2] = {
	{ -1, +0 },
	{ +0, +1 },
	{ +1, +0 },
	{ +0, -1 }
};

void SetBoard();
void PrintBoard();
void FillWater();

int main(void)
{
	SetBoard();
	
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, hedgehogPos });
	bVisited[hedgehogPos.first][hedgehogPos.second] = true;

	int iCurrentTurn = 0;

	while (q.empty() == false)
	{
		int iMoveNumber = q.front().first;
		pair<int, int> currentPos = q.front().second;
		q.pop();

		if (iMoveNumber != iCurrentTurn)
		{
			FillWater();
			iCurrentTurn = iMoveNumber;
		}

		if (cBoard[currentPos.first][currentPos.second] == '*')
		{
			continue;
		}

		if (currentPos.first == housePos.first && currentPos.second == housePos.second)
		{
			cout << iMoveNumber << endl;
			return 0;
		}

		for (int iDirIdx = 0; iDirIdx < 4; ++iDirIdx)
		{
			int iNextY = currentPos.first + iDirs[iDirIdx][0];
			int iNextX = currentPos.second + iDirs[iDirIdx][1];

			if (iNextX < 0 || iNextY < 0 || iNextX >= g_iC || iNextY >= g_iR)
			{
				continue;
			}

			if (bVisited[iNextY][iNextX] == true)
			{
				continue;
			}

			if (cBoard[iNextY][iNextX] == '*')
			{
				continue;
			}

			if (cBoard[iNextY][iNextX] == 'X')
			{
				continue;
			}

			q.push({ iMoveNumber + 1, { iNextY, iNextX } });
			bVisited[iNextY][iNextX] = true;
		}
	}

	cout << "KAKTUS" << endl;
	return 0;
}

void SetBoard()
{
	cin >> g_iR >> g_iC;

	for (int i = 0; i < g_iR; ++i)
	{
		string width = "";
		cin >> width;
		for (int j = 0; j < width.size(); ++j)
		{
			cBoard[i][j] = width[j];
			
			if (cBoard[i][j] == 'S')
			{
				hedgehogPos.first = i;
				hedgehogPos.second = j;
			}
			else if (cBoard[i][j] == 'D')
			{
				housePos.first = i;
				housePos.second = j;
			}
		}
	}
}

void PrintBoard()
{
	cout << endl;
	for (int i = 0; i < g_iR; ++i)
	{
		for (int j = 0; j < g_iC; ++j)
		{
			cout << cBoard[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void FillWater()
{
	queue<pair<int, int>> q;
	for (int i = 0; i < g_iR; ++i)
	{
		for (int j = 0; j < g_iC; ++j)
		{
			if (cBoard[i][j] == '*')
			{
				q.push({ i, j });
			}
		}
	}

	while (q.empty() == false)
	{
		pair<int, int> pos = q.front();

		for (int i = 0; i < 4; ++i)
		{
			int nextY = pos.first + iDirs[i][0];
			int nextX = pos.second + iDirs[i][1];

			if (nextY < 0 || nextX < 0 || nextY >= g_iR || nextX >= g_iC)
			{
				continue;
			}

			if (cBoard[nextY][nextX] == '*')
			{
				continue;
			}

			if (cBoard[nextY][nextX] == 'D')
			{
				continue;
			}

			if (cBoard[nextY][nextX] == 'X')
			{
				continue;
			}

			cBoard[nextY][nextX] = '*';
		}
		q.pop();
	}
}