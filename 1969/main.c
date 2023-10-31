#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _WORD
{
	char _w;
	int _count;
} Word;

char DNA[1001][51] = { 0, };
Word temp[4] = { 0, };

//void MergeResultChar(int left, int mid, int right, Word* words)
//{
//	int leftIdx = left;
//	int rightIdx = mid + 1;
//	int tempIdx = 0;
//
//	while (leftIdx <= mid && rightIdx <= right)
//	{
//		if (words[leftIdx]._w < words[rightIdx]._w)
//			temp[tempIdx++] = words[leftIdx++];
//		else
//			temp[tempIdx++] = words[rightIdx++];
//	}
//
//	if (mid < leftIdx)
//	{
//		while (rightIdx <= right)
//			temp[tempIdx++] = words[rightIdx++];
//	}
//	else
//	{
//		while (leftIdx <= mid)
//			temp[tempIdx++] = words[leftIdx++];
//	}
//
//	for (int i = 0; i < tempIdx; ++i)
//		words[left + i] = temp[i];
//}
//
//void MergeSortChar(int left, int right, Word* words)
//{
//	if (left >= right)
//		return;
//	int mid = (left + right) / 2;
//	MergeSortChar(left, mid, words);
//	MergeSortChar(mid + 1, right, words);
//	MergeResultChar(left, mid, right, words);
//}

void MergeResult(int left, int mid, int right, Word* words)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (words[leftIdx]._count > words[rightIdx]._count)
			temp[tempIdx++] = words[leftIdx++];
		else if(words[leftIdx]._count < words[rightIdx]._count)
			temp[tempIdx++] = words[rightIdx++];
		else
		{
			if (words[leftIdx]._w < words[rightIdx]._w)
				temp[tempIdx++] = words[leftIdx++];
			else
				temp[tempIdx++] = words[rightIdx++];
		}
	}

	if (mid < leftIdx)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = words[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = words[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		words[left + i] = temp[i];
	}
}

void MergeSort(int left, int right, Word* words)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(left, mid, words);
	MergeSort(mid + 1, right, words);
	MergeResult(left, mid, right, words);
}

int main(void)
{
	char answer[51] = { 0, };
	int answerIdx = 0;

	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; ++i)
		scanf("%s", DNA[i]);

	int dist = 0;

	for (int j = 0; j < M; ++j)
	{
		Word words[4] = { 0,0,0,0 };
		words[0]._w = 'A'; words[1]._w = 'C'; words[2]._w = 'G'; words[3]._w = 'T';
		words[0]._count = 0; words[1]._count = 0; words[2]._count = 0; words[3]._count = 0;
		
		for (int i = 0; i < N; ++i)
		{
			if (DNA[i][j] == 'A')
				words[0]._count += 1;
			else if (DNA[i][j] == 'C')
				words[1]._count += 1;
			else if (DNA[i][j] == 'G')
				words[2]._count += 1;
			else if (DNA[i][j] == 'T')
				words[3]._count += 1;
		}

		MergeSort(0, 3, words);
		
		answer[answerIdx++] = words[0]._w;
		
		for (int i = 0; i < N; ++i)
		{
			if (words[0]._w != DNA[i][j])
				++dist;
		}
	}
	printf("%s\n", answer);
	printf("%d\n", dist);
	return 0;
}