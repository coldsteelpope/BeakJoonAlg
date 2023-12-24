#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> dp;

// y, x, status
int status_horizontal_dirs[2][3] = {
	{ +0, +1, 0 },
	{ +1, +1, 2 }
};

int status_vertical_dirs[2][3] = {
	{ +1, +0, 1 },
	{ +1, +1, 2 }
};

int status_diagonal_dirs[3][3] = {
	{ +1, +0, 1 },
	{ +1, +1, 2 },
	{ +0, +1, 0 }
};

void SetBoard(int N)
{
	board.resize(N, vector<int>(N, 0));
	dp.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}
}

bool CanGo(int nextY, int nextX, int nextStatus, int N)
{
	if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
	{
		return false;
	}

	bool isDiagonal = (nextStatus == 2) ? true : false;
	if (isDiagonal == true)
	{
		if (board[nextY][nextX] == 1 || board[nextY - 1][nextX] == 1 || board[nextY][nextX - 1] == 1)
		{
			return false;
		}
	}
	else
	{
		if (board[nextY][nextX] == 1)
		{
			return false;
		}
	}
	return true;
}

void PrintDP(int N)
{
	cout << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(void)
{
	int N;
	cin >> N;
	SetBoard(N);

	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, 1)));
	dp[0][1] = 1;
	
	while (q.empty() == false)
	{
		pair<int, pair<int, int>> here = q.front();
		q.pop();

		if (here.second.first == N - 1 && here.second.second == N - 1)
		{
			continue;
		}

		if (here.first == 0)
		{
			// horizontal
			for (int dir_i = 0; dir_i < 2; ++dir_i)
			{
				int nextY = here.second.first + status_horizontal_dirs[dir_i][0];
				int nextX = here.second.second + status_horizontal_dirs[dir_i][1];
				int nextStatus = status_horizontal_dirs[dir_i][2];
				
				if (CanGo(nextY, nextX, nextStatus, N) == true)
				{
					dp[nextY][nextX] += 1;
					q.push(make_pair(status_horizontal_dirs[dir_i][2], make_pair(nextY, nextX)));
				}
			}
		}
		else if (here.first == 1)
		{
			// vertical
			for (int dir_i = 0; dir_i < 2; ++dir_i)
			{
				int nextY = here.second.first + status_vertical_dirs[dir_i][0];
				int nextX = here.second.second + status_vertical_dirs[dir_i][1];
				int nextStatus = status_vertical_dirs[dir_i][2];

				if (CanGo(nextY, nextX, nextStatus, N) == true)
				{
					dp[nextY][nextX] += 1;
					q.push(make_pair(status_vertical_dirs[dir_i][2], make_pair(nextY, nextX)));
				}
			}
		}
		else
		{
			// diagonal
			for (int dir_i = 0; dir_i < 3; ++dir_i)
			{
				int nextY = here.second.first + status_diagonal_dirs[dir_i][0];
				int nextX = here.second.second + status_diagonal_dirs[dir_i][1];
				int nextStatus = status_diagonal_dirs[dir_i][2];

				if (CanGo(nextY, nextX, nextStatus, N) == true)
				{
					dp[nextY][nextX] += 1;
					q.push(make_pair(status_diagonal_dirs[dir_i][2], make_pair(nextY, nextX)));
				}
			}
		}
	}
	cout << dp[N - 1][N - 1] << "\n";
	return 0;
}