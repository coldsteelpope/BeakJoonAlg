#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct _NODE
{
	int _data;
	bool _find;
	struct _NODE* _next;
	struct _NODE* _prev;
} Node;

typedef struct _QUEUE
{
	int _count;
	Node* _head;
	Node* _rear;
} Queue;

typedef struct _HEAP
{
	int _capability;
	int _usedsize;
	Node* _nodes;
} Heap;

void CreateHeap(Heap** h, int init)
{
	(*h) = (Heap*)malloc(sizeof(Heap));
	(*h)->_usedsize = 0;
	(*h)->_capability = init;
	(*h)->_nodes = (Node*)malloc(sizeof(Node) * (*h)->_capability);
}



int GetParent(int index)
{
	return (index - 1) / 2;
}

int GetLeft(int index)
{
	return 2 * index + 1;
}

void SwapHeapNodes(Heap** h, int index1, int index2)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memcpy(temp, &(*h)->_nodes[index1], sizeof(Node));
	memcpy(&(*h)->_nodes[index1], &(*h)->_nodes[index2], sizeof(Node));
	memcpy(&(*h)->_nodes[index2], temp, sizeof(Node));
	free(temp);
}

Node GetHeapRoot(Heap** h)
{
	return (*h)->_nodes[0];
}

void PushHeap(Heap** h, int data, bool find)
{
	int currentPosition = (*h)->_usedsize;
	int parentPosition = GetParent(currentPosition);
	
	if ((*h)->_capability == (*h)->_usedsize)
	{
		(*h)->_capability *= 2;
		(*h)->_nodes = (Node*)realloc((*h)->_nodes, sizeof(Node) * (*h)->_capability);
	}

	(*h)->_nodes[currentPosition]._data = data;
	(*h)->_nodes[currentPosition]._find = find;

	while (currentPosition > 0 && (*h)->_nodes[currentPosition]._data > (*h)->_nodes[parentPosition]._data)
	{
		SwapHeapNodes(h, currentPosition, parentPosition);
		currentPosition = parentPosition;
		parentPosition = GetParent(currentPosition);
	}
	(*h)->_usedsize++;
}

void PopHeap(Heap** h)
{
	int currentPosition = 0;
	memset(&(*h)->_nodes[0], 0, sizeof(Node));
	
	(*h)->_usedsize--;
	SwapHeapNodes(h, 0, (*h)->_usedsize);

	int leftPosition = GetLeft(currentPosition);
	int rightPosition = leftPosition + 1;
	while (1)
	{
		int selectedPosition = 0;

		if (leftPosition >= (*h)->_usedsize)
		{
			break;
		}

		if (rightPosition >= (*h)->_usedsize)
		{
			selectedPosition = leftPosition;
		}
		else
		{
			if ((*h)->_nodes[leftPosition]._data <= (*h)->_nodes[rightPosition]._data)
				selectedPosition = rightPosition;
			else
				selectedPosition = leftPosition;
		}

		if ((*h)->_nodes[currentPosition]._data <= (*h)->_nodes[selectedPosition]._data)
		{
			SwapHeapNodes(h, currentPosition, selectedPosition);
			currentPosition = selectedPosition;
		}
		else
		{
			break;
		}
		
		leftPosition = GetLeft(currentPosition);
		rightPosition = leftPosition + 1;
	}

	if ((*h)->_usedsize < ((*h)->_capability / 2))
	{
		(*h)->_capability = (*h)->_capability / 2;
		(*h)->_nodes = (Node*)realloc((*h)->_nodes, sizeof(Node) * (*h)->_capability);
	}
}

void DestroyHeap(Heap** h)
{
	free((*h)->_nodes);
	free((*h));
}

void CreateQueue(Queue** q)
{
	(*q) = (Queue*)malloc(sizeof(Queue));
	(*q)->_count = 0;

	(*q)->_head = (Node*)malloc(sizeof(Node));
	(*q)->_rear = (Node*)malloc(sizeof(Node));
	
	(*q)->_head->_next = (*q)->_rear;
	(*q)->_rear->_prev = (*q)->_head;
	
	(*q)->_head->_data = 0; (*q)->_head->_find = false;
	(*q)->_rear->_data = 0; (*q)->_rear->_find = false;
}

void PushQueue(Queue** q, int data, bool find)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->_data = data;
	newNode->_find = find;
	
	(*q)->_rear->_prev->_next = newNode;
	newNode->_prev = (*q)->_rear->_prev;
	newNode->_next = (*q)->_rear;
	(*q)->_rear->_prev = newNode;

	(*q)->_count++;
}

Node* FrontQueue(Queue** q)
{
	return (*q)->_head->_next;
}

void PopQueue(Queue** q)
{
	Node* poppedNode = FrontQueue(q);
	(*q)->_head->_next = poppedNode->_next;
	poppedNode->_next->_prev = (*q)->_head;
	(*q)->_count--;
	free(poppedNode);
}

bool EmptyQueue(Queue** q)
{
	return (*q)->_count == 0;
}

void DestroyQueue(Queue** q)
{
	while (EmptyQueue(q) == false)
	{
		PopQueue(q);
	}
	free((*q)->_head);
	free((*q)->_rear);
	free((*q));
}

int main(void)
{
	Queue* q;
	Heap* h;

	int testCase = 0;
	scanf("%d", &testCase);
	
	for (int tc = 0; tc < testCase; ++tc)
	{
		int N, M;
		scanf("%d%d", &N, &M);

		CreateQueue(&q);
		CreateHeap(&h, 3);

		for (int doc_num = 0; doc_num < N; ++doc_num)
		{
			int pushed_data = 0;
			bool pushed_find = (M == doc_num);
			scanf("%d", &pushed_data);
			PushQueue(&q, pushed_data, pushed_find);
			PushHeap(&h, pushed_data, pushed_find);
		}

		int try_num = 0;
		while (EmptyQueue(&q) == false)
		{
			Node* frontNode = FrontQueue(&q);
			int maxData = GetHeapRoot(&h)._data;

			if (frontNode->_data < maxData)
			{
				PushQueue(&q, frontNode->_data, frontNode->_find);
				PopQueue(&q);
			}
			else
			{
				if (frontNode->_find)
				{
					++try_num;
					break;
				}
				else
				{
					PopQueue(&q);
					PopHeap(&h);
					++try_num;
				}
			}
		}
		printf("%d\n", try_num);

		DestroyHeap(&h);
		DestroyQueue(&q);
	}

	return 0;
}