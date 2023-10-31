#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _NODE
{
	int _data;
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

	(*queue)->_head->_count = 0; (*queue)->_head->_data = 0; (*queue)->_head->_next = (*queue)->_rear;
	(*queue)->_rear->_count = 0; (*queue)->_rear->_data = 0; (*queue)->_rear->_prev = (*queue)->_head;
}

void Push(Queue** queue, int data, int count)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_count = count;
	newNode->_data = data;
	
	
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
		Pop(queue);
	free((*queue)->_head);
	free((*queue)->_rear);
	free((*queue));
}

int D(int data)
{
	return (2 * data) % 10000;
}

int S(int data)
{
	return (data - 1 + 10000) % 10000;
}

int L(int data)
{
	return (data % 1000) * 10 + data / 1000;
}

int R(int data)
{
	return (data % 10) * 1000 + (data / 10);
}



void Bfs(int start_num, int end_num)
{
	Queue* queue;
	CreateQueue(&queue);
	
	int visited[10001] = { 0, };

	Push(&queue, start_num, 0);
	visited[start_num] = 1;

	while (Empty(&queue) == false)
	{
		Node* poppedNode = Front(&queue);
		if (poppedNode->_data == end_num)
		{
			break;
		}
		
		if (visited[D(poppedNode->_data)] == 0)
		{
			visited[D(poppedNode->_data)] = visited[poppedNode->_data] + 1;
			Push(&queue, D(poppedNode->_data), poppedNode->_count + 1);
		}

		if (visited[S(poppedNode->_data)] == 0)
		{
			visited[S(poppedNode->_data)] = visited[poppedNode->_data] + 1;
			Push(&queue, S(poppedNode->_data), poppedNode->_count + 1);
		}

		if (visited[L(poppedNode->_data)] == 0)
		{
			visited[L(poppedNode->_data)] = visited[poppedNode->_data] + 1;
			Push(&queue, L(poppedNode->_data), poppedNode->_count + 1);
		}

		if (visited[R(poppedNode->_data)] == 0)
		{
			visited[R(poppedNode->_data)] = visited[poppedNode->_data] + 1;
			Push(&queue, R(poppedNode->_data), poppedNode->_count + 1);
		}
		Pop(&queue);
	}
	
	char cmd[10001] = { 0, };
	int cmd_index = 0;
	
	while (start_num != end_num)
	{
		short sequence = visited[end_num];
		if (visited[R(end_num)] == sequence - 1)
		{
			cmd[cmd_index++] = 'L';
			end_num = R(end_num);
		}
		else if (visited[L(end_num)] == sequence - 1)
		{
			cmd[cmd_index++] = 'R';
			end_num = L(end_num);
		}
		else if (visited[(end_num + 1) % 10000] == sequence - 1)
		{
			cmd[cmd_index++] = 'S';
			end_num = (end_num + 1) % 10000;
		}
		else
		{
			cmd[cmd_index++] = 'D';
			if (visited[end_num / 2] == sequence - 1)
				end_num = end_num / 2;
			else
				end_num = (10000 + end_num) / 2;
		}

	}

	for (int i = cmd_index - 1; i >= 0; --i)
	{
		printf("%c", cmd[i]);
	}
	printf("\n");
	DestroyQueue(&queue);
}

int main(void)
{
	int testcase = 0;
	scanf("%d", &testcase);
	
	for (int t = 0; t < testcase; ++t)
	{
		int start_num, end_num;
		scanf("%d%d", &start_num ,&end_num);
		Bfs(start_num, end_num);
	}

	

	return 0;
}