#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>



typedef struct _NODE
{
	int _src;
	int _dest;
	int _weight;
} Node;

typedef struct _HEAP
{
	int _usedsize;
	int _capacity;
	Node* _nodes;
} Heap;

void CreateHeap(Heap** heap, int initSize)
{
	(*heap) = (Heap*)malloc(sizeof(Heap));
	(*heap)->_capacity = initSize;
	(*heap)->_usedsize = 0;
	(*heap)->_nodes = (Node*)malloc(sizeof(Node) * (*heap)->_capacity);
}

void DestroyHeap(Heap** heap)
{
	free((*heap)->_nodes);
	free((*heap));
}

int GetParentPosition(int index)
{
	return (index + 1) / 2;
}

int GetLeftChildPosition(int index)
{
	return (2 * index + 1);
}

void SwapNodes(Heap** heap, int index1, int index2)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memcpy(temp, &(*heap)->_nodes[index1], sizeof(Node));
	memcpy(&(*heap)->_nodes[index1], &(*heap)->_nodes[index2], sizeof(Node));
	memcpy(&(*heap)->_nodes[index2], temp, sizeof(Node));
	free(temp);
}

void Push(Heap** heap, int src, int dest, int weight)
{
	int currentPosition = (*heap)->_usedsize;
	int parentPosition = GetParentPosition(currentPosition);
	
	if ((*heap)->_capacity == (*heap)->_usedsize)
	{
		(*heap)->_capacity *= 2;
		(*heap)->_nodes = (Node*)realloc((*heap)->_nodes, sizeof(Node) * (*heap)->_capacity);
	}

	(*heap)->_nodes[currentPosition]._src = src;
	(*heap)->_nodes[currentPosition]._dest = dest;
	(*heap)->_nodes[currentPosition]._weight = weight;

	if (currentPosition > 0 && (*heap)->_nodes[currentPosition]._weight < (*heap)->_nodes[parentPosition]._weight)
	{
		SwapNodes(heap, currentPosition, parentPosition);
		currentPosition = parentPosition;
		parentPosition = GetParentPosition(currentPosition);
	}
	(*heap)->_usedsize++;
}

Node Top(Heap** heap)
{
	return (*heap)->_nodes[0];
}

void Pop(Heap** heap)
{
	int currentPosition = 0;
	memset(&(*heap)->_nodes[0], 0, sizeof(Node));
	
	(*heap)->_usedsize--;
	memcpy(&(*heap)->_nodes[currentPosition], &(*heap)->_nodes[(*heap)->_usedsize], sizeof(Node));

	int leftChildPosition = GetLeftChildPosition(currentPosition);
	int rightChildPosition = leftChildPosition + 1;

	while (1)
	{
		int selectedChildPosition = 0;
		if (leftChildPosition >= (*heap)->_usedsize)
			break;

		if (rightChildPosition >= (*heap)->_usedsize)
			selectedChildPosition = leftChildPosition;
		else
		{
			if ((*heap)->_nodes[leftChildPosition]._weight < (*heap)->_nodes[rightChildPosition]._weight)
				selectedChildPosition = leftChildPosition;
			else
				selectedChildPosition = rightChildPosition;
		}

		if ((*heap)->_nodes[selectedChildPosition]._weight < (*heap)->_nodes[currentPosition]._weight)
		{
			SwapNodes(heap, selectedChildPosition, currentPosition);
			currentPosition = selectedChildPosition;
		}
		else
		{
			break;
		}
		leftChildPosition = GetLeftChildPosition(currentPosition);
		rightChildPosition = leftChildPosition + 1;
	}

	if (((*heap)->_usedsize == (*heap)->_capacity / 2) && ((*heap)->_usedsize != 0))
	{
		(*heap)->_capacity /= 2;
		(*heap)->_nodes = (Node*)realloc((*heap)->_nodes, sizeof(Node) * (*heap)->_capacity);
	}
}

int adjacentMatrix[1001][1001] = { 0, };

int main(void)
{
	Heap* heap;
	// N: 도시의 갯수 (Vertex)
	// M: 버스의 갯수 (Edge)
	int N, M;
	scanf("%d%d", &N, &M);
	
	CreateHeap(&heap, N + 1);

	for (int i = 0; i < M; ++i)
	{
		int src, dest, weight;
		scanf("%d%d%d", &src, &dest, &weight);
		adjacentMatrix[src][dest] = weight;
	}
	
	int start_pos, target_pos;
	scanf("%d%d", &start_pos, &target_pos);

	
	// 더 작성하기

	DestroyHeap(&heap);
}