#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _EDGE
{
	int src;
	int dest;
	int weight;
} Edge;

typedef struct _GRAPH
{
	// V: ������ ����
	// E: ������ ����
	int V;
	int E;
	Edge* edge;
} Graph;

Graph* CreateGraph(int V, int E)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->E = E;
	graph->edge = (Edge*)malloc(sizeof(Edge) * E);
	return graph;
}

// ����-���� �˰���
void BellmanFord(Graph* graph, int src)
{
	// src: ���� ���
	int V = graph->V;
	int E = graph->E;
	
	int* dist = (int*)malloc(sizeof(int) * V);
	for (int i = 0; i < V; ++i)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 1; i <= V - 1; ++i)
	{
		for (int j = 0; j < E; ++j)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	for (int i = 0; i < E; ++i)
	{
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;

		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
		{
			printf("���� ����Ŭ�� �����մϴ�.\n");
			return;
		}
	}

	printf("����\t�ִܰŸ�\n");
	for (int i = 0; i < V; ++i)
		printf("%d\t%d\n", i, dist[i]);

	free(dist);
}

int main() {
	int V = 5; // ������ ��
	int E = 8; // ������ ��
	Graph* graph = CreateGraph(V, E);

	// ���� �߰�
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;

	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;

	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;

	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;

	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;

	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;

	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 1;

	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3;

	int src = 0; // ���� ����
	BellmanFord(graph, src);

	free(graph->edge);
	free(graph);

	return 0;
}