#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <utility>

using namespace std;

vector<vector<bool>> discovered;

int dirs[8][2] = {
	{ +1, -2 },
	{ +2, -1 },
	{ +2, +1 },
	{ +1, +2 },
	{ -1, +2 },
	{ -2, +1 },
	{ -2, -1 },
	{ -1, -2 }
};

int BFS(int start_y, int start_x, int target_y, int target_x, int limit_len)
{
	queue < pair<int, pair<int, int>>> q;
	
	q.push({ 0, { start_y, start_x } });
	discovered[start_y][start_x] = true;

	int num = 0;
	while (q.empty() == false)
	{
		pair<int, pair<int, int>> here = q.front();
		int here_y = here.second.first;
		int here_x = here.second.second;
		int here_count = here.first;
		q.pop();

		if (here_y == target_y && here_x == target_x)
		{
			num = here_count;
			break;
		}

		for (int dir_i = 0; dir_i < 8; ++dir_i)
		{
			int next_y = here_y + dirs[dir_i][0];
			int next_x = here_x + dirs[dir_i][1];

			if (next_y < 0 || next_x < 0 || next_y >= limit_len || next_x >= limit_len)
				continue;

			if (discovered[next_y][next_x] == true)
				continue;
			
			discovered[next_y][next_x] = true;
			q.push({ here_count + 1, {next_y, next_x} });
		}
	}
	return num;
}

int SetBoardGame()
{
	int len;
	scanf("%d", &len);
	discovered.clear();
	discovered.resize(len + 1, vector<bool>(len + 1, false));
	return len;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	
	for (int t = 0; t < T; ++t)
	{
		int len = SetBoardGame();
		
		int start_y, start_x;
		scanf("%d%d", &start_y, &start_x);
		
		int target_y, target_x;
		scanf("%d%d", &target_y, &target_x);

		int answer = BFS(start_y, start_x, target_y, target_x, len);
		printf("%d\n", answer);
	}
	return 0;
}