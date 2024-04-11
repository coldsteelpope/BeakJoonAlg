#include <iostream>

#define MAX_LEN 2188

using namespace std;

typedef struct tagPoint
{
	int iY;
	int iX;
} Point;

int g_iN = 0;

int g_iOne = 0;
int g_iZero = 0;
int g_iMinusOne = 0;

int iBoard[MAX_LEN][MAX_LEN] = { 0, };

void Set_Board();
bool Is_Unified(Point _tTopLeft, int _iN);
void DFS(Point _tTopLeft, int _iN);

int main(void)
{
	Set_Board();
	DFS({ 0,0 }, g_iN);

	cout << g_iMinusOne << endl;
	cout << g_iZero << endl;
	cout << g_iOne << endl;
	return 0;
}

void Set_Board()
{
	cin >> g_iN;
	for (int i = 0; i < g_iN; ++i)
	{
		for (int j = 0; j < g_iN; ++j)
		{
			cin >> iBoard[i][j];
		}
	}
}

bool Is_Unified(Point _tTopLeft, int _iN)
{
	int iFirstElement = iBoard[_tTopLeft.iY][_tTopLeft.iX];
	for (int i = _tTopLeft.iY; i < _tTopLeft.iY + _iN; ++i)
	{
		for (int j = _tTopLeft.iX; j < _tTopLeft.iX + _iN; ++j)
		{
			if (iBoard[i][j] != iFirstElement)
			{
				return false;
			}
		}
	}
	return true;
}

void DFS(Point _tTopLeft, int _iN)
{
	if (Is_Unified(_tTopLeft, _iN))
	{
		int iFirstElement = iBoard[_tTopLeft.iY][_tTopLeft.iX];
		switch (iFirstElement)
		{
		case -1:
		{
			++g_iMinusOne;
		}
		break;
		case 0:
		{
			++g_iZero;
		}
		break;
		case 1:
		{
			++g_iOne;
		}
		break;
		}
		return;
	}

	int iCurrentTopLeftY = _tTopLeft.iY;
	int iCurrentTopLeftX = _tTopLeft.iX;

	DFS({ iCurrentTopLeftY, iCurrentTopLeftX }, _iN / 3);
	DFS({ iCurrentTopLeftY, iCurrentTopLeftX + _iN / 3 }, _iN / 3);
	DFS({ iCurrentTopLeftY, iCurrentTopLeftX + (2 * _iN) / 3 }, _iN / 3);

	DFS({ iCurrentTopLeftY + _iN / 3, iCurrentTopLeftX }, _iN / 3);
	DFS({ iCurrentTopLeftY + _iN / 3, iCurrentTopLeftX + _iN / 3 }, _iN / 3);
	DFS({ iCurrentTopLeftY + _iN / 3, iCurrentTopLeftX + (2 * _iN) / 3 }, _iN / 3);

	DFS({ iCurrentTopLeftY + (2 * _iN) / 3, iCurrentTopLeftX }, _iN / 3);
	DFS({ iCurrentTopLeftY + (2 * _iN) / 3, iCurrentTopLeftX + _iN / 3 }, _iN / 3);
	DFS({ iCurrentTopLeftY + (2 * _iN) / 3, iCurrentTopLeftX + (2 * _iN) / 3 }, _iN / 3);
}