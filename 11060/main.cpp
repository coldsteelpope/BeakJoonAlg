#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>

using namespace std;
vector<int> maze;
map<int, bool> discovered;

int main(void)
{
	int N;
	cin >> N;
	maze.push_back(0);
	for (int i = 0; i < N; ++i)
	{
		int jump;
		cin >> jump;
		maze.push_back(jump);
	}

	queue<pair<int, int>> q;
	q.push({0, 1});
	discovered[1] = true;

	int min_distance = -1;
	while (q.empty() == false)
	{
		pair<int,int> here = q.front();
		q.pop();

		if (here.second >= N)
		{
			min_distance = here.first;
			break;
		}

		int here_jump = maze[here.second];
		for (int j = 1; j <= here_jump; ++j)
		{
			if (here.second + j > N)
				continue;
			if (discovered[here.second+ j] == true)
				continue;
			
			discovered[here.second + j] = true;
			q.push({ here.first + 1, here.second + j });
		}
	}

	cout << min_distance << endl;
	
	return 0;
}