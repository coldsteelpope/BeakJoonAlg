#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<pair<string, int>>> rooms;

int main(void)
{
	int p, m;
	cin >> p >> m;

	rooms.resize(p);
	int roomsNum = 0;
	for (int i = 0; i < p; ++i)
	{
		string id;
		int level;
		cin >> level >> id;
		int r = 0;

		for (r = 0; r < roomsNum; ++r)
		{
			// 방의 인원 수가 꽉 찰 때 무시하지 않고, 꽉 찬 방에 사람을 우겨넣었다.
			/*
			반례
			5 2
			10 b
			10 a
			10 c
			10 d
			10 e
			*/
			if (rooms[r][0].second - 10 <= level && level <= rooms[r][0].second + 10 && rooms[r].size() < m)
			{
				rooms[r].emplace_back(make_pair(id, level));
				break;
			}
		}

		if (r == roomsNum)
		{
			rooms[r].emplace_back(make_pair(id, level));
			++roomsNum;
		}
	}

	for (int r = 0; r < roomsNum; ++r)
	{
		std::sort(rooms[r].begin(), rooms[r].end());
		if (rooms[r].size() == m)
		{
			cout << "Started!" << endl;
		}
		else
		{
			cout << "Waiting!" << endl;
		}
		for (int i = 0; i < rooms[r].size(); ++i)
		{
			cout << rooms[r][i].second << " " << rooms[r][i].first << endl;
		}
	}
	return 0;
}