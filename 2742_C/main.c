#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int num = N; num >= 1; --num)
	{
		printf("%d\n", num);
	}
	return 0;
}