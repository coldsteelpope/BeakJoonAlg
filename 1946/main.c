#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct _EMPLOYEE
{
	int _paperScore;
	int _interviewScore;
} Employee;

Employee employees[100001] = { 0, };
Employee temp[100001] = { 0, };

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (employees[leftIdx]._paperScore < employees[rightIdx]._paperScore)
			temp[tempIdx++] = employees[leftIdx++];
		else
			temp[tempIdx++] = employees[rightIdx++];
	}

	if (mid < leftIdx)
	{
		while (rightIdx <= right)
			temp[tempIdx++] = employees[rightIdx++];
	}
	else
	{
		while (leftIdx <= mid)
			temp[tempIdx++] = employees[leftIdx++];
	}

	for (int i = 0; i < tempIdx; ++i)
		employees[left + i] = temp[i];
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

void PrintEmployees(int employees_num)
{
	printf("\n");
	for (int i = 0; i < employees_num; ++i)
	{
		printf("%d\t%d\n", employees[i]._paperScore, employees[i]._interviewScore);
	}
	printf("\n");
}

void SetEmployees(int employees_num)
{
	for (int i = 0; i < employees_num; ++i)
		scanf("%d%d", &employees[i]._paperScore, &employees[i]._interviewScore);
}

int GetMaxValue(int employees_num)
{
	int hired = 1;
	Employee pivot = employees[0];

	for (int i = 1; i < employees_num; ++i)
	{
		Employee current_emp = employees[i];
		if (pivot._interviewScore > current_emp._interviewScore)
		{
			pivot = current_emp;
			++hired;
		}
	}
	return hired;
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; ++t)
	{
		int employees_num = 0;
		scanf("%d", &employees_num);
		SetEmployees(employees_num);
		MergeSort(0, employees_num - 1);
		int answer = GetMaxValue(employees_num);
		printf("%d\n", answer);
	}
	return 0;
}