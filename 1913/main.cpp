#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;

int main(void)
{
	int N;
	int target;
	cin >> N >> target;

	board.resize(N, vector<int>(N, 0));
	
	int num = 1;
	int rnd = 1;
	int currentY = N / 2;
	int currentX = N / 2;
	int targetY = -1;
	int targetX = -1;
	board[currentY][currentX] = num;

	while (num < N * N)
	{
		if (num == target)
		{
			targetY = currentY;
			targetX = currentX;
		}

		board[--currentY][currentX] = ++num;

		if (num == target)
		{
			targetY = currentY;
			targetX = currentX;
		}
		
		// left to right
		for (int i = 0; i < rnd; ++i)
		{
			board[currentY][++currentX] = ++num;

			if (num == target)
			{
				targetY = currentY;
				targetX = currentX;
			}
		}

		// up to down
		for (int j = 0; j < rnd + 1; ++j)
		{
			board[++currentY][currentX] = ++num;

			if (num == target)
			{
				targetY = currentY;
				targetX = currentX;
			}
		}

		// right to left
		for (int i = 0; i < rnd + 1; ++i)
		{
			board[currentY][--currentX] = ++num;

			if (num == target)
			{
				targetY = currentY;
				targetX = currentX;
			}
		}

		// down to up
		for (int i = 0; i < rnd + 1; ++i)
		{
			board[--currentY][currentX] = ++num;

			if (num == target)
			{
				targetY = currentY;
				targetX = currentX;
			}
		}
		rnd += 2;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << targetY + 1 << " " << targetX + 1 << "\n";
	return 0;
}