#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _COORD
{
	int _x;
	int _y;
} Coord;

Coord* coords[100000];
int coordsIndex = 0;
Coord* temp[100000];

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;
	
	while (leftIdx <= mid && rightIdx <= right)
	{
		if (coords[leftIdx]->_y < coords[rightIdx]->_y)
		{
			temp[tempIdx++] = coords[leftIdx++];
		}
		else if (coords[rightIdx]->_y < coords[leftIdx]->_y)
		{
			temp[tempIdx++] = coords[rightIdx++];
		}
		else
		{
			if (coords[leftIdx]->_x <= coords[rightIdx]->_x)
			{
				temp[tempIdx++] = coords[leftIdx++];
			}
			else
			{
				temp[tempIdx++] = coords[rightIdx++];
			}
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = coords[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = coords[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		coords[left + i] = temp[i];
	}
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (right + left) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		Coord* newCoord = (Coord*)malloc(sizeof(Coord));
		scanf("%d%d", &newCoord->_x, &newCoord->_y);
		coords[coordsIndex++] = newCoord;
	}
	MergeSort(0, N - 1);
	for (int i = 0; i < N; ++i)
	{
		printf("%d %d\n", coords[i]->_x, coords[i]->_y);
	}

	return 0;
}