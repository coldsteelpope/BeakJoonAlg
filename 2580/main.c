#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int boardGame[10][10] = { 0, };
typedef struct _POS
{
	int _y;
	int _x;
} Pos;

Pos zeroPos[81] = { 0, };
int zeroPosLen = 0;

bool IsOkWidth(int y);
bool IsOkHeight(int x);
bool IsOkSquare(int y, int x);

int GetStartSquareY(int squarePosY);
int GetStartSquareX(int squarePosX);

void SetBoardGame();
void SetZeroPos();
void PrintBoardGame();

void DFS(int y, int x, int val, int index)
{

	boardGame[y][x] = val;
	if (y == 4 && x == 0 && val == 3)
	{
		int a = 3;
	}

	bool isOkWidth = IsOkWidth(y);
	bool isOkHeight = IsOkHeight(x);
	bool isOkSquare = IsOkSquare(y, x);
//	PrintBoardGame();
	
	if (isOkWidth == true && isOkHeight == true && isOkSquare == true)
	{
		if (zeroPosLen == index)
		{
			// 끝내기
			PrintBoardGame();
			exit(0);
		}
		else
		{
			for (int nextVal = 1; nextVal <= 9; ++nextVal)
			{
				int nextY = zeroPos[index]._y;
				int nextX = zeroPos[index]._x;
				DFS(nextY, nextX, nextVal, index + 1);
			}
			// 실패했을경우
			boardGame[y][x] = 0;
		}
	}
	else
	{
		boardGame[y][x] = 0;
		return;
	}
}



int main(void)
{
	SetBoardGame();
	SetZeroPos();

	if (zeroPosLen == 0)
	{

	}
	else
	{
		int firstY = zeroPos[0]._y;
		int firstX = zeroPos[0]._x;
		for (int num = 1; num <= 9; ++num)
		{
			DFS(firstY, firstX, num, 1);
		}
	}
}


bool IsOkWidth(int y)
{
	bool result = true;
	bool visited[10] = { 0, };
	for (int x = 0; x < 9; ++x)
	{
		if (boardGame[y][x] == 0)
			continue;

		if (visited[boardGame[y][x]] == false)
		{
			visited[boardGame[y][x]] = true;
		}
		else
		{
			result = false;
			break;
		}
	}
	return result;
}

bool IsOkHeight(int x)
{
	bool result = true;
	bool visited[10] = { 0, };
	for (int y = 0; y < 9; ++y)
	{
		if (boardGame[y][x] == 0)
			continue;

		if (visited[boardGame[y][x]] == false)
		{
			visited[boardGame[y][x]] = true;
		}
		else
		{
			result = false;
			break;
		}
	}
	return result;
}

int GetStartSquareY(int squarePosY)
{
	int startSquareY = 0;
	switch (squarePosY)
	{
	case 0:
		startSquareY = 0;
		break;
	case 1:
		startSquareY = 3;
		break;
	case 2:
		startSquareY = 6;
		break;
	default:
		break;
	}
	return startSquareY;
}

int GetStartSquareX(int squarePosX)
{
	int startSquareX = 0;
	switch (squarePosX)
	{
	case 0:
		startSquareX = 0;
		break;
	case 1:
		startSquareX = 3;
		break;
	case 2:
		startSquareX = 6;
		break;
	default:
		break;
	}
	return startSquareX;
}

bool IsOkSquare(int y, int x)
{
	int squarePosY = y / 3;
	int squarePosX = x / 3;

	int startSquareY = GetStartSquareY(squarePosY);
	int startSquareX = GetStartSquareX(squarePosX);

	bool result = true;
	bool visited[10] = { 0, };
	for (int i = startSquareY; i < startSquareY + 3; ++i)
	{
		for (int j = startSquareX; j < startSquareX + 3; ++j)
		{
			if (boardGame[i][j] == 0)
				continue;
			if (visited[boardGame[i][j]] == false)
			{
				visited[boardGame[i][j]] = true;
			}
			else
			{
				result = false;
				break;
			}
		}
		if (result == false)
		{
			break;
		}
	}
	return result;
}

void SetBoardGame()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			scanf("%d", &boardGame[i][j]);
		}
	}
}

void SetZeroPos()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (boardGame[i][j] == 0)
			{
				zeroPos[zeroPosLen]._y = i;
				zeroPos[zeroPosLen]._x = j;
				++zeroPosLen;
			}
		}
	}
}

void PrintBoardGame()
{
	//printf("\n");
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			printf("%d ", boardGame[i][j]);
		}
		printf("\n");
	}
	//printf("\n");
}