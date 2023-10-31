#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int map[101][101] = { 0, };
bool visited[101][101] = { 0, };

typedef struct _NODE
{
	int _y;
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

	(*queue)->_head->_next = (*queue)->_rear;
	(*queue)->_rear->_prev = (*queue)->_head;

	(*queue)->_head->_y = 0; (*queue)->_head->_x = 0; (*queue)->_head->_prev = NULL;
	(*queue)->_rear->_x = 0; (*queue)->_rear->_y = 0; (*queue)->_rear->_next = NULL;
}

void Push(Queue** queue, int y, int x, int c)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_y = y;
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

void PrintMap(int M, int N)
{
	for (int y = 0; y < M; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			printf("%d\t", map[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}


void SetMap(int M, int N)
{
	char* str = (char*)malloc(sizeof(char) * 101);
	for (int y = 0; y < M; ++y)
	{
		scanf("%s", str);
		int strLen = strlen(str);
		for (int x = 0; x < strLen; ++x)
		{
			map[y][x] = str[x] - '0';
		}
	}
	free(str);
}

int main(void)
{
	Queue* queue;
	CreateQueue(&queue);

	int M, N;
	scanf("%d%d", &M, &N);
	
	SetMap(M, N);
	
	visited[0][0] = true;
	Push(&queue, 0, 0, 1);

	int dirs[4][2] = {
		{+0, +1},
		{+1, +0},
		{+0, -1},
		{-1, +0}
	};
	
	while (Empty(&queue) == false)
	{
		Node* poppedNode = FrontNode(&queue);
		if (poppedNode->_y == M - 1 && poppedNode->_x == N - 1)
		{
			printf("%d\n", poppedNode->_c);
			break;
		}

		for (int dir_index = 0; dir_index < 4; ++dir_index)
		{
			int next_y = poppedNode->_y + dirs[dir_index][0];
			int next_x = poppedNode->_x + dirs[dir_index][1];

			if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)
				continue;
			if (visited[next_y][next_x] == true)
				continue;
			if (map[next_y][next_x] == 0)
				continue;
			visited[next_y][next_x] = true;
			Push(&queue, next_y, next_x, poppedNode->_c + 1);
		}
		Pop(&queue);
	}

	DestroyQueue(&queue);
	return 0;
}