#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define INF (~0U >> 2)

using namespace std;

vector<vector<int>> adjacentList;
map<int, bool> visited;

int len[100001] = { 0, };
int visited_num = 0;

inline int compare(int& a, int& b)
{
	return a > b;
}

void DFS(int here)
{
	visited[here] = true;
	len[here] = ++visited_num;
	//len[here] = (len[here] > dist) ? dist : len[here];
	for (int there_idx = 0; there_idx < adjacentList[here].size(); ++there_idx)
	{
		int there = adjacentList[here][there_idx];
		if (visited[there] == true)
			continue;
		DFS(there);
	}
}

void SetAdjacentList(int M, int N)
{
	for (int m = 1; m <= M; ++m)
	{
		int start_pos, target_pos;
		scanf("%d%d", &start_pos, &target_pos);
		adjacentList[start_pos].push_back(target_pos);
		adjacentList[target_pos].push_back(start_pos);
	}

	for (int i = 1; i <= N; ++i)
	{
		sort(adjacentList[i].begin(), adjacentList[i].end(), compare);
	}
}

int main(void)
{
	// N: 정점의 수, M: 간선의 수, R: 시작 정점
	int N, M, R;
	scanf("%d%d%d", &N, &M, &R);
	adjacentList.resize(N + 1);
	SetAdjacentList(M, N);
	DFS(R);

	for (int i = 1; i <= N; ++i)
	{
		if (len[i] == INF)
			printf("%d\n", 0);
		else
			printf("%d\n", len[i]);		
	}
	return 0;
}