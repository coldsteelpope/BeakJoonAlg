#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	int _result;
	int _t;
	struct _NODE* _next;
	struct _NODE* _prev;
} Node;

typedef struct _QUEUE
{
	int _count;
	Node* _head;
	Node* _rear;
} Queue;

void CreateQueue(Queue** q)
{
	(*q) = (Queue*)malloc(sizeof(Queue));
	(*q)->_count = 0;

	(*q)->_head = (Node*)malloc(sizeof(Node));
	(*q)->_rear = (Node*)malloc(sizeof(Node));

	(*q)->_head->_result = -1;
	(*q)->_head->_t = -1;

	(*q)->_rear->_result = -1;
	(*q)->_rear->_t = -1;

	(*q)->_head->_next = (*q)->_rear;
	(*q)->_head->_prev = NULL;

	(*q)->_rear->_prev = (*q)->_head;
	(*q)->_rear->_next = NULL;
}

void Push(Queue** q, int result, int t)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_result = result;
	newNode->_t = t;

	(*q)->_count++;
	(*q)->_rear->_prev->_next = newNode;
	newNode->_prev = (*q)->_rear->_prev;
	
	newNode->_next = (*q)->_rear;
	(*q)->_rear->_prev = newNode;
}

Node* Front(Queue** q)
{
	return (*q)->_head->_next;
}

void Pop(Queue** q)
{
	Node* poppedNode = Front(q);
	poppedNode->_prev->_next = poppedNode->_next;
	poppedNode->_next->_prev = poppedNode->_prev;
	(*q)->_count--;
	free(poppedNode);
}

bool Empty(Queue** q)
{
	return (*q)->_count == 0;
}

void Destroy(Queue** q)
{
	while (Empty(q) == false)
		Pop(q);
	free((*q)->_head);
	free((*q)->_rear);
	free((*q));
}


int main(void)
{
	Queue* q;
	CreateQueue(&q);

	int N;
	scanf("%d", &N);
	Push(&q, N, 0);
	
	int answer = 0;
	while (Empty(&q) == false)
	{
		Node* frontNode = Front(&q);

		if (frontNode->_result == 1)
		{
			answer = frontNode->_t;
			break;
		}
		else if(frontNode->_result > 1)
		{
			if (frontNode->_result % 2 == 0)
			{
				Push(&q, frontNode->_result / 3, frontNode->_t + 1);
			}
			
			if (frontNode->_result % 3 == 0)
			{
				Push(&q, frontNode->_result / 2, frontNode->_t + 1);
			}

			Push(&q, frontNode->_result - 1, frontNode->_t + 1);
		}
		Pop(&q);
	}

	printf("%d", answer);
	Destroy(&q);
}