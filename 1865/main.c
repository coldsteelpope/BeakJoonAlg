#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 10001

typedef struct _EDGE
{
	int _src;
	int _dest;
	int _weight;
} Edge;

typedef struct _GRAPH
{
	int _usedIdx;
	int _V;
	int _E;
	Edge* _edges;
} Graph;

void CreateGraph(Graph** graph, int V, int E)
{
	(*graph) = (Graph*)malloc(sizeof(Graph));
	(*graph)->_V = V;
	(*graph)->_E = E;
	(*graph)->_usedIdx = 0;
	(*graph)->_edges = (Edge*)malloc(sizeof(Edge) * E);
}

void DestroyGraph(Graph** graph)
{
	free((*graph)->_edges);
	free((*graph));
}

long long dist[505] = { 0, };

void SetDist(int V)
{
	for (int i = 0; i <= V; ++i)
		dist[i] = INF;
}

bool BellmandFord(Graph** graph)
{
	int verticesNum = (*graph)->_V;
	int edgesNum = (*graph)->_E;

	SetDist(verticesNum);
	dist[1] = 0;

	for (int iter_num = 1; iter_num <= verticesNum; ++iter_num)
	{
		for (int e = 0; e < edgesNum; ++e)
		{
			int start_node = (*graph)->_edges[e]._src;
			int target_node = (*graph)->_edges[e]._dest;
			int weight = (*graph)->_edges[e]._weight;

			if (dist[start_node] + weight < dist[target_node])
				dist[target_node] = dist[start_node] + weight;
		}
	}

	bool infinite = false;
	for (int e = 0; e < edgesNum; ++e)
	{
		int start_node = (*graph)->_edges[e]._src;
		int target_node = (*graph)->_edges[e]._dest;
		int weight = (*graph)->_edges[e]._weight;

		if (dist[start_node] + weight < dist[target_node])
		{
			infinite = true;
			break;
		}
	}
	return infinite;
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; ++t)
	{
		int N, M, W;
		Graph* graph;
		scanf("%d%d%d", &N, &M, &W);
		CreateGraph(&graph, N, 2 * M + W);

		for (int e = 0; e < M; ++e)
		{
			int src, dest, weight;
			scanf("%d%d%d", &src, &dest, &weight);

			graph->_edges[graph->_usedIdx]._src = src;
			graph->_edges[graph->_usedIdx]._dest = dest;
			graph->_edges[graph->_usedIdx]._weight = weight;

			graph->_usedIdx += 1;

			graph->_edges[graph->_usedIdx]._src = dest;
			graph->_edges[graph->_usedIdx]._dest = src;
			graph->_edges[graph->_usedIdx]._weight = weight;

			graph->_usedIdx += 1;
		}

		for (int e = 0; e < W; ++e)
		{
			int src, dest, weight;
			scanf("%d%d%d", &src, &dest, &weight);

			graph->_edges[graph->_usedIdx]._src = src;
			graph->_edges[graph->_usedIdx]._dest = dest;
			graph->_edges[graph->_usedIdx]._weight = -weight;

			graph->_usedIdx += 1;
		}

		bool success = BellmandFord(&graph);

		if (success)
			printf("YES\n");
		else
			printf("NO\n");

		DestroyGraph(&graph);
	}
}