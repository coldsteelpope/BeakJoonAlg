#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct _HEAP
{
	int _usedsize;
	int _capability;
	int* _nodes;
} Heap;

void CreateHeap(Heap** heap, int initSize)
{
	(*heap) = (Heap*)malloc(sizeof(Heap));
	(*heap)->_usedsize = 0;
	(*heap)->_capability = initSize;	
	(*heap)->_nodes = (int*)malloc(sizeof(int) * initSize);
}

void DestroyHeap(Heap** heap)
{
	free((*heap)->_nodes);
	free((*heap));
}

int GetParentNode(int index)
{
	return (index - 1) / 2;
}

int GetLeftChildNode(int index)
{
	return (2 * index) + 1;
}

void SwapNodes(Heap** heap, int index1, int index2)
{
	int temp = (*heap)->_nodes[index1];
	(*heap)->_nodes[index1] = (*heap)->_nodes[index2];
	(*heap)->_nodes[index2] = temp;
}

void Push(Heap** heap, int data)
{
	int currentPosition = (*heap)->_usedsize;
	int parentPosition = GetParentNode(currentPosition);

	if ((*heap)->_usedsize == (*heap)->_capability)
	{
		(*heap)->_capability *= 2;
		(*heap)->_nodes = (int*)realloc((*heap)->_nodes, sizeof(int) * (*heap)->_capability);
	}

	(*heap)->_nodes[currentPosition] = data;

	while (currentPosition > 0 && (*heap)->_nodes[currentPosition] < (*heap)->_nodes[parentPosition])
	{
		SwapNodes(heap, currentPosition, parentPosition);
		currentPosition = parentPosition;
		parentPosition = GetParentNode(currentPosition);
	}
	(*heap)->_usedsize++;
}

int Top(Heap** heap)
{
	return (*heap)->_nodes[0];
}

void Pop(Heap** heap)
{
	int currentPosition = 0;
	(*heap)->_nodes[currentPosition] = 0;
	
	(*heap)->_usedsize--;
	memcpy(&(*heap)->_nodes[currentPosition], &(*heap)->_nodes[(*heap)->_usedsize], sizeof(int));
	
	int leftPosition = GetLeftChildNode(currentPosition);
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
			if ((*heap)->_nodes[leftPosition] < (*heap)->_nodes[rightPosition])
				selectedPosition = leftPosition;
			else
				selectedPosition = rightPosition;
		}

		if ((*heap)->_nodes[selectedPosition] < (*heap)->_nodes[currentPosition])
		{
			SwapNodes(heap, selectedPosition, currentPosition);
			currentPosition = selectedPosition;
		}
		else
		{
			break;
		}
		
		leftPosition = GetLeftChildNode(currentPosition);
		rightPosition = leftPosition + 1;
	}
	
	if ((*heap)->_usedsize == (*heap)->_capability / 2 && (*heap)->_usedsize != 0)
	{
		(*heap)->_capability /= 2;
		(*heap)->_nodes = (int*)realloc((*heap)->_nodes, sizeof(int) * (*heap)->_capability);
	}
}

void PrintHeap(Heap** heap)
{
	printf("\n");
	for (int i = 0; i < (*heap)->_usedsize; ++i)
		printf("%d ", (*heap)->_nodes[i]);
	printf("\n");
}

typedef struct _NODE
{
	int _start;
	int _end;
} Node;

Node nodes[200001];
Node temp[200001];

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (nodes[leftIdx]._start < nodes[rightIdx]._start)
		{
			temp[tempIdx++] = nodes[leftIdx++];
		}
		else
		{
			temp[tempIdx++] = nodes[rightIdx++];
		}
	}

	if (mid < leftIdx)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = nodes[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = nodes[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		nodes[left + i] = temp[i];
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
		nodes[i]._start = start_time; nodes[i]._end = end_time;
	}

	MergeSort(0, N - 1);
	Push(&heap, nodes[0]._end);

	for (int i = 1; i < N; ++i)
	{
		if (Top(&heap) <= nodes[i]._start)
		{
			Pop(&heap);
			Push(&heap, nodes[i]._end);
		}
		else
		{
			Push(&heap, nodes[i]._end);
		}
	}

	printf("%d\n", heap->_usedsize);
	DestroyHeap(&heap);
}