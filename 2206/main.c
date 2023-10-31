#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int map[1001][1001] = { 0, };
int distance[2][1001][1001] = {0,};

// Dfs로 푸는 방법 생각하기
typedef struct _NODE
{
	int _y;
	int _x;
	int _broken;
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
	(*queue)->_head = (Node*)malloc(sizeof(Node));
	(*queue)->_rear = (Node*)malloc(sizeof(Node));
	(*queue)->_count = 0;
	(*queue)->_head->_next = (*queue)->_rear;
	(*queue)->_rear->_prev = (*queue)->_head;
}

void Push(Queue** queue, int y, int x, int count, int broken)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_y = y; newNode->_x = x; newNode->_broken = broken; newNode->_count = count;
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

void SetMap(int N, int M)
{
	for (int i = 1; i <= N; ++i)
	{
		char* str = (char*)malloc(sizeof(char) * (M + 1));
		scanf("%s", str);
		int strLen = strlen(str);
		for (int j = 0; j < strLen; ++j)
			map[i][j + 1] = str[j] - '0';
	}
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	SetMap(N, M);
	
	Queue* queue;
	CreateQueue(&queue);
	Push(&queue, 1, 1, 0, 0);
	distance[0][1][1] = 1;
	
	int dirs[4][2] = {
		{+0, +1},
		{+1, +0},
		{+0, -1},
		{-1, +0}
	};

	while (Empty(&queue) == false)
	{
		Node* frontNode = Front(&queue);

		if (frontNode->_y == N && frontNode->_x == M)
		{
			break;
		}

		for (int dirs_index = 0; dirs_index < 4; dirs_index++)
		{
			int next_y = frontNode->_y + dirs[dirs_index][0];
			int next_x = frontNode->_x + dirs[dirs_index][1];

			if (next_y < 1 || next_x < 1 || next_y > N || next_x > M)
				continue;

			if (distance[frontNode->_broken][next_y][next_x])
				continue;

			if (map[next_y][next_x] == 0)
			{
				distance[frontNode->_broken][next_y][next_x] = distance[frontNode->_broken][frontNode->_y][frontNode->_x] + 1;
				Push(&queue, next_y, next_x, frontNode->_count + 1, frontNode->_broken);
			}
			else if (map[next_y][next_x] == 1 && frontNode->_broken == 0)
			{
				distance[1][next_y][next_x] = distance[frontNode->_broken][frontNode->_y][frontNode->_x] + 1;
				Push(&queue, next_y, next_x, frontNode->_count + 1, 1);
			}
			
		}
		Pop(&queue);
	}


	
	int len_one = distance[0][N][M];
	int len_two = distance[1][N][M];

	if (len_one == 0 && len_two == 0)
		printf("%d", -1);
	else
		printf("%d", (len_one == 0) ? len_two : len_one);

	DestroyQueue(&queue);
	return 0;
}