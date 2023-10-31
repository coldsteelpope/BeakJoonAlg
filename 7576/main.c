#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	int _y;
	int _x;
	int _days;
	struct _NODE* _next;
	struct _NODE* _prev;
} Node;

typedef struct _QUEUE
{
	int _count;
	Node* _head;
	Node* _rear;
} Queue;

int box[1000][1000] = { 0, };
bool discovered[1000][1000] = { 0, };

void CreateQueue(Queue** queue)
{
	(*queue) = (Queue*)malloc(sizeof(Queue));
	(*queue)->_count = 0;

	(*queue)->_head = (Node*)malloc(sizeof(Node));
	(*queue)->_rear = (Node*)malloc(sizeof(Node));
	
	(*queue)->_head->_next = (*queue)->_rear;
	(*queue)->_rear->_prev = (*queue)->_head;

	(*queue)->_head->_x = -1; (*queue)->_head->_y = -1; (*queue)->_head->_prev = NULL;
	(*queue)->_rear->_x = -1; (*queue)->_rear->_y = -1; (*queue)->_rear->_next = NULL;
}

void Push(Queue** queue, int y, int x, int days)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_y = y;
	newNode->_x = x;
	newNode->_days = days;
	
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
		Pop(queue);
	free((*queue)->_head);
	free((*queue)->_rear);
	free((*queue));
}

void PrintBox(int M, int N)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			printf("%d ", box[y][x]);
		}
		printf("\n");
	}
}

int main(void)
{
	Queue* queue;
	CreateQueue(&queue);
	int M, N; // m: 가로, n: 세로
	scanf("%d%d", &M, &N);

	int num_crudes = 0;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			scanf("%d", &box[y][x]);
			if (box[y][x] == 1)
			{
				discovered[y][x] = true;
				Push(&queue, y, x, 0);
			}
			else if (box[y][x] == 0)
			{
				num_crudes++;
			}
		}
	}

	int max_days = -1;
	int t_num_crudes = 0;
	while (Empty(&queue) == false)
	{
		Node* poppedNode = FrontNode(&queue);
	
		if (box[poppedNode->_y][poppedNode->_x] == 0)
			++t_num_crudes;

		int dirs[4][2] = {
			{+0, +1},
			{+1, +0},
			{+0, -1},
			{-1, +0}
		};

		for (int dirs_index = 0; dirs_index < 4; dirs_index++)
		{
			int next_y = poppedNode->_y + dirs[dirs_index][0];
			int next_x = poppedNode->_x + dirs[dirs_index][1];
			
			if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
				continue;
			if (box[next_y][next_x] == -1)
				continue;
			if (discovered[next_y][next_x] == true)
				continue;
			discovered[next_y][next_x] = true;
			Push(&queue, next_y, next_x, poppedNode->_days + 1);
			max_days = (poppedNode->_days + 1 > max_days) ? poppedNode->_days + 1 : max_days;
		}
		Pop(&queue);
	}
	
	int answer = 0;
	if (t_num_crudes != num_crudes)
		answer = -1;
	else if (t_num_crudes == 0 && num_crudes == 0)
		answer = 0;
	else
		answer = max_days;
	printf("%d\n", answer);
	return 0;
}