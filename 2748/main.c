#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int num[91] = { 0, };

int main(void)
{
	int n;
	scanf("%d", &n);
	num[1] = 0;
	num[2] = 1;
	
	for (int i = 3; i <= n + 1; ++i)
	{
		num[i] = num[i - 1] + num[i - 2];
	}
	printf("%d", num[n + 1]);
	return 0;
}