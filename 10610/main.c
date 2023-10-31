#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char number[100001] = { 0, };
char temp[100001] = { 0, };

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (number[leftIdx] > number[rightIdx])
			temp[tempIdx++] = number[leftIdx++];
		else
			temp[tempIdx++] = number[rightIdx++];
	}

	if (mid < leftIdx)
	{
		while (rightIdx <= right)
			temp[tempIdx++] = number[rightIdx++];
	}
	else
	{
		while (leftIdx <= mid)
			temp[tempIdx++] = number[leftIdx++];
	}

	for (int i = 0; i < tempIdx; ++i)
		number[left + i] = temp[i];
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
	scanf("%s", number);
	
	int tot = 0;
	bool isZeroExisted = false;

	int numberLen = strlen(number);
	for (int i = 0; i < numberLen; ++i)
	{
		if (number[i] == '0') 
			isZeroExisted = true;
		
		tot += number[i] - '0';
	}
		
	if (tot % 3 != 0 || isZeroExisted == false)
	{
		printf("%d", -1);
	}
	else
	{
		MergeSort(0, numberLen - 1);
		printf("%s", number);
	}
	return 0;
}
