#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int Partition(int left, int right, int* num)
{
	int pivot = num[left];
	int lowPointer = left + 1;
	int highPointer = right;

	while (lowPointer <= highPointer)
	{
		if (lowPointer <= right && num[lowPointer] >= pivot)
		{
			++lowPointer;
		}
		
		if (highPointer >= left && num[highPointer] <= pivot)
		{
			--highPointer;
		}

		if (lowPointer < highPointer)
		{
			Swap(&num[lowPointer], &num[highPointer]);
		}
	}
	Swap(&num[left], &num[highPointer]);
	return highPointer;
}

void QuickSort(int left, int right, int* num)
{
	if (left > right)
		return;
	int pivot = Partition(left, right, num);
	QuickSort(left, pivot - 1, num);
	QuickSort(pivot + 1, right, num);
}

int GetStrLen(char* str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		++len;
	}
	return len;
}

int main(void)
{
	char str[16] = { 0, };
	int num[16] = { 0, };
	scanf("%s", str);
	int strLen = GetStrLen(str);
	for (int i = 0; i < strLen; ++i)
	{
		num[i] = str[i] - '0';
	}
	QuickSort(0, strLen - 1, num);
	for (int i = 0; i < strLen; ++i)
	{
		printf("%d", num[i]);
	}
	return 0;
}