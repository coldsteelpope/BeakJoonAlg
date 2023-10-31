#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF (~0U >> 2)

typedef struct _EDGE
{
	int _src;
	int _dest;
	int _weight;
} Edge;

typedef struct _GRAPH
{
	int _V;
	int _E;
	Edge* _edges;
} Graph;

long long dist[501] = { 0, };

void CreateGraph(Graph** graph, int V, int E)
{
	(*graph) = (Graph*)malloc(sizeof(Graph));
	(*graph)->_V = V;
	(*graph)->_E = E;
	(*graph)->_edges = (Edge*)malloc(sizeof(Edge) * E);
}

void DestroyGraph(Graph** graph)
{
	free((*graph)->_edges);
	free((*graph));
}

void SetDist(int N)
{
	for (int i = 0; i <= N; ++i)
	{
		dist[i] = INF;
	}
}

bool BellmandFord(Graph** graph, int start)
{
	int vertexNum = (*graph)->_V;
	int edgesNum = (*graph)->_E;

	SetDist(vertexNum);

	dist[start] = 0;

	bool infinite_loop = false;
	for (int iter_num = 1; iter_num <= vertexNum - 1; ++iter_num)
	{
		for (int e = 0; e < edgesNum; ++e)
		{
			int start_node = (*graph)->_edges[e]._src;
			int target_node = (*graph)->_edges[e]._dest;
			int weight = (*graph)->_edges[e]._weight;

			if (dist[start_node] != INF && dist[start_node] + weight < dist[target_node])
				dist[target_node] = dist[start_node] + weight;
		}
	}

	for (int e = 0; e < edgesNum; ++e)
	{
		int start_node = (*graph)->_edges[e]._src;
		int target_node = (*graph)->_edges[e]._dest;
		int weight = (*graph)->_edges[e]._weight;

		if (dist[start_node] != INF && dist[start_node] + weight < dist[target_node])
		{
			infinite_loop = true;
			break;
		}
	}

	if (infinite_loop == false)
	{
		for (int i = 0; i <= vertexNum; ++i)
		{
			if (dist[i] == INF)
				dist[i] = -1;
		}
	}

	return infinite_loop;
}

int main(void)
{
	Graph* graph;
	// N: µµ½ÃÀÇ °¹¼ö / M: °£¼±ÀÇ °¹¼ö
	int N, M;
	scanf("%d%d", &N, &M);
	CreateGraph(&graph, N, M);
	for (int edges_index = 0; edges_index < M; ++edges_index)
	{
		int start, target, weight;
		scanf("%d%d%d", &start, &target, &weight);

		graph->_edges[edges_index]._src = start;
		graph->_edges[edges_index]._dest = target;
		graph->_edges[edges_index]._weight = weight;
	}
	
	bool infinite_loop = BellmandFord(&graph, 1);
	if (infinite_loop)
		printf("%d", -1);
	else
	{
		//MergeSort(2, graph->_V);
		for (int node = 2; node <= graph->_V; ++node)
		{
			printf("%lld ", dist[node]);
		}
	}
	DestroyGraph(&graph);
}