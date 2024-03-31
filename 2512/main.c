#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN		10001

int iArray[MAX_LEN] = { 0, };
int iTempArray[MAX_LEN] = { 0, };

void MergeResult(int _iStart, int _iMid, int _iEnd);
void MergeSort(int _iStart, int _iEnd);
int GetTotalBudget(int _iMidBudget, size_t iArrayLen);
int GetMaxBudget(int _iN, int _iM);

int main(void)
{
	int iN;
	int iM;

	scanf("%d", &iN);
	for (int i = 0; i < iN; ++i)
	{
		scanf("%d", &iArray[i]);
	}	
	scanf("%d", &iM);

	MergeSort(0, iN - 1);
	int iMaxBudget = GetMaxBudget(iN, iM);
	printf("%d\n", iMaxBudget);
	return 0;
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

	while (_iMid >= iLeftIdx && _iEnd >= iRightIdx)
	{
		if (iArray[iLeftIdx] <= iArray[iRightIdx])
		{
			iTempArray[iTempIdx++] = iArray[iLeftIdx++];
		}
		else
		{
			iTempArray[iTempIdx++] = iArray[iRightIdx++];
		}
	}

	if (_iMid < iLeftIdx)
	{
		while (iRightIdx <= _iEnd)
		{
			iTempArray[iTempIdx++] = iArray[iRightIdx++];
		}
	}
	else
	{
		while (iLeftIdx <= _iMid)
		{
			iTempArray[iTempIdx++] = iArray[iLeftIdx++];
		}
	}

	for (int i = 0; i < iTempIdx; ++i)
	{
		iArray[_iStart + i] = iTempArray[i];
	}
}

int GetTotalBudget(int _iMidBudget, size_t iArrayLen)
{
	int iTotalBudget = 0;
	for (int i = 0; i < iArrayLen; ++i)
	{
		if (iArray[i] > _iMidBudget)
		{
			iTotalBudget += _iMidBudget;
			continue;
		}
		iTotalBudget += iArray[i];
	}
	return iTotalBudget;
}

int GetMaxBudget(int _iN, int _iM)
{
	int iLowestBudget = 0;
	int iHighestBudget = iArray[_iN - 1];

	//int resultBudget = 0;

	while (iLowestBudget < iHighestBudget)
	{
		int iMidBudget = (iLowestBudget + iHighestBudget) / 2;
		int iTotalBudget = GetTotalBudget(iMidBudget, _iN);

		if (iTotalBudget > _iM)
		{
			iHighestBudget = iMidBudget;
		}
		else
		{
			iLowestBudget = iMidBudget + 1;
		}
	}
	//return resultBudget;
	return (iLowestBudget == iArray[_iN - 1]) ? iLowestBudget : iLowestBudget - 1;
}

