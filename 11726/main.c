#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n[1001] = { 0, };

int main(void)
{
	n[1] = 1;
	n[2] = 2;
	for (int i = 3; i <= 1000; ++i)
		n[i] = n[i - 1] + n[i - 2];
	int num;
	scanf("%d", &num);
	printf("%d\n", n[num]);
	return 0;
}