#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>


typedef struct _NODE
{
	int _val;
	struct _NODE* _next;
	struct _NODE* _prev;
} Node;

typedef struct _QUEUE
{
	int _count;
	struct _NODE* _head;
	struct _NODE* _tail;
} Queue;

void CreateQueue(Queue** queue)
{
	(*queue) = (Queue*)malloc(sizeof(Queue));
	(*queue)->_count = 0;
	(*queue)->_head = (Node*)malloc(sizeof(Node));
	(*queue)->_tail = (Node*)malloc(sizeof(Node));
	
	(*queue)->_head->_next = (*queue)->_tail;
	(*queue)->_tail->_prev = (*queue)->_head;
	
	(*queue)->_head->_val = 0;
	(*queue)->_tail->_val = 0;
}

void Enqueue(Queue** queue, int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_val = val;
	newNode->_next = (*queue)->_tail;
	newNode->_prev = (*queue)->_tail->_prev;

	(*queue)->_tail->_prev->_next = newNode;
	(*queue)->_tail->_prev = newNode;
	(*queue)->_count++;
}

Node* Front(Queue** queue)
{
	return (*queue)->_head->_next;
}

void Dequeue(Queue** queue)
{
	Node* poppedNode = Front(queue);
	(*queue)->_head->_next = poppedNode->_next;
	poppedNode->_next->_prev = (*queue)->_head;
	(*queue)->_count--;
	poppedNode = NULL;
	free(poppedNode);
}

void DestroyQueue(Queue** queue)
{
	while ((*queue)->_count != 0)
	{
		Dequeue(queue);
	}
	(*queue)->_head = NULL;
	free((*queue)->_head);
	(*queue)->_tail = NULL;
	free((*queue)->_tail);
}

void Bfs(int*** graph, bool** visited, int here, int N)
{
	Queue* q;
	CreateQueue(&q);
	Enqueue(&q, here - 1);
	(*visited)[here - 1] = true;
	
	while (q->_count != 0)
	{
		here = Front(&q)->_val;
		Dequeue(&q);
		printf("%d ", here + 1);
		
		for (int there = 0; there < N; ++there)
		{
			if ((*graph)[here][there] == 0)
				continue;
			if ((*visited)[there] == true)
				continue;
			Enqueue(&q, there);
			(*visited)[there] = true;
		}
	}
	DestroyQueue(&q);
}

void Dfs(int*** graph, bool** visited, int here, int N)
{
	(*visited)[here - 1] = true;
	printf("%d ", here);
	for (int there = 0; there < N; ++there)
	{
		if ((*graph)[here - 1][there] == 0)
			continue;
		if ((*visited)[there] == false)
			Dfs(graph, visited, there + 1, N);
	}
}

int main(void)
{
	int N, M, V;
	scanf("%d%d%d", &N, &M, &V);
	fflush(stdin);
	
	// Create Graph
	int** graph = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; ++i)
		*(graph + i) = (int*)calloc(N, sizeof(int*));

	// Add Line
	for (int i = 0; i < M; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		fflush(stdin);
		graph[y - 1][x - 1] = 1;
		graph[x - 1][y - 1] = 1;
	}

	bool* visited = (bool*)calloc(N, sizeof(bool));
	Dfs(&graph, &visited, V, N);
	memset(visited, false, sizeof(bool) * N);
	printf("\n");
	Bfs(&graph, &visited, V, N);
	
	visited = NULL;
	free(visited);
	for (int row = 0; row < N; ++row)
	{
		graph[row] = NULL;
		free(graph[row]);
	}
	free(graph);
	
	return 0;
}