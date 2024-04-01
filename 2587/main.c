#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN		5

int iArray[MAX_LEN] = { 0, };
int iTemp[MAX_LEN] = { 0, };

void SetArray();

int GetAverage();

void MergeResult(int _iStart, int _iMid, int _iEnd);

void MergeSort(int _iStart, int _iEnd);

int main(void)
{
	SetArray();
	int iAverage = GetAverage();
	MergeSort(0, MAX_LEN - 1);
	int iMidValue = iArray[(MAX_LEN + 0) / 2];
	printf("%d\n%d\n", iAverage, iMidValue);
	return 0;
}

void SetArray()
{
	for (int i = 0; i < MAX_LEN; ++i)
	{
		scanf("%d", &iArray[i]);
	}
}

int GetAverage()
{
	int iSum = 0;
	for (int i = 0; i < MAX_LEN; ++i)
	{
		iSum += iArray[i];
	}
	return iSum / MAX_LEN;
}

void MergeSort(int _iStart, int _iEnd)
{
	if (_iStart >= _iEnd)
	{
		return;
	}

	int iMid = (_iStart + _iEnd) / 2;
	MergeSort(_iStart, iMid);
	MergeSort(iMid + 1, _iEnd);
	MergeResult(_iStart, iMid, _iEnd);
}

void MergeResult(int _iStart, int _iMid, int _iEnd)
{
	int iLeftIdx = _iStart;
	int iRightIdx = _iMid + 1;
	int iTempIdx = 0;

	while (iLeftIdx <= _iMid && iRightIdx <= _iEnd)
	{
		if (iArray[iLeftIdx] <= iArray[iRightIdx])
		{
			iTemp[iTempIdx++] = iArray[iLeftIdx++];
		}
		else
		{
			iTemp[iTempIdx++] = iArray[iRightIdx++];
		}
	}

	if (iLeftIdx > _iMid)
	{
		while (iRightIdx <= _iEnd)
		{
			iTemp[iTempIdx++] = iArray[iRightIdx++];
		}
	}
	else
	{
		while (iLeftIdx <= _iMid)
		{
			iTemp[iTempIdx++] = iArray[iLeftIdx++];
		}
	}

	for (int i = 0; i < iTempIdx; ++i)
	{
		iArray[_iStart + i] = iTemp[i];
	}
}