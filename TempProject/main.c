#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[10] = { 0, };

int Partition(int left, int right)
{
	int pivot = arr[left];
	int leftPointer = left;
	int rightPointer = right;

	while (left <= leftPointer && right <= rightPointer)
	{
		rightPointer = 1;
		arr[0] = 1;
		arr[1] = 2;
	}
}

int main(void)
{

}