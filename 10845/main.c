#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _NODE
{
	int _data;
	struct _NODE* _next;
	struct _NODE* _prev;
} Node;

typedef struct _QUEUE
{
	int _count;
	Node* _head;
	Node* _tail;
} Queue;

// 왜 이중 포인터를 사용하는가?

void CreateQueue(Queue** queue)
{
	(*queue) = (Queue*)malloc(sizeof(Queue));

	(*queue)->_count = 0;

	(*queue)->_head = (Node*)malloc(sizeof(Node));
	(*queue)->_tail = (Node*)malloc(sizeof(Node));

	(*queue)->_head->_data = 0;
	(*queue)->_head->_next = (*queue)->_tail;
	(*queue)->_head->_prev = NULL;
	
	(*queue)->_tail->_data = 0;
	(*queue)->_tail->_prev = (*queue)->_head;
	(*queue)->_tail->_next = NULL;
}

void Push(Queue** queue, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_data = data;
	
	(*queue)->_tail->_prev->_next = newNode;
	newNode->_prev = (*queue)->_tail->_prev;
	
	newNode->_next = (*queue)->_tail;
	(*queue)->_tail->_prev = newNode;

	(*queue)->_count++;
}

int Size(Queue** queue)
{
	return (*queue)->_count;
}

bool Empty(Queue** queue)
{
	return (*queue)->_count == 0;
}

int Front(Queue** queue)
{
	if (Empty(queue) == true)
	{
		return -1;
	}
	else
	{
		return (*queue)->_head->_next->_data;
	}
}

int Back(Queue** queue)
{
	if (Empty(queue) == true)
	{
		return -1;
	}
	else
	{
		return (*queue)->_tail->_prev->_data;
	}
}

int Pop(Queue** queue)
{
	if (Empty(queue) == true)
	{
		return -1;
	}
	else
	{
		Node* poppedNode = (*queue)->_head->_next;
		int poppedData = poppedNode->_data;

		poppedNode->_next->_prev = (*queue)->_head;
		(*queue)->_head->_next = poppedNode->_next;

		(*queue)->_count--;
		free(poppedNode);
		return poppedData;
	}
}

void DestroyQueue(Queue** queue)
{
	while (Empty(queue) == false)
	{
		Pop(queue);
	}
	free((*queue)->_head);
	free((*queue)->_tail);
	free((*queue));
}



int main(void)
{
	Queue* q;
	CreateQueue(&q);

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		char command[8] = { 0, };
		scanf("%s", command);
		
		if (strcmp(command, "push") == 0)
		{
			int num;
			scanf("%d", &num);
			Push(&q, num);
		}
		else if (strcmp(command, "front") == 0)
		{
			int front = Front(&q);
			printf("%d\n", front);
		}
		else if (strcmp(command, "back") == 0)
		{
			int back = Back(&q);
			printf("%d\n", back);
		}
		else if (strcmp(command, "pop") == 0)
		{
			int poppedData = Pop(&q);
			printf("%d\n", poppedData);
		}
		else if (strcmp(command, "size") == 0)
		{
			int size = Size(&q);
			printf("%d\n", size);
		}
		else if (strcmp(command, "empty") == 0)
		{
			bool isEmpty = Empty(&q);
			printf("%d\n", isEmpty);
		}
	}
	DestroyQueue(&q);
	return 0;
}