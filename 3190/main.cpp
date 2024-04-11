#include <iostream>
#include <deque>
#include <queue>

#define MAX_LEN		101

using namespace std;

int iDirs[4][2] = {
	{ +0, +1 },
	{ +1, +0 },
	{ +0, -1 },
	{ -1, +0 }
};
int g_iN, g_iK;
int iSnakeDirIdx = 0;
deque<pair<int, int>> snake;
queue<pair<int, char>> QProcess;
int iBoard[MAX_LEN][MAX_LEN] = { 0, };

void SetApples();
void Move();
void Grow();
bool IsAlive();
void ChangeDirection(char _cDir);

int main(void)
{
	SetApples();
	int iL;
	cin >> iL;
	for (int i = 0; i < iL; ++i)
	{
		int iSecond;
		char cDir;
		cin >> iSecond >> cDir;
		QProcess.push({ iSecond, cDir });
	}

	bool bIsAlive = true;
	int iSecond = 0;
	while (true)
	{
		
		while (QProcess.empty() == false)
		{
			int iLimitTime = QProcess.front().first;
			char cDir = QProcess.front().second;
			QProcess.pop();

			while (iSecond < iLimitTime)
			{
				Move();
				bIsAlive = IsAlive();
				Grow();
				++iSecond;

				if (bIsAlive == false)
				{
					cout << iSecond << endl;
					return 0;
				}
			}
			ChangeDirection(cDir);
		}

		Move();

		bIsAlive = IsAlive();
		Grow();
		++iSecond;
		if (bIsAlive == false)
		{
			cout << iSecond << endl;
			return 0;
		}
	}

	return 0;
}

void SetApples()
{
	cin >> g_iN;
	cin >> g_iK;
	for (int i = 0; i < g_iK; ++i)
	{
		int iY, iX;
		cin >> iY >> iX;
		iBoard[iY][iX] = 1;
	}
	snake.push_back({ 1,1 });
}

void Move()
{
	pair<int, int> iCurrentHeadPos = snake.front();
	iCurrentHeadPos.first += iDirs[iSnakeDirIdx][0];
	iCurrentHeadPos.second += iDirs[iSnakeDirIdx][1];
	snake.push_front(iCurrentHeadPos);
}

void Grow()
{
	pair<int, int> currentHeadPos = snake.front();
	if (iBoard[currentHeadPos.first][currentHeadPos.second] == 1)
	{
		iBoard[currentHeadPos.first][currentHeadPos.second] = 0;
	}
	else
	{
		snake.pop_back();
	}
}

bool IsAlive()
{
	pair<int, int> currentHeadPos = snake.front();
	
	int iCurrentHeadPosY = currentHeadPos.first;
	int iCurrentHeadPosX = currentHeadPos.second;

	if (iCurrentHeadPosX <= 0 || iCurrentHeadPosY <= 0 || iCurrentHeadPosX > g_iN || iCurrentHeadPosY > g_iN)
	{
		return false;
	}

	for (int i = 1; i < snake.size(); ++i)
	{
		if (snake[i].first == iCurrentHeadPosY && snake[i].second == iCurrentHeadPosX)
		{
			return false;
		}
	}

	return true;
}

void ChangeDirection(char _cDir)
{
	if (_cDir == 'D')
	{
		iSnakeDirIdx = (iSnakeDirIdx + 1 == +4) ? 0 : iSnakeDirIdx + 1;
	}
	else if (_cDir == 'L')
	{
		iSnakeDirIdx = (iSnakeDirIdx - 1 == -1) ? 3 : iSnakeDirIdx - 1;
	}
}
