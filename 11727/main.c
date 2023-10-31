#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int nums[1001] = { 0, };

int main(void)
{
	int n;
	scanf("%d", &n);

	nums[1] = 1;
	nums[2] = 3;
	for (int i = 3; i <= 1000; ++i)
		nums[i] = (nums[i - 1] + 2 * nums[i - 2]) % 10007;
	printf("%d\n", nums[n]);
	return 0;
}