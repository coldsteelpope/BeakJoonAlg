#include <iostream>
#include <queue>
#include <map>

#define MAX 1000000000

typedef struct _NODE
{
	long long _data;
	int _time;
} Node;

using namespace std;
map<int, bool> discovered;
//bool discovered[MAX + 1] = { 0, };

int main(void)
{
	int A, B;
	cin >> A >> B;

	queue<Node> q;
	q.push({ A, 0 });
	discovered[A] = true;

	int min_time = -2;
	while (q.empty() == false)
	{
		Node here = q.front();
		q.pop();
		
		if (here._data == B)
		{
			min_time = here._time;
			break;
		}

		if (here._data * 2 <= MAX && here._data * 2 != 0 && discovered[here._data * 2] == false)
		{
			q.push({ here._data * 2, here._time + 1 });
			discovered[here._data * 2] = true;
		}

		if ((here._data) * 10 + 1 <= MAX && discovered[(here._data * 10) + 1] == false)
		{
			q.push({ (here._data) * 10 + 1, here._time + 1 });
			discovered[(here._data) * 10 + 1] = true;
		}
	}

	cout << min_time + 1 << endl;
}