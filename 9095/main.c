#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int num[12] = { 0, };

int main(void)
{
	int n;
	
	scanf("%d", &n);
	
	num[0] = 0;
	num[1] = 1;
	num[2] = 2;
	num[3] = 4;
	for (int i = 4; i <= 11; ++i)
	{
		num[i] = num[i - 1] + num[i - 2] + num[i - 3];
	}

	for (int i = 0; i < n; ++i)
	{
		int current_num = 0;
		scanf("%d", &current_num);
		printf("%d\n", num[current_num]);
	}
	return 0;
}