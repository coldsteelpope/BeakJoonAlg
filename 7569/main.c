#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _TOMATO
{
	int _x;
	int _y;
	int _z;
	int _days;
	struct _TOMATO* _next;
	struct _TOMATO* _prev;
} Tomato;

typedef struct _QUEUE
{
	int _count;
	Tomato* _head;
	Tomato* _rear;
} Queue;

void CreateQueue(Queue** queue)
{
	(*queue) = (Queue*)malloc(sizeof(Queue));
	(*queue)->_count = 0;
	(*queue)->_head = (Tomato*)malloc(sizeof(Tomato));
	(*queue)->_rear = (Tomato*)malloc(sizeof(Tomato));
	(*queue)->_head->_next = (*queue)->_rear;
	(*queue)->_rear->_prev = (*queue)->_head;
}

void Push(Queue** queue, int z, int y, int x, int days)
{
	Tomato* newTomato = (Tomato*)malloc(sizeof(Tomato));
	newTomato->_x = x; newTomato->_y = y; newTomato->_z = z;
	newTomato->_days = days;
	
	(*queue)->_rear->_prev->_next = newTomato;
	newTomato->_prev = (*queue)->_rear->_prev;

	newTomato->_next = (*queue)->_rear;
	(*queue)->_rear->_prev = newTomato;

	(*queue)->_count++;
}

Tomato* Front(Queue** queue)
{
	return (*queue)->_head->_next;
}

void Pop(Queue** queue)
{
	Tomato* poppedTomato = Front(queue);
	(*queue)->_head->_next = poppedTomato->_next;
	poppedTomato->_next->_prev = (*queue)->_head;
	free(poppedTomato);
	(*queue)->_count--;
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

int boxes[100][100][100] = { 0, };
bool visited[100][100][100] = { 0, };

void PrintBoxes(int H, int N, int M)
{
	for (int z = 0; z < H; ++z)
	{
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < M; ++x)
			{
				printf("%d\t", boxes[z][y][x]);
			}
			printf("\n");
		}
		printf("\n");
	}

}


int main(void)
{
	Queue* queue;
	CreateQueue(&queue);
	int M, N, H;
	scanf("%d%d%d", &M, &N, &H);

	int total_zeros_num = 0;

	for (int z = 0; z < H; ++z)
	{
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < M; ++x)
			{
				scanf("%d", &boxes[z][y][x]);
				if (boxes[z][y][x] == 1)
				{
					Push(&queue, z, y, x, 0);
					visited[z][y][x] = true;
				}
				else if (boxes[z][y][x] == 0)
				{
					++total_zeros_num;
				}
			}
		}
	}
	
	int dirs[6][3] = {
		{+1, +0, +0},
		{-1, +0, +0},
		{+0, +1, +0},
		{+0, -1, +0},
		{+0, +0, +1},
		{+0, +0, -1}
	};
	
	int min_days = 0;
	while (Empty(&queue) == false)
	{
		Tomato* poppedTomato = Front(&queue);
		for (int dirs_index = 0; dirs_index < 6; ++dirs_index)
		{
			int next_z = poppedTomato->_z + dirs[dirs_index][0];
			int next_y = poppedTomato->_y + dirs[dirs_index][1];
			int next_x = poppedTomato->_x + dirs[dirs_index][2];
			
			if (next_z < 0 || next_y < 0 || next_x < 0 || next_z >= H || next_y >= N || next_x >= M)
				continue;
			if (visited[next_z][next_y][next_x] == true)
				continue;
			if (boxes[next_z][next_y][next_x] == 1 || boxes[next_z][next_y][next_x] == -1)
				continue;
			
			visited[next_z][next_y][next_x] = true;
			--total_zeros_num;
			Push(&queue, next_z, next_y, next_x, poppedTomato->_days + 1);
		}

		min_days = (poppedTomato->_days > min_days) ? poppedTomato->_days : min_days;
		Pop(&queue);
	}

	
	if (total_zeros_num != 0)
		printf("%d\n", -1);
	else
		printf("%d\n", min_days);

	DestroyQueue(&queue);
	return 0;
}
