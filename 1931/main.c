#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _CONFERENCE
{
	unsigned int _startTime;
	unsigned int _endTime;
	unsigned int _diff;
} Conference;

Conference* conferences[100000];
int conferences_index = 0;
Conference* temp[100000];

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (conferences[leftIdx]->_endTime < conferences[rightIdx]->_endTime)
		{
			temp[tempIdx++] = conferences[leftIdx++];
		}
		else if(conferences[leftIdx]->_endTime > conferences[rightIdx]->_endTime)
		{
			temp[tempIdx++] = conferences[rightIdx++];
		}
		else
		{
			if (conferences[leftIdx]->_startTime <= conferences[rightIdx]->_startTime)
			{
				temp[tempIdx++] = conferences[leftIdx++];
			}
			else
			{
				temp[tempIdx++] = conferences[rightIdx++];
			}
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
			temp[tempIdx++] = conferences[rightIdx++];
	}
	else
	{
		while (leftIdx <= mid)
			temp[tempIdx++] = conferences[leftIdx++];
	}

	for (int i = 0; i < tempIdx; ++i)
		conferences[left + i] = temp[i];
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
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		Conference* newConference = (Conference*)malloc(sizeof(Conference));
		scanf("%u%u", &newConference->_startTime, &newConference->_endTime);
		newConference->_diff = newConference->_endTime - newConference->_startTime;
		conferences[conferences_index++] = newConference;
	}
	
	MergeSort(0, N - 1);
	
	// j가 현재 진행중인 회의 index
	int j = 0;
	int count = 1;
	// i는 다음에 진행할 회의 index
	for (int i = 1; i < N; ++i)
	{
		if (conferences[j]->_endTime <= conferences[i]->_startTime)
		{
			// 다음에 진행할 회의를 이제 진행
			j = i;
			++count;
		}
	}
	printf("%d\n", count);
	return 0;
}