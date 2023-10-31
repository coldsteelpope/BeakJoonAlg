#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	long long _data;
	int _compressed;
	int _pos;
} Node;

Node* nums[1000000] = { 0, };
Node* temp[1000000] = { 0, };

void MergeResultByPos(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (nums[leftIdx]->_pos < nums[rightIdx]->_pos)
			temp[tempIdx++] = nums[leftIdx++];
		else
			temp[tempIdx++] = nums[rightIdx++];
	}

	if (leftIdx > mid)
		while (rightIdx <= right)
			temp[tempIdx++] = nums[rightIdx++];
	else
		while (leftIdx <= mid)
			temp[tempIdx++] = nums[leftIdx++];

	for (int i = 0; i < tempIdx; ++i)
		nums[left + i] = temp[i];
}

void MergeSortByPos(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSortByPos(left, mid);
	MergeSortByPos(mid + 1, right);
	MergeResultByPos(left, mid, right);
}

void MergeResultByData(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;
	
	while (leftIdx <= mid && rightIdx <= right)
	{
		if (nums[leftIdx]->_data < nums[rightIdx]->_data)
			temp[tempIdx++] = nums[leftIdx++];
		else
			temp[tempIdx++] = nums[rightIdx++];
	}
	
	if (leftIdx > mid)
		while (rightIdx <= right)
			temp[tempIdx++] = nums[rightIdx++];
	else
		while (leftIdx <= mid)
			temp[tempIdx++] = nums[leftIdx++];

	for (int i = 0; i < tempIdx; ++i)
		nums[left + i] = temp[i];
}

void MergeSortByData(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSortByData(left, mid);
	MergeSortByData(mid + 1, right);
	MergeResultByData(left, mid, right);
}

//int BinarySearchLowerBound(int left, int right, int val)
//{
//	while (left < right)
//	{
//		int mid = (right + left) / 2;
//		if (nums[mid]->_data >= val)
//		{
//			right = mid;
//		}
//		else
//		{
//			left = mid + 1;
//		}
//	}
//	return right;
//}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; ++i)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		scanf("%lld", &newNode->_data);
		newNode->_compressed = 0;
		newNode->_pos = i;
		nums[i] = newNode;
	}

	MergeSortByData(0, N - 1);
	
	long long ex_data = 1000000001;
	int ex_compressed = -1;
	for (int i = 0; i < N; ++i)
	{
		if (nums[i]->_data != ex_data)
		{
			nums[i]->_compressed = ++ex_compressed;
			ex_data = nums[i]->_data;
		}
		else
		{
			nums[i]->_compressed = ex_compressed;
		}
	}
	
	MergeSortByPos(0, N - 1);

	for (int i = 0; i < N; ++i)
		printf("%d ", nums[i]->_compressed);
	
	for (int i = 0; i < N; ++i)
		free(nums[i]);
}