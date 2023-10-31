#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int GetMaxNumberInFloorN(int n)
{
	return (3 * n * n) - (3 * n) + 1;
}

int main(void)
{
	long num;
	long floor = 1;
	scanf("%ld", &num);
	while (GetMaxNumberInFloorN(floor) < num)
		++floor;
	printf("%ld", floor);
	return 0;
}