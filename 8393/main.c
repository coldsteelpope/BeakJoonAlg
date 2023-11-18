#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	long long int sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		sum += i;
	}
	printf("%lld\n", sum);
	return 0;
}