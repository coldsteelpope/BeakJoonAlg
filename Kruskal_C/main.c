#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int _parent[10001] = { 0, };
int _rank[10001] = { 0, };

void SetParent(int V)
{
	for (int i = 1; i <= V; ++i)
	{
		_parent[i] = i;
		_rank[i] = 1;
	}
}

int Find(int u)
{
	if (u == _parent[u])
		return u;
	// 부대장이 아닌 대장으로 초기화해서 최적화
	_parent[u] = Find(_parent[u]);
	return _parent[u];
}

void Swap(int* u, int* v)
{
	int temp = *u;
	*u = *v;
	*v = temp;
}

void Merge(int u, int v)
{
	u = Find(u);
	v = Find(v);
	
	if (u == v)
		return;
	
	if (_rank[u] > _rank[v])
		Swap(&u, &v);
	
	_parent[u] = v;
	if (_rank[u] == _rank[v])
		_rank[v]++;
}

typedef struct _EDGE
{
	int _start;
	int _target;
	int _cost;
} Edge;

Edge edges[100001] = { 0, };
Edge selected[100001] = { 0, };
int selected_index = 0;
Edge temp[100001] = { 0, };

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (edges[leftIdx]._cost <= edges[rightIdx]._cost)
		{
			temp[tempIdx++] = edges[leftIdx++];
		}
		else
		{
			temp[tempIdx++] = edges[rightIdx++];
		}
	}
	
	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = edges[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = edges[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		edges[left + i] = temp[i];
	}
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

int kruskal(int n, int V)
{
	int ret = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int start, target, cost;
		scanf("%d%d%d", &start, &target, &cost);

		edges[i]._start = start;
		edges[i]._target = target;
		edges[i]._cost = cost;
	}

	MergeSort(0, n - 1);
	SetParent(V);

	for (int i = 0; i < n; ++i)
	{
		Edge current_edge = edges[i];
		if (Find(current_edge._start) == Find(current_edge._target))
			continue;
		Merge(current_edge._start, current_edge._target);
		selected[selected_index++] = current_edge;
		ret += current_edge._cost;
	}
	return ret;
}


int main(void)
{
	int V, E;
	scanf("%d%d", &V, &E);
	int cost = kruskal(E, V);
	printf("%d", cost);
	return 0;
}