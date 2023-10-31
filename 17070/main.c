#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	int _y;
	int _x;
	int _type;
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
}

void Push(Queue** queue, int y, int x, int type)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_y = y;
	newNode->_x = x;
	newNode->_type = type;
	
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

void Destroy(Queue** queue)
{
	while (Empty(queue) == false)
	{
		Pop(queue);
	}
	free((*queue)->_head);
	free((*queue)->_rear);
	free((*queue));
}

int map[17][17] = { 0, };
int dp[17][17] = { 0, };

void PrintMap(int N)
{
	printf("\n");
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			printf("%d\t", map[i][j]);
		printf("\n");
	}
	printf("\n");
}

void PrintDP(int N)
{
	printf("\n");
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			printf("%d\t", dp[i][j]);
		printf("\n");
	}
	printf("\n");
}

void SetMap(int N)
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			scanf("%d", &map[i][j]);
}

int main(void)
{
	Queue* queue;
	CreateQueue(&queue);
	
	int N;
	scanf("%d", &N);
	
	// type1 => 가로
	// type2 => 세로
	// type3 => 대각선
	SetMap(N);
	Push(&queue, 1, 2, 1);

	while (Empty(&queue) == false)
	{
		Node* hereNode = Front(&queue);
		++dp[hereNode->_y][hereNode->_x];

		if (hereNode->_type == 1)
		{
			int dirs[2][3] = {
				{+0, +1, 1},
				{+1, +1, 3}
			};

			for (int dir_index = 0; dir_index < 2; ++dir_index)
			{
				int next_y = hereNode->_y + dirs[dir_index][0];
				int next_x = hereNode->_x + dirs[dir_index][1];
				int next_pipe_type = dirs[dir_index][2];
				
				if (next_y < 1 || next_x < 1 || next_y > N || next_x > N)
					continue;

				if (map[next_y][next_x] == 1)
					continue;

				if (next_pipe_type == 3)
				{
					if (map[next_y - 1][next_x] == 1)
						continue;
					if (map[next_y][next_x - 1] == 1)
						continue;
				}

				Push(&queue, next_y, next_x, next_pipe_type);
			}
		}
		else if (hereNode->_type == 2)
		{
			int dirs[2][3] = {
				{ +1, +0, 2 },
				{ +1, +1, 3 }
			};

			for (int dir_index = 0; dir_index < 2; ++dir_index)
			{
				int next_y = hereNode->_y + dirs[dir_index][0];
				int next_x = hereNode->_x + dirs[dir_index][1];
				int next_pipe_type = dirs[dir_index][2];

				if (next_y < 1 || next_x < 1 || next_y > N || next_x > N)
					continue;

				if (map[next_y][next_x] == 1)
					continue;

				if (next_pipe_type == 3)
				{
					if (map[next_y - 1][next_x] == 1)
						continue;
					if (map[next_y][next_x - 1] == 1)
						continue;
				}

				Push(&queue, next_y, next_x, next_pipe_type);
			}
		}
		else if (hereNode->_type == 3)
		{
			int dirs[3][3] = {
				{ +0, +1, 1 },
				{ +1, +0, 2 },
				{ +1, +1, 3 }
			};

			for (int dir_index = 0; dir_index < 3; ++dir_index)
			{
				int next_y = hereNode->_y + dirs[dir_index][0];
				int next_x = hereNode->_x + dirs[dir_index][1];
				int next_pipe_type = dirs[dir_index][2];

				if (next_y < 1 || next_x < 1 || next_y > N || next_x > N)
					continue;

				if (map[next_y][next_x] == 1)
					continue;

				if (next_pipe_type == 3)
				{
					if (map[next_y - 1][next_x] == 1)
						continue;
					if (map[next_y][next_x - 1] == 1)
						continue;
				}
				Push(&queue, next_y, next_x, next_pipe_type);
			}
		}
		Pop(&queue);
	}
	printf("%d", dp[N][N]);
	Destroy(&queue);
}