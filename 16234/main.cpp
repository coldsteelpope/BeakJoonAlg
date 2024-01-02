#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;

int dirs[4][2] = {
	{ +0, +1 },
	{ +1, +0 },
	{ +0, -1 },
	{ -1, +0 }
};

inline int GetAbs(int num)
{
	return num > 0 ? num : -num;
}

void SetBoard(int N)
{
	board.resize(N, vector<int>(N, 0));
	visited.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}
}

void BFS(int N, int L, int R, int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	vector<pair<int, int>> pos;
	pos.push_back(make_pair(i, j));
	
	while (q.empty() == false)
	{
		pair<int, int> here = q.front();
		q.pop();

		for (int dir_i = 0; dir_i < 4; ++dir_i)
		{
			int nextY = here.first + dirs[dir_i][0];
			int nextX = here.second + dirs[dir_i][1];

			if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
			{
				continue;
			}

			if (visited[nextY][nextX] == true)
			{
				continue;
			}

			int diff = GetAbs(board[here.first][here.second] - board[nextY][nextX]);
			if (diff < L || diff > R)
			{
				continue;
			}

			visited[here.first][here.second] = true;
			visited[nextY][nextX] = true;
			pos.push_back(make_pair(nextY, nextX));

			q.push(make_pair(nextY, nextX));
		}
	}

	int sum = 0;
	for (int i = 0; i < pos.size(); ++i)
	{
		sum += board[pos[i].first][pos[i].second];
	}
	
	for (int i = 0; i < pos.size(); ++i)
	{
		board[pos[i].first][pos[i].second] = sum / pos.size();
	}
}

void SetVisited(int N, int L, int R)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j] == true)
			{
				continue;
			}
			BFS(N, L, R, i, j);
		}
	}
}

void Init(int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			visited[i][j] = false;
		}
	}
}

bool IsOpen(int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j] == true)
			{
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
	int N, L, R, count = 0;
	cin >> N >> L >> R;
	SetBoard(N);

	while (true)
	{
		SetVisited(N, L, R);
		if (IsOpen(N) == false)
		{
			break;
		}
		++count;
		Init(N);
	}

	cout << count << "\n";
	return 0;
}