#include <iostream>
#include <vector>

#define CURRENT_DIR			1

using namespace std;

vector<vector<char>> cBoard;

void PrintCBoard(int iMaxTop, int iMaxBottom, int iMaxLeft, int iMaxRight)
{
	for (int iHeightIndex = iMaxTop; iHeightIndex <= iMaxBottom; ++iHeightIndex)
	{
		for (int iWidthIndex = iMaxLeft; iWidthIndex <= iMaxRight; ++iWidthIndex)
		{
			cout << cBoard[iHeightIndex][iWidthIndex];
		}
		cout << endl;
	}
}

void TurnRight(int& iCurrentDir)
{
	iCurrentDir = (iCurrentDir + 1 == 4) ? 0 : ++iCurrentDir;
}

void TurnLeft(int& iCurrentDir)
{
	iCurrentDir = (iCurrentDir - 1 == -1) ? 3 : --iCurrentDir;
}

void MoveForward(int iCurrentDir, int& iMaxTop, int& iMaxBottom, int& iMaxLeft, int& iMaxRight, int& iPosY, int& iPosX)
{
	switch (iCurrentDir)
	{
	case 0:
		cBoard[iPosY][++iPosX] = '.';
		iMaxRight = (iMaxRight < iPosX) ? iPosX : iMaxRight;
		break;
	case 1:
		cBoard[++iPosY][iPosX] = '.';
		iMaxBottom = (iMaxBottom < iPosY) ? iPosY : iMaxBottom;
		break;
	case 2:
		cBoard[iPosY][--iPosX] = '.';
		iMaxLeft = (iMaxLeft > iPosX) ? iPosX : iMaxLeft;
		break;
	case 3:
		cBoard[--iPosY][iPosX] = '.';
		iMaxTop = (iMaxTop > iPosY) ? iPosY : iMaxTop;
		break;
	}
}

int main(void)
{
	int iLen;
	cin >> iLen;

	int iMaxLen = iLen * 2 + 1;
	cBoard.resize(iMaxLen, vector<char>(iMaxLen, '#'));

	int iPosY = iMaxLen / 2;
	int iPosX = iMaxLen / 2;
	
	int iMaxTop = iPosY;
	int iMaxBottom = iPosY;
	int iMaxLeft = iPosX;
	int iMaxRight = iPosX;

	int iCurrentDir = 1;

	cBoard[iPosY][iPosX] = '.';
	
	string moves;
	cin >> moves;

	for (int index = 0; index < iLen; ++index)
	{
		switch (moves[index])
		{
		case 'R':
			TurnRight(iCurrentDir);
			break;
		case 'L':
			TurnLeft(iCurrentDir);
			break;
		case 'F':
			MoveForward(
				iCurrentDir,
				iMaxTop,
				iMaxBottom,
				iMaxLeft,
				iMaxRight,
				iPosY,
				iPosX
			);
			break;
		}
	}

	PrintCBoard(iMaxTop, iMaxBottom, iMaxLeft, iMaxRight);

	return 0;
}