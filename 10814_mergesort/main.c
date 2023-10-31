#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _PERSON
{
	int _age;
	char _name[201];
} Person;


Person g_p[100001];
Person g_temp[100001];

void MergeResult(Person p[], int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int temp_len = right - left + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (p[leftIdx]._age <= p[rightIdx]._age)
			g_temp[tempIdx++] = p[leftIdx++];
		else
			g_temp[tempIdx++] = p[rightIdx++];
	}
	
	if (leftIdx > mid)
	{
		while (rightIdx <= right)
			g_temp[tempIdx++] = p[rightIdx++];
	}
	else
	{
		while (leftIdx <= mid)
			g_temp[tempIdx++] = p[leftIdx++];
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		p[left + i] = g_temp[i];
	}
}

void MergeSort(Person p[], int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(p, left, mid);
	MergeSort(p, mid + 1, right);
	MergeResult(p, left, mid, right);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int p_index = 0; p_index < N; ++p_index) 
	{
		scanf("%d%s", &g_p[p_index]._age, g_p[p_index]._name);
	}

	MergeSort(g_p, 0, N - 1);
	
	for (int p_index = 0; p_index < N; ++p_index)
	{
		printf("%d %s\n", g_p[p_index]._age, g_p[p_index]._name);
	}
	return 0;
}