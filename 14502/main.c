// 내가 재귀함수에 대한 이해가 많이 부족한 것 같다.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 8 + 1

typedef struct _NODE
{
	int _y;
	int _x;
	struct _NODE* _next;
	struct _NODE* _prev;
} Node;

typedef struct _QUEUE
{
	int _count;
	Node* _head;
	Node* _rear;
} Queue;


int map[MAX][MAX];
int copied_map[MAX][MAX];
int temp[MAX][MAX];

void CreateQueue(Queue** queue)
{
	(*queue) = (Queue*)malloc(sizeof(Queue));
	(*queue)->_count = 0;
	(*queue)->_head = (Node*)malloc(sizeof(Node));
	(*queue)->_rear = (Node*)malloc(sizeof(Node));

	(*queue)->_head->_x = 0; (*queue)->_head->_y = 0;
	(*queue)->_rear->_x = 0; (*queue)->_rear->_y = 0;

	(*queue)->_head->_next = (*queue)->_rear;
	(*queue)->_rear->_prev = (*queue)->_head;
}

void Push(Queue** queue, int y, int x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_y = y;
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
		Pop(queue);
	free((*queue)->_head);
	free((*queue)->_rear);
	free((*queue));
}

int bfs(int height, int width)
{
	bool visited[MAX][MAX] = { 0, };
	int temp[MAX][MAX] = { 0, };
	
	Queue* queue;
	CreateQueue(&queue);
	
	// Set Temp
	for (int y = 1; y <= height; ++y)
		for (int x = 1; x <= width; ++x)
			temp[y][x] = copied_map[y][x];

	// Push Virus Node
	for (int y = 1; y <= height; ++y)
	{
		for (int x = 1; x <= width; ++x)
		{
			if (copied_map[y][x] == 2)
			{
				Push(&queue, y, x);
				visited[y][x] = true;
			}
		}
	}

	int dirs[4][2] = {
		{ +0, +1 },
		{ -1, +0 },
		{ +0, -1 },
		{ +1, +0 }
	};

	while (Empty(&queue) == false)
	{
		Node* front = Front(&queue);
		
		for (int dirs_index = 0; dirs_index < 4; ++dirs_index)
		{
			int next_y = front->_y + dirs[dirs_index][0];
			int next_x = front->_x + dirs[dirs_index][1];

			if (next_x < 1 || next_y < 1 || next_x > width || next_y > height)
				continue;
			if (visited[next_y][next_x] == true)
				continue;
			if (temp[next_y][next_x] == 1)
				continue;
			
			temp[next_y][next_x] = 2;
			visited[next_y][next_x] = true;
			Push(&queue, next_y, next_x);
		}
		Pop(&queue);
	}

	int zero_count = 0;
	for (int y = 1; y <= height; ++y)
	{
		for (int x = 1; x <= width; ++x)
		{
			if (temp[y][x] == 0)
				++zero_count;
		}
	}
	DestroyQueue(&queue);
	return zero_count;
}

void CreateWall(int count, int height, int width, int* max_area)
{
	if (count == 3)
	{
		int temp = bfs(height, width);
		(*max_area) = (temp > (*max_area)) ? temp : (*max_area);
		return;
	}
	else
	{
		for (int y = 1; y <= height; ++y)
		{
			for (int x = 1; x <= width; ++x)
			{
				if (copied_map[y][x] == 0)
				{
					copied_map[y][x] = 1;
					CreateWall(count + 1, height, width, max_area);
					copied_map[y][x] = 0;
				}
			}
		}
	}
}

int main(void)
{
	// N: height, M: width
	int N, M;
	scanf("%d%d", &N, &M);
	
	// Set Map
	for (int y = 1; y <= N; ++y)
		for (int x = 1; x <= M; ++x)
			scanf("%d", &map[y][x]);

	// Copy Map
	for (int y = 1; y <= N; ++y)
		for (int x = 1; x <= M; ++x)
			copied_map[y][x] = map[y][x];

	int max_area = 0;
	CreateWall(0, N, M, &max_area);

	printf("%d", max_area);
	return 0;
}