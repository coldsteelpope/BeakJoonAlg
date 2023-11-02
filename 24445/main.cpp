#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

map<int, vector<int>> adjacentList;
map<int, bool> discovered;
vector<int> answer;

int visited_num = 1;


inline int compare(int a, int b)
{
	return a > b;
}

void BFS(int start_pos)
{
	queue<int> q;
	q.push(start_pos);
	discovered[start_pos] = true;

	while (q.empty() == false)
	{
		int here = q.front();
		answer[here] = visited_num++;
		q.pop();

		for (int i = 0; i < adjacentList[here].size(); ++i)
		{
			int there = adjacentList[here][i];
			if (discovered[there] == true)
				continue;
			discovered[there] = true;
			q.push(there);
		}
	}
}

void SetAdjacentList(int N, int M)
{
	answer.resize(N + 1, 0);
	for (int m = 0; m < M; ++m)
	{
		int start_pos, target_pos;
		scanf("%d%d", &start_pos, &target_pos);
		adjacentList[start_pos].push_back(target_pos);
		adjacentList[target_pos].push_back(start_pos);
	}

	for (auto& ele : adjacentList)
	{
		sort(ele.second.begin(), ele.second.end(), compare);
	}
}

int main(void)
{
	int N, M, R;
	scanf("%d%d%d", &N, &M, &R);

	SetAdjacentList(N, M);
	BFS(R);

	for (int i = 1; i <= N; ++i)
	{
		printf("%d\n", answer[i]);
	}

	return 0;
}