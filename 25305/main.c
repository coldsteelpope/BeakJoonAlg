#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STUDENT_NUM		1000

int iStudentScores[MAX_STUDENT_NUM] = { 0, };
int iTempArray[MAX_STUDENT_NUM] = { 0, };

void MergeResult(int _iStart, int _iMid, int _iEnd);

void MergeSort(int _iStart, int _iEnd);

int main(void)
{
	int iN, ik;
	scanf("%d%d", &iN, &ik);
	
	for (int i = 0; i < iN; ++i)
	{
		scanf("%d", &iStudentScores[i]);
	}

	MergeSort(0, iN - 1);
	printf("%d\n", iStudentScores[ik - 1]);

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

	while (iLeftIdx <= _iMid && iRightIdx <= _iEnd)
	{
		if (iStudentScores[iLeftIdx] >= iStudentScores[iRightIdx])
		{
			iTempArray[iTempIdx++] = iStudentScores[iLeftIdx++];
		}
		else
		{
			iTempArray[iTempIdx++] = iStudentScores[iRightIdx++];
		}
	}

	if (iLeftIdx > _iMid)
	{
		while (iRightIdx <= _iEnd)
		{
			iTempArray[iTempIdx++] = iStudentScores[iRightIdx++];
		}
	}
	else
	{
		while (iLeftIdx <= _iMid)
		{
			iTempArray[iTempIdx++] = iStudentScores[iLeftIdx++];
		}
	}

	for (int i = 0; i < iTempIdx; ++i)
	{
		iStudentScores[_iStart + i] = iTempArray[i];
	}
}