#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <map>

using namespace std;

vector<pair<int, int>> coms;
vector<vector<int>> adjacentList;
bool discovered[10001] = { 0, };

void ResetDiscovered(int N)
{
	for (int i = 0; i <= N; i++) {
		discovered[i] = 0;
	}
}

int bfs(int here)
{
	queue<int> q;
	q.push(here);
	discovered[here] = true;
	
	int hacking_computer = 0;
	while (q.empty() == false)
	{
		int here = q.front();
		q.pop();
		
		for (int there_index = 0; there_index < adjacentList[here].size(); ++there_index)
		{
			int there = adjacentList[here][there_index];
			if (discovered[there] == true)
				continue;
			hacking_computer++;
			discovered[there] = true;
			q.push(there);
		}
	}
	return hacking_computer;
}

int compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
	{
		return a.first > b.first;
	}
	return a.second < b.second;
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	
	adjacentList.resize(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int target, start;
		cin >> target >> start;
		adjacentList[start].push_back(target);
	}

	int max_value = 0;
	for (int com_num = 1; com_num <= N; ++com_num)
	{
		int hacked_coms = bfs(com_num);
		max_value = (max_value > hacked_coms) ? max_value : hacked_coms;
		coms.push_back({ hacked_coms, com_num });
		ResetDiscovered(N);
	}


	for (int i = 0; i < coms.size(); ++i)
	{
		if (coms[i].first == max_value)
		{
			cout << coms[i].second << " ";
		}
	}
	return 0;
}