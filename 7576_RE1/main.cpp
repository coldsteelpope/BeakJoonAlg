#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> board;
vector<pair<int, int>> tomatos;

int zeroNums = 0;
int dirs[4][2] = {
	{ +0, +1 },
	{ +1, +0 },
	{ +0, -1 },
	{ -1, +0 }
};

inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

void SetBoard(int M, int N)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cin >> board[y][x];
			if (board[y][x] == 1)
			{
				tomatos.emplace_back(make_pair(y, x));
			}
			
			if (board[y][x] == 0)
			{
				++zeroNums;
			}
		}
	}
}

int main(void)
{
	// M은 가로(x), N은 세로(y)
	int M, N;
	cin >> M >> N;
	board.resize(N, vector<int>(M, 0));
	SetBoard(M, N);
	
	queue <pair<int, pair<int, int>>> q;
	for (auto& tomato : tomatos)
	{
		q.push(make_pair(0, tomato));
	}
	
	int maxDay = 0;
	while (q.empty() == false)
	{
		pair<int, pair<int, int>> here = q.front();
		q.pop();

		maxDay = GetMax(maxDay, here.first);
		for (int dirIdx = 0; dirIdx < 4; ++dirIdx)
		{
			int nextY = here.second.first + dirs[dirIdx][0];
			int nextX = here.second.second + dirs[dirIdx][1];

			if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M)
			{
				continue;
			}

			if (board[nextY][nextX] == -1)
			{
				continue;
			}

			if (board[nextY][nextX] == 1)
			{
				continue;
			}

			--zeroNums;
			board[nextY][nextX] = 1;
			q.push(make_pair(here.first + 1, make_pair(nextY, nextX)));
		}
	}

	if (zeroNums != 0)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << maxDay << "\n";
	}

	return 0;
}