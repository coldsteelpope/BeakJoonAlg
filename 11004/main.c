#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int iArrays[5000001] = { 0, };
int iTmpArrays[5000001] = { 0, };

void MergeResult(int _iStart, int _iMid, int _iEnd)
{
	int iLeftIndex = _iStart;
	int iRightIndex = _iMid + 1;
	int iTmpIndex = 0;

	while (iLeftIndex <= _iMid && iRightIndex <= _iEnd)
	{
		if (iArrays[iLeftIndex] <= iArrays[iRightIndex])
		{
			iTmpArrays[iTmpIndex++] = iArrays[iLeftIndex++];
		}
		else
		{
			iTmpArrays[iTmpIndex++] = iArrays[iRightIndex++];
		}
	}

	if (iLeftIndex > _iMid)
	{
		while (iRightIndex <= _iEnd)
		{
			iTmpArrays[iTmpIndex++] = iArrays[iRightIndex++];
		}
	}
	else
	{
		while (iLeftIndex <= _iMid)
		{
			iTmpArrays[iTmpIndex++] = iArrays[iLeftIndex++];
		}
	}

	for (int i = 0; i < iTmpIndex; ++i)
	{
		iArrays[_iStart + i] = iTmpArrays[i];
	}
}


int Merge(int _iStart, int _iEnd)
{
	if (_iStart >= _iEnd)
	{
		return;
	}

	int iMid = (_iStart + _iEnd) / 2;
	Merge(_iStart, iMid); // 왜 iMid - 1은 안되는 걸까
	Merge(iMid + 1, _iEnd);
	MergeResult(_iStart, iMid, _iEnd);
}


int main(void)
{
	int iNumber;
	int iFindNumber;
	scanf("%d%d", &iNumber, &iFindNumber);

	for (int i = 0; i < iNumber; ++i)
	{
		scanf("%d", &iArrays[i]);
	}

	Merge(0, iNumber - 1);
	printf("%d\n", iArrays[iFindNumber - 1]);
	
	return 0;
}