#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _POKETMON
{
	char	_name[21];
	int		_num;
} Poketmon;

Poketmon* poketmons[100001];
Poketmon* poketmons_sorted_by_name[100001];
Poketmon* temp[100001];

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (strcmp(poketmons_sorted_by_name[leftIdx]->_name, poketmons_sorted_by_name[rightIdx]) <= 0)
		{
			temp[tempIdx++] = poketmons_sorted_by_name[leftIdx++];
		}
		else
		{
			temp[tempIdx++] = poketmons_sorted_by_name[rightIdx++];
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = poketmons_sorted_by_name[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = poketmons_sorted_by_name[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		poketmons_sorted_by_name[left + i] = temp[i];
	}
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (right + left) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

void PrintPoketmon(int N)
{
	for (int i = 1; i <= N; ++i)
	{
		printf("%d: %s \n", poketmons_sorted_by_name[i]->_num, poketmons_sorted_by_name[i]->_name);
	}
	printf("\n");
}

int BinarySearch(int left, int right, char* poketmon_name)
{
	int i = -1;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		if (strcmp(poketmons_sorted_by_name[mid], poketmon_name) == 0)
		{
			i = mid;
			break;
		}
		else if (strcmp(poketmons_sorted_by_name[mid], poketmon_name) < 0)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return i;
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	for (int i = 1; i <= N; ++i)
	{
		Poketmon* poketmon = (Poketmon*)malloc(sizeof(Poketmon));
		poketmon->_num = i;
		scanf("%s", poketmon->_name);
		poketmons[i] = poketmon;
		poketmons_sorted_by_name[i] = poketmon;
	}

	MergeSort(1, N);

	for (int i = 0; i < M; ++i)
	{
		char str[21] = { 0, };
		scanf("%s", str);
		if (str[0] >= 48 && str[0] <= 57)
		{
			printf("%s\n", poketmons[atoi(str)]->_name);
		}
		else
		{
			int where_is_poketmon = BinarySearch(1, N, str);
			if (where_is_poketmon != -1)
				printf("%d\n", poketmons_sorted_by_name[where_is_poketmon]->_num);
		}
	}
	
	for (int i = 1; i <= N; ++i)
	{
		free(poketmons[i]);
	}
}