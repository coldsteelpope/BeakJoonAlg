#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int map[100001] = { 0, };
bool visited[100001] = { 0, };

typedef struct _NODE
{
	int _x;
	int _c;
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
	
	(*queue)->_head->_x = 0; (*queue)->_head->_c = 0;
	(*queue)->_rear->_x = 0; (*queue)->_rear->_c = 0;

	(*queue)->_head->_next = (*queue)->_rear; (*queue)->_head->_prev = NULL;
	(*queue)->_rear->_prev = (*queue)->_head; (*queue)->_rear->_next = NULL;
}

void Push(Queue** queue, int x, int c)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_x = x;
	newNode->_c = c;

	(*queue)->_rear->_prev->_next = newNode;
	newNode->_prev = (*queue)->_rear->_prev;
	
	newNode->_next = (*queue)->_rear;
	(*queue)->_rear->_prev = newNode;

	(*queue)->_count++;
}

Node* FrontNode(Queue** queue)
{
	return (*queue)->_head->_next;
}

void Pop(Queue** queue)
{
	Node* poppedNode = FrontNode(queue);
	(*queue)->_count--;

	(*queue)->_head->_next = poppedNode->_next;
	poppedNode->_next->_prev = (*queue)->_head;

	free(poppedNode);
}

bool Empty(Queue** queue)
{
	return (*queue)->_count == 0;
}

void DestroyQueue(Queue** queue)
{
	if (Empty(queue) == false)
	{
		Pop(queue);
	}
	free((*queue)->_head);
	free((*queue)->_rear);
	free((*queue));
}



int main(void)
{
	Queue* queue;
	int N, K;
	scanf("%d%d", &N, &K);
	
	CreateQueue(&queue);
	Push(&queue, N, 0);
	visited[N] = true;

	while (Empty(&queue) == false)
	{
		Node* poppedNode = FrontNode(&queue);

		if (poppedNode->_x == K)
		{
			printf("%d\n", poppedNode->_c);
			break;
		}

		int nextX[3] = {
			poppedNode->_x - 1,
			poppedNode->_x + 1,
			poppedNode->_x * 2
		};
		int nextXLen = sizeof(nextX) / sizeof(int);
		
		for (int nextXIdx = 0; nextXIdx < nextXLen; ++nextXIdx)
		{
			int x = nextX[nextXIdx];
			if (x < 0 || x >= 100001)
				continue;
			if (visited[x] == true)
				continue;
			visited[x] = true;
			Push(&queue, x, poppedNode->_c + 1);
		}
		Pop(&queue);
	}
	
	DestroyQueue(&queue);
}