#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int map[1000][1000] = { 0, };
int result[1000][1000] = { 0, };
bool discovered[1000][1000] = { 0, };

typedef struct _NODE
{
	int _y;
	int _x;
	int _count;
	struct _NODE* _next;
	struct _NODE* _prev;
} Node;

typedef struct _QUEUE
{
	int _count;
	Node* _head;
	Node* _rear;
} Queue;

void CreateQueue(Queue** queue)
{
	(*queue) = (Queue*)malloc(sizeof(Queue));
	(*queue)->_count = 0;
	
	(*queue)->_head = (Node*)malloc(sizeof(Node));
	(*queue)->_rear = (Node*)malloc(sizeof(Node));
	
	(*queue)->_head->_x = 0; (*queue)->_head->_y = 0; (*queue)->_head->_count = 0; (*queue)->_head->_next = (*queue)->_rear; (*queue)->_head->_prev = NULL;
	(*queue)->_rear->_x = 0; (*queue)->_rear->_y = 0; (*queue)->_rear->_count = 0; (*queue)->_rear->_prev = (*queue)->_head; (*queue)->_rear->_next = NULL;
}

void Push(Queue** queue, int y, int x, int count)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_y = y; newNode->_x = x; newNode->_count = count;
	
	(*queue)->_count++;

	(*queue)->_rear->_prev->_next = newNode;
	newNode->_prev = (*queue)->_rear->_prev;
	
	newNode->_next = (*queue)->_rear;
	(*queue)->_rear->_prev = newNode;
}

Node* Front(Queue** queue)
{
	return (*queue)->_head->_next;
}

void Pop(Queue** queue)
{
	Node* poppedNode = Front(queue);
	(*queue)->_head->_next = poppedNode->_next;
	poppedNode->_next->_prev = (*queue)->_head;
	(*queue)->_count--;
	free(poppedNode);
}

bool Empty(Queue** queue)
{
	return (*queue)->_count == 0;
}

void DestroyQueue(Queue** queue)
{
	while (Empty(queue) == false)
	{
		Pop(queue);
	}
	free((*queue)->_head);
	free((*queue)->_rear);
	free((*queue));
}

void PrintMap(int n, int m)
{
	printf("\n");
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			printf("%d ", map[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetResultMinusOne(int n, int m)
{
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			result[y][x] = -1;
		}
	}
}

void PrintResult(int n, int m)
{
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			printf("%d ", result[y][x]);
		}
		printf("\n");
	}
}

int main(void)
{
	Queue* queue;
	CreateQueue(&queue);

	
	int start_y = 0;
	int start_x = 0;
	int n, m;

	scanf("%d%d", &n, &m);
	SetResultMinusOne(n, m);

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			scanf("%d", &map[y][x]);
			if (map[y][x] == 2)
			{
				start_y = y; 
				start_x = x;
			}
			else if (map[y][x] == 0)
				result[y][x] = 0;
		}
	}

	int dirs[4][2] = {
		{+0, +1},
		{+1, +0},
		{+0, -1},
		{-1, +0}
	};
	
	discovered[start_y][start_x] = true;
	Push(&queue, start_y, start_x, 0);

	while (Empty(&queue) == false)
	{
		Node* poppedNode = Front(&queue);
		result[poppedNode->_y][poppedNode->_x] = poppedNode->_count;

		for (int dirs_index = 0; dirs_index < 4; dirs_index++)
		{
			int next_y = poppedNode->_y + dirs[dirs_index][0];
			int next_x = poppedNode->_x + dirs[dirs_index][1];

			if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n)
				continue;
			if (discovered[next_y][next_x] == true)
				continue;
			if (map[next_y][next_x] == 0)
				continue;
			
			discovered[next_y][next_x] = true;
			Push(&queue, next_y, next_x, poppedNode->_count + 1);
		}
		Pop(&queue);
	}

	DestroyQueue(&queue);
	PrintResult(n, m);

	return 0;
}