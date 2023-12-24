#include <iostream>
#include <utility>
#include <queue>

using namespace std;

typedef struct _POS
{
	int _z;
	int _y;
	int _x;
} Pos;

int board[101][101][101] = { 0, };
int dirs[6][3] = {
	{ +1, +0, +0 },
	{ -1, +0, +0 },
	{ +0, -1, +0 },
	{ +0, +0, +1 },
	{ +0, +1, +0 },
	{ +0, +0, -1 }
};

inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

bool CanGo(int nextZ, int nextY, int nextX, int M, int N, int H)
{
	if (nextZ < 1 || nextY < 1 || nextX < 1 || nextZ > H || nextY > N || nextX > M)
	{
		return false;
	}

	if (board[nextZ][nextY][nextX] == 1 || board[nextZ][nextY][nextX] == -1)
	{
		return false;
	}

	return true;
}

void PrintBoard(int M, int N, int H)
{
	cout << endl;
	for (int z = 1; z <= H; ++z)
	{
		cout << z << "floor" << endl;
		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= M; ++x)
			{
				cout << board[z][y][x] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

int main(void)
{
	// M: width, N: longitude, H: height
	int M, N, H;
	cin >> M >> N >> H;
	
	int zeroNum = 0;
	queue<pair<int, Pos>> q;

	for (int z = 1; z <= H; ++z)
	{
		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= M; ++x)
			{
				cin >> board[z][y][x];
				if (board[z][y][x] == 1)
				{
					Pos pos;
					pos._z = z; pos._y = y; pos._x = x;
					q.push(make_pair(0, pos));
				}
				else if (board[z][y][x] == 0)
				{
					++zeroNum;
				}
			}
		}
	}

	int maxValue = 0;
	while (q.empty() == false)
	{
		//PrintBoard(M, N, H);

		pair<int, Pos> here = q.front();
		
		int currentZ = here.second._z;
		int currentY = here.second._y;
		int currentX = here.second._x;

		q.pop();

		maxValue = GetMax(maxValue, here.first);
		
		for (int dirIdx = 0; dirIdx < 6; ++dirIdx)
		{
			int nextZ = currentZ + dirs[dirIdx][0];
			int nextY = currentY + dirs[dirIdx][1];
			int nextX = currentX + dirs[dirIdx][2];

			if (CanGo(nextZ, nextY, nextX, M, N, H) == true)
			{
				board[nextZ][nextY][nextX] = 1;
				--zeroNum;
				
				Pos nextPos;
				nextPos._z = nextZ; nextPos._y = nextY; nextPos._x = nextX;
				q.push(make_pair(here.first + 1, nextPos));
			}
		}
	}

	if (zeroNum != 0)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << maxValue << "\n";
	}
	return 0;
}