#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	int _x;
	int _y;
} Node;

Node nodes[100001] = { 0, };
Node temp[100001] = { 0, };

void PrintNodes(int N);

void MergeResult(int left, int right, int mid)
{
	int leftPointer = left;
	int rightPointer = mid + 1;
	int tempPointer = 0;
	
	while (leftPointer <= mid && rightPointer <= right)
	{
		if (nodes[leftPointer]._y < nodes[rightPointer]._y)
		{
			temp[tempPointer]._x = nodes[leftPointer]._x;
			temp[tempPointer]._y = nodes[leftPointer]._y;
			++tempPointer;
			++leftPointer;
		}
		else if (nodes[leftPointer]._y > nodes[rightPointer]._y)
		{
			temp[tempPointer]._x = nodes[rightPointer]._x;
			temp[tempPointer]._y = nodes[rightPointer]._y;
			++tempPointer;
			++rightPointer;
		}
		else
		{
			if (nodes[leftPointer]._x <= nodes[rightPointer]._x)
			{
				temp[tempPointer]._x = nodes[leftPointer]._x;
				temp[tempPointer]._y = nodes[leftPointer]._y;
				++tempPointer;
				++leftPointer;
			}
			else
			{
				temp[tempPointer]._x = nodes[rightPointer]._x;
				temp[tempPointer]._y = nodes[rightPointer]._y;
				++tempPointer;
				++rightPointer;
			}
		}
	}

	if(mid < leftPointer)
	{
		while (rightPointer <= right)
		{
			temp[tempPointer]._x = nodes[rightPointer]._x;
			temp[tempPointer]._y = nodes[rightPointer]._y;
			++tempPointer;
			++rightPointer;
		}
	}
	else
	{
		while (leftPointer <= mid)
		{
			temp[tempPointer]._x = nodes[leftPointer]._x;
			temp[tempPointer]._y = nodes[leftPointer]._y;
			++tempPointer;
			++leftPointer;
		}
	}
	for (int i = 0; i < tempPointer; ++i)
	{
		nodes[left + i]._x = temp[i]._x;
		nodes[left + i]._y = temp[i]._y;
	}
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, right, mid);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; ++n)
	{
		scanf("%d%d", &nodes[n]._x, &nodes[n]._y);
	}
	MergeSort(0, N - 1);
	PrintNodes(N);
	return 0;
}

void PrintNodes(int N)
{
	for (int i = 0; i < N; ++i)
	{
		printf("%d %d\n", nodes[i]._x, nodes[i]._y);
	}
}