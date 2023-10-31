#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	Edge* edge;
} Graph;

Graph* CreateGraph(int V, int E)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->_V = V; graph->_E = E;
	graph->edge = (Edge*)malloc(sizeof(Edge) * E);
}

bool BellmanFord(Graph* graph, int src)
{
	int* dist = (int*)malloc(sizeof(int) * graph->_V);
	for (int i = 0; i < graph->_V; ++i)
		dist[i] = (~0U >> 2);
	dist[src] = 0;

	for (int iter_num = 1; iter_num <= graph->_V - 1; ++iter_num)
	{
		for (int e = 0; e < graph->_E; ++e)
		{
			int start_node = graph->edge[e]._src;
			int end_node = graph->edge[e]._dest;
			int weight = graph->edge[e]._weight;

			if (dist[start_node] != (~0U >> 2) && dist[start_node] + weight < dist[end_node])
				dist[end_node] = dist[start_node] + weight;
		}
	}

	for (int i = 0; i < graph->_E; ++i)
	{
		int start_node = graph->edge[i]._src;
		int end_node = graph->edge[i]._dest;
		int weight = graph->edge[i]._weight;

		if (dist[start_node] != (~0U >> 2) && dist[start_node] + weight < dist[end_node])
		{
			printf("음수 사이클이 존재한다.\n");
			return;
		}
	}
}

