#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef struct _NODE
{
	int _amount;
	int _y;
	int _x;
	int _dist;
} Node;

Node map[21][21] = { 0, };
bool discovered[21][21] = { 0, };

int N;
int current_shark_num_eats = 0;
int current_shark_size = 2;
int current_shark_pos_y = 0;
int current_shark_pos_x = 0;

int total_dist = 0;
vector<Node> can_eat_fishes;

bool compare(Node fish_one, Node fish_two)
{	
	if (fish_one._dist == fish_two._dist)
	{
		if (fish_one._y == fish_two._y)
		{
			return fish_one._x < fish_two._x;
		}
		else
		{
			return fish_one._y < fish_two._y;
		}
	}
	else
	{
		return fish_one._dist < fish_two._dist;
	}
}

void ClearCanEatFishes()
{
	can_eat_fishes.clear();
}

void ClearDiscovered()
{
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			discovered[y][x] = false;
}

void SetMap()
{
	cin >> N;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cin >> map[y][x]._amount;
			map[y][x]._y = y; map[y][x]._x = x; map[y][x]._dist = 0;
			if (map[y][x]._amount == 9)
			{
				current_shark_pos_y = y;
				current_shark_pos_x = x;
			}
		}
	}
}


void Search()
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (map[y][x]._amount != 0)
			{
				if (map[y][x]._amount == 9)
					continue;
				if (map[y][x]._amount < current_shark_size)
					can_eat_fishes.push_back(map[y][x]);
				else if (map[y][x]._amount > current_shark_size)
					discovered[y][x] = true;
			}
		}
	}
}

int GetMinDistUsingBFS(int target_y, int target_x)
{
	bool temp_discovered[21][21] = { 0, };
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			temp_discovered[i][j] = discovered[i][j];

	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {current_shark_pos_y, current_shark_pos_x} });
	temp_discovered[current_shark_pos_y][current_shark_pos_x] = true;

	int min_dist = -1;
	while (q.empty() == false)
	{
		pair<int, pair<int, int>> here = q.front();
		q.pop();

		if (here.second.first == target_y && here.second.second == target_x)
		{
			min_dist = here.first;
			break;
		}
		
		int dirs[4][2] = {
			{+0, +1},
			{+1, +0},
			{+0, -1},
			{-1, +0}
		};

		for (int dirs_i = 0; dirs_i < 4; ++dirs_i)
		{
			int next_y = dirs[dirs_i][0] + here.second.first;
			int next_x = dirs[dirs_i][1] + here.second.second;
			
			if (next_y < 0 || next_x < 0 || next_x >= N || next_y >= N)
				continue;
			if (temp_discovered[next_y][next_x] == true)
				continue;
			
			temp_discovered[next_y][next_x] = true;
			q.push({ here.first + 1, {next_y, next_x} });
		}
	}
	return min_dist;
}

void PrintMap()
{
	cout << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << map[i][j]._amount << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Process()
{
	//PrintMap();

	while (1)
	{
		Search();
		if (can_eat_fishes.size() == 0)
		{
			break;
		}
		else
		{

			vector<Node> candidates;

			for (int i = 0; i < can_eat_fishes.size(); ++i)
			{
				Node current_fish = can_eat_fishes[i];
				int min_dist = GetMinDistUsingBFS(current_fish._y, current_fish._x);
				if (min_dist != -1)
				{
					can_eat_fishes[i]._dist = min_dist;
					candidates.push_back(can_eat_fishes[i]);
				}
			}

			if (candidates.size() == 0)
			{
				break;
			}
			else
			{
				sort(candidates.begin(), candidates.end(), compare);
				Node eat_fish = candidates[0];

				//cout << total_dist << "s / " << "LV. " << current_shark_size << " (Exp " << current_shark_num_eats << " / " << current_shark_size << ")" << endl;

				map[current_shark_pos_y][current_shark_pos_x]._amount = 0;
				map[current_shark_pos_y][current_shark_pos_x]._dist = 0;

				current_shark_pos_y = eat_fish._y;
				current_shark_pos_x = eat_fish._x;

				++current_shark_num_eats;
				if (current_shark_size <= current_shark_num_eats)
				{
					++current_shark_size;
					current_shark_num_eats = 0;
				}

				total_dist += eat_fish._dist;
				map[current_shark_pos_y][current_shark_pos_x]._amount = 9;
			}

		}

		//PrintMap();
		ClearDiscovered();
		ClearCanEatFishes();
	}

	cout << total_dist << endl;
}

int main(void)
{
	SetMap();
	Process();
	return 0;
}