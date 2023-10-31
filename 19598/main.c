#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct _NODE
{
	int _start_time;
	int _end_time;
} Node;

typedef struct _HEAP
{
	int _capability;
	int _usedsize;
	Node* _nodes;
} Heap;

void CreateHeap(Heap** heap, int initSize)
{
	(*heap) = (Heap*)malloc(sizeof(Heap));
	(*heap)->_capability = initSize;
	(*heap)->_usedsize = 0;
	(*heap)->_nodes = (Node*)malloc(sizeof(Node) * (*heap)->_capability);
}

void DestroyHeap(Heap** heap)
{
	free((*heap)->_nodes);
	free((*heap));
}

int GetParentPosition(int index)
{
	return (index - 1) / 2;
}

int GetLeftChildPosition(int index)
{
	return (2 * index) + 1;
}

void SwapNodes(Heap** heap, int index1, int index2)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memcpy(temp, &(*heap)->_nodes[index1], sizeof(Node));
	memcpy(&(*heap)->_nodes[index1], &(*heap)->_nodes[index2], sizeof(Node));
	memcpy(&(*heap)->_nodes[index2], temp, sizeof(Node));
}

void Push(Heap** heap, int start_time, int end_time)
{
	int currentPosition = (*heap)->_usedsize;
	int parentPosition = GetParentPosition(currentPosition);

	if ((*heap)->_capability == (*heap)->_usedsize)
	{
		(*heap)->_capability *= 2;
		(*heap)->_nodes = (Node*)realloc((*heap)->_nodes, sizeof(Node) * (*heap)->_capability);
	}

	(*heap)->_nodes[currentPosition]._start_time = start_time;
	(*heap)->_nodes[currentPosition]._end_time = end_time;
	
	while (currentPosition > 0 && (*heap)->_nodes[currentPosition]._end_time < (*heap)->_nodes[parentPosition]._end_time)
	{
		SwapNodes(heap, currentPosition, parentPosition);
		currentPosition = parentPosition;
		parentPosition = GetParentPosition(currentPosition);
	}
	(*heap)->_usedsize++;
}

void Pop(Heap** heap)
{
	int currentPosition = 0;
	memset(&(*heap)->_nodes[currentPosition], 0, sizeof(Node));

	(*heap)->_usedsize--;
	SwapNodes(heap, 0, (*heap)->_usedsize);

	int leftPosition = GetLeftChildPosition(currentPosition);
	int rightPosition = leftPosition + 1;

	while (1)
	{
		int selectedPosition = 0;
		if (leftPosition >= (*heap)->_usedsize)
			break;
		if (rightPosition >= (*heap)->_usedsize)
			selectedPosition = leftPosition;
		else
		{
			if ((*heap)->_nodes[leftPosition]._end_time < (*heap)->_nodes[rightPosition]._end_time)
				selectedPosition = leftPosition;
			else
				selectedPosition = rightPosition;
		}

		if ((*heap)->_nodes[currentPosition]._end_time > (*heap)->_nodes[selectedPosition]._end_time)
		{
			SwapNodes(heap, currentPosition, selectedPosition);
			currentPosition = selectedPosition;
		}
		else
		{
			break;
		}

		leftPosition = GetLeftChildPosition(currentPosition);
		rightPosition = leftPosition + 1;
	}

	if ((*heap)->_usedsize == (*heap)->_capability / 2 && (*heap)->_usedsize != 0)
	{
		(*heap)->_capability /= 2;
		(*heap)->_nodes = (Node*)realloc((*heap)->_nodes, sizeof(Node) * (*heap)->_capability);
	}
}

Node Top(Heap** heap)
{
	return (*heap)->_nodes[0];
}

void PrintHeap(Heap** heap)
{
	printf("\n");
	for (int i = 0; i < (*heap)->_usedsize; ++i)
	{
		printf("(start_time: %d, end_time: %d) ", (*heap)->_nodes[i]._start_time, (*heap)->_nodes[i]._end_time);
	}

	printf("\n");
}

Node schedulers[100001];
Node temp[100001];

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (schedulers[leftIdx]._start_time < schedulers[rightIdx]._start_time)
		{
			temp[tempIdx++] = schedulers[leftIdx++];
		}
		else if (schedulers[leftIdx]._start_time > schedulers[rightIdx]._start_time)
		{
			temp[tempIdx++] = schedulers[rightIdx++];
		}
		else
		{
			if (schedulers[leftIdx]._end_time < schedulers[rightIdx]._end_time)
			{
				temp[tempIdx++] = schedulers[leftIdx++];
			}
			else
			{
				temp[tempIdx++] = schedulers[rightIdx++];
			}
		}
	}

	if (mid < leftIdx)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = schedulers[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = schedulers[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		schedulers[left + i] = temp[i];
	}
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

int main(void)
{
	Heap* heap;
	int N;
	scanf("%d", &N);
	CreateHeap(&heap, N);
	
	for (int i = 0; i < N; ++i)
	{
		int start_time, end_time;
		scanf("%d%d", &start_time, &end_time);
		schedulers[i]._start_time = start_time; schedulers[i]._end_time = end_time;
	}

	MergeSort(0, N - 1);
	Push(&heap, schedulers[0]._start_time, schedulers[0]._end_time);

	for (int i = 1; i < N; ++i)
	{
		Node TopNode = Top(&heap);
		if (TopNode._end_time <= schedulers[i]._start_time)
		{
			Pop(&heap);
			Push(&heap, schedulers[i]._start_time, schedulers[i]._end_time);
		}
		else
		{
			Push(&heap, schedulers[i]._start_time, schedulers[i]._end_time);
		}
	}

	printf("%d\n", heap->_usedsize);
	return 0;
}