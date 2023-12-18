#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Conference
{
	int _startT;
	int _endT;
	int _num;
};

int maxValue = 0;
vector<Conference> conferences;

void DFS(int startIdx, int end, int sum)
{
	maxValue = (maxValue > sum) ? maxValue : sum;
	for (int i = startIdx; i < conferences.size(); ++i)
	{
		if (end <= conferences[i]._startT)
		{
			DFS(i + 1, conferences[i]._endT, sum + conferences[i]._num);
		}
	}
}

int main(void)
{
	int N;
	cin >> N;
	conferences.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> conferences[i]._startT >> conferences[i]._endT >> conferences[i]._num;
	}
	std::sort(conferences.begin(), conferences.end(), [](Conference a, Conference b)->bool{
		if (a._endT == b._endT)
		{
			return a._startT < b._startT;
		}
		else
		{
			return a._endT < b._endT;
		}
	});
	DFS(0, 0, 0);
	cout << maxValue << endl;
	return 0;
}