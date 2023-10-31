#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef struct _NODE
{
	int _y;
	int _x;
	int _type;
	int _meet_num;
} Node;


Node map[101][101] = { 0, };
bool discovered[101][101] = { 0, };

void PrintMap(int N, int M)
{
	cout << endl;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cout << map[y][x]._type << " ";
			//cout << discovered[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void InitDiscovered(int N, int M)
{
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			discovered[y][x] = false;
}

void UpdateMap(int N, int M)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (map[y][x]._meet_num >= 2)
			{
				map[y][x]._type = 0;
			}
			map[y][x]._meet_num = 0;
		}
	}
}

bool IsEmptyMap(int N, int M)
{
	bool isEmpty = true;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (map[y][x]._type == 1)
			{
				isEmpty = false;
				break;
			}
		}
	}
	return isEmpty;
}

void BFSForMeetNum(int N, int M)
{
	InitDiscovered(N, M);
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	discovered[0][0] = true;
	
	int dirs[4][2] = {
		{ +0, +1 },
		{ +1, +0 },
		{ +0, -1 },
		{ -1, +0 }
	};

	while (q.empty() == false)
	{
		pair<int, int> here = q.front();
		q.pop();
	

		for (int dir_index = 0; dir_index < 4; dir_index++)
		{
			int next_y = here.first + dirs[dir_index][0];
			int next_x = here.second + dirs[dir_index][1];

			if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
				continue;
			if (discovered[next_y][next_x] == true)
				continue;
			if (map[next_y][next_x]._type == 1)
			{
				map[next_y][next_x]._meet_num += 1;
				continue;
			}
			discovered[next_y][next_x] = true;
			q.push({ next_y, next_x });
		}
	}
	//PrintMap(N, M);
	UpdateMap(N, M);
}

void SetMap(int N, int M)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cin >> map[y][x]._type;
			map[y][x]._y = y; map[y][x]._x = x; map[y][x]._meet_num = 0;
		}
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	SetMap(N, M);
	
	int answer = 0;
	while (IsEmptyMap(N, M) == false)
	{
		BFSForMeetNum(N, M);
		//PrintMap(N, M);
		++answer;
	}
	cout << answer << endl;

	return 0;
}