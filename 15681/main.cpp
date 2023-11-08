#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> adjacentList;
vector<bool> visited;
vector<vector<int>> tree;
vector<int> treeSize;
vector<int> countNodes;

void MakeTree(int currentNode)
{
	visited[currentNode] = true;
	for (int& connectedNode : adjacentList[currentNode])
	{
		if (visited[connectedNode] == true)
			continue;
		tree[currentNode].push_back(connectedNode);
		MakeTree(connectedNode);
	}
}

void SetCountNodes(int parent)
{
	int count = 0;
	countNodes[parent] += 1;
	for (int& childNode : tree[parent])
	{
		SetCountNodes(childNode);
		countNodes[parent] += countNodes[childNode];
	}
}

int main(void)
{
	int N, R, Q;
	scanf("%d%d%d", &N, &R, &Q);
	
	adjacentList.resize(N + 1);
	tree.resize(N + 1);
	visited.resize(N + 1, false);
	countNodes.resize(N + 1, 0);

	for (int n = 0; n < N - 1; ++n)
	{
		int start, target;
		scanf("%d%d", &start, &target);
		adjacentList[start].push_back(target);
		adjacentList[target].push_back(start);
	}

	MakeTree(R);
	SetCountNodes(R);

	for (int q = 0; q < Q; ++q)
	{
		int node;
		scanf("%d", &node);
		printf("%d\n", countNodes[node]);
	}
	return 0;
}