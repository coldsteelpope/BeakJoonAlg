#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ARR_LEN		1000

int iArr[MAX_ARR_LEN] = { 0, };
int iTempArr[MAX_ARR_LEN] = { 0, };

void MergeResult(int left, int mid, int right)
{
	int iLeftIdx = left;
	int iRightIdx = mid + 1;
	int iTempIdx = 0;

	while (iLeftIdx <= mid && iRightIdx <= right)
	{
		if (iArr[iLeftIdx] <= iArr[iRightIdx])
		{
			iTempArr[iTempIdx++] = iArr[iLeftIdx++];
		}
		else
		{
			iTempArr[iTempIdx++] = iArr[iRightIdx++];
		}
	}

	if (iLeftIdx > mid)
	{
		while (iRightIdx <= right)
		{
			iTempArr[iTempIdx++] = iArr[iRightIdx++];
		}
	}
	else
	{
		while (iLeftIdx <= mid)
		{
			iTempArr[iTempIdx++] = iArr[iLeftIdx++];
		}
	}

	for (int index = 0; index < iTempIdx; ++index)
	{
		iArr[left + index] = iTempArr[index];
	}
}

void MergeSort(int iLeft, int iRight)
{
	if (iLeft >= iRight)
	{
		return;
	}

	int iMid = (iLeft + iRight) / 2;
	MergeSort(iLeft, iMid);
	MergeSort(iMid + 1, iRight);
	MergeResult(iLeft, iMid, iRight);
}

int main(void)
{
	int iN;
	scanf("%d", &iN);
	
	for (int index = 0; index < iN; ++index)
	{
		scanf("%d", &iArr[index]);
	}

	MergeSort(0, iN - 1);

	for (int index = 0; index < iN; ++index)
	{
		printf("%d\n", iArr[index]);
	}

	return 0;
}