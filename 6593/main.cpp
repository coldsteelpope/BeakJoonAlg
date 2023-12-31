#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

typedef struct _POS
{
	int _z;
	int _y;
	int _x;
} Pos;

Pos startPos = { 0,0,0 };
char board[31][31][31] = { 0, };

int dirs[6][3] = {
	{ +1, +0, +0 },
	{ -1, +0, +0 },
	{ +0, +1, +0 },
	{ +0, -1, +0 },
	{ +0, +0, +1 },
	{ +0, +0, -1 }
};

inline int GetMin(int num1, int num2)
{
	return num1 > num2 ? num2 : num1;
}

void PrintBoard(int L, int R, int C)
{
	cout << endl;
	for (int l = 0; l < L; ++l)
	{
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				cout << board[l][r][c];
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

void SetBoard(int L, int R, int C)
{
	for (int l = 0; l < L; ++l)
	{
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				cin >> board[l][r][c];
				if (board[l][r][c] == 'S')
				{
					startPos = { l,r,c };
				}
			}
		}
		getchar();
	}
}

bool CanGo(int nextZ, int nextY, int nextX, int L, int R, int C)
{
	if (nextZ < 0 || nextY < 0 || nextX < 0 || nextZ >= L || nextY >= R || nextX >= C)
	{
		return false;
	}

	if (board[nextZ][nextY][nextX] == '#')
	{
		return false;
	}

	return true;
}

void Solution(int L, int R, int C)
{
	queue<pair<int, Pos>> q;
	q.push(make_pair(0, startPos));
	board[startPos._z][startPos._y][startPos._x] = '#';
	
	int minute = (~0U >> 2);
	while (q.empty() == false)
	{
		pair<int, Pos> here = q.front();
		q.pop();

		if (board[here.second._z][here.second._y][here.second._x] == 'E')
		{
			minute = GetMin(minute, here.first);
		}

		for (int dir_i = 0; dir_i < 6; ++dir_i)
		{
			int nextZ = here.second._z + dirs[dir_i][0];
			int nextY = here.second._y + dirs[dir_i][1];
			int nextX = here.second._x + dirs[dir_i][2];

			if (CanGo(nextZ, nextY, nextX, L, R, C) == false) 
			{
				continue;
			}

			Pos nextPos = { nextZ, nextY, nextX };

			if (board[nextZ][nextY][nextX] != 'E')
			{
				board[nextZ][nextY][nextX] = '#';
			}
			
			q.push(make_pair(here.first + 1, nextPos));

			//PrintBoard(L, R, C);
		}
	}

	if (minute == (~0U >> 2))
	{
		cout << "Trapped!" << "\n";
	}
	else
	{
		cout << "Escaped in " << minute << " minute(s)." << "\n";
	}
}

void Destroy(int L, int R, int C)
{
	startPos = { 0,0,0 };
	memset(board, 0, sizeof(board));
}

int main(void)
{
	
	while (true)
	{
		int L, R, C;
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
		{
			break;
		}
		SetBoard(L, R, C);
		Solution(L, R, C);
		Destroy(L, R, C);
	}
	return 0;
}