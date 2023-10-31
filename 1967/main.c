#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	int _next;
	int _weight;
} Node;

Node* node[10001][10001] = {0,};
bool visited[10001] = { 0, };


int maxVal = 0;
int endPoint = 0;
void Dfs(int here, int n, int cost)
{
	visited[here] = true;
	if (maxVal < cost)
	{
		maxVal = cost;
		endPoint = here;
	}
	for (int there = 1; there <= n; ++there)
	{
		if (visited[there] == true)
			continue;
		if (node[here][there] == NULL)
			continue;
		Dfs(node[here][there]->_next, n, cost + node[here][there]->_weight);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n - 1; ++i)
	{
		int parent_num, child_num, weight;
		scanf("%d%d%d", &parent_num, &child_num, &weight);
		
		Node* parentNode = (Node*)malloc(sizeof(Node));
		parentNode->_next = child_num;
		parentNode->_weight = weight;
		node[parent_num][child_num] = parentNode;

		Node* childNode = (Node*)malloc(sizeof(Node));
		childNode->_next = parent_num;
		childNode->_weight = weight;
		node[child_num][parent_num] = childNode;
	}
	Dfs(1, n, 0);
	for (int i = 0; i < 10001; ++i)
		visited[i] = false;
	maxVal = 0;
	Dfs(endPoint, n, 0);
	printf("%d\n", maxVal);
	return 0;
}