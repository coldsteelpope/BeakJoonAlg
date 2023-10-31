#include <iostream>
#include <queue>

using namespace std;

typedef struct _POS
{
	int _visited_num;
	int _time;
} Pos;

typedef struct _NODE
{
	int _x;
	int _time;
} Node;

Pos map[100001] = { 0, };
bool discovered[100001] = { 0, };

int main(void)
{
	int N, K;
	cin >> N >> K;

	queue<Node> q;
	discovered[N] = true;
	q.push({ N, 0 });

	int min_time = 0;
	bool is_find_in_min_time = false;

	while (q.empty() == false)
	{
		Node here = q.front();
		q.pop();

		discovered[here._x] = true;

		if (is_find_in_min_time == true && here._x == K && min_time == here._time)
		{
			map[here._x]._visited_num++;
		}

		if (is_find_in_min_time == false && here._x == K)
		{
			min_time = here._time;
			is_find_in_min_time = true;
			map[here._x]._visited_num++;
		}
		
		if (here._x + 1 <= 100000 && discovered[here._x + 1] == false)
		{
			q.push({ here._x + 1, here._time + 1 });
		}

		if (here._x - 1 >= 0 && discovered[here._x - 1] == false)
		{
			q.push({ here._x - 1, here._time + 1 });
		}

		if (here._x * 2 <= 100000 && here._x * 2 != 0 && discovered[here._x * 2] == false)
		{
			q.push({ here._x * 2, here._time + 1 });
		}

	}

	cout << min_time << endl;
	cout << map[K]._visited_num << endl;
}