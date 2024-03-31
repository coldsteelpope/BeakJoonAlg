#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1000001

int iArray[MAX_LEN] = { 0, };
int iTempArray[MAX_LEN] = { 0, };

void MergeResult(int _start, int _mid, int _end)
{
	int iLeftIdx = _start;
	int iRightIdx = _mid + 1;
	int iTempArrayIdx = 0;

	while (iLeftIdx <= _mid && iRightIdx <= _end)
	{
		if (iArray[iLeftIdx] >= iArray[iRightIdx])
		{
			iTempArray[iTempArrayIdx++] = iArray[iLeftIdx++];
		}
		else
		{
			iTempArray[iTempArrayIdx++] = iArray[iRightIdx++];
		}
	}

	if (iLeftIdx > _mid)
	{
		while (iRightIdx <= _end)
		{
			iTempArray[iTempArrayIdx++] = iArray[iRightIdx++];
		}
	}
	else
	{
		while (iLeftIdx <= _mid)
		{
			iTempArray[iTempArrayIdx++] = iArray[iLeftIdx++];
		}
	}

	for (int i = 0; i < iTempArrayIdx; ++i)
	{
		iArray[_start + i] = iTempArray[i];
	}
}

void MergeSort(int _iStart, int _iEnd)
{
	if (_iStart >= _iEnd)
	{
		return;
	}

	int mid = (_iStart + _iEnd) / 2;
	MergeSort(_iStart, mid);
	MergeSort(mid + 1, _iEnd);
	MergeResult(_iStart, mid, _iEnd);
}

int main(void)
{
	int iN;
	scanf("%d", &iN);

	for (int i = 0; i < iN; ++i)
	{ 
		scanf("%d", &iArray[i]);
	}

	MergeSort(0, iN - 1);
	
	for (int i = 0; i < iN; ++i)
	{
		printf("%d\n", iArray[i]);
	}

	return 0;
}