#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
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
	
	(*queue)->_head->_count = 0; (*queue)->_head->_x = 0;
	(*queue)->_rear->_count = 0; (*queue)->_rear->_x = 0;

	(*queue)->_head->_next = (*queue)->_rear;
	(*queue)->_rear->_prev = (*queue)->_head;
}

void Push(Queue** queue, int x, int count)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_count = count;
	newNode->_x = x;
	
	(*queue)->_rear->_prev->_next = newNode;
	newNode->_prev = (*queue)->_rear->_prev;
	
	newNode->_next = (*queue)->_rear;
	(*queue)->_rear->_prev = newNode;

	(*queue)->_count++;
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

bool discovered[101] = { 0, };
int ladders[101] = { 0, };
int snakes[101] = { 0, };

// ladder = 1
// snake = 2
int main(void)
{
	// N = 사다리의 수
	// M = 뱀의 수
	Queue* queue;
	CreateQueue(&queue);

	int N, M;
	scanf("%d%d", &N, &M);

	for (int ladder = 0; ladder < N; ++ladder)
	{
		int idx, val;
		scanf("%d%d", &idx, &val);
		ladders[idx] = val;
	}

	for (int snake = 0; snake < M; ++snake)
	{
		int idx, val;
		scanf("%d%d", &idx, &val);
		snakes[idx] = val;
	}

	discovered[1] = true;
	Push(&queue, 1, 0);
	int minCount = 2147483647;

	while (Empty(&queue) == false)
	{
		Node* frontNode = Front(&queue);
		if (frontNode->_x == 100)
		{
			minCount = frontNode->_count;
			break;
		}
		for (int dice = 1; dice <= 6; ++dice)
		{
			int nextX = frontNode->_x + dice;
			
			if (nextX > 100)
				continue;
			if (discovered[nextX] == true)
				continue;
			
			if (ladders[nextX] != 0)
				nextX = ladders[nextX];
			else if (snakes[nextX] != 0)
				nextX = snakes[nextX];
			
			discovered[nextX] = true;
			Push(&queue, nextX, frontNode->_count + 1);
		}
		Pop(&queue);
	}
	printf("%d", minCount);
	DestroyQueue(&queue);
	return 0;
}