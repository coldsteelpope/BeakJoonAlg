#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int answer = 0;
	while (N != 0)
	{
		answer += N % 2;
		N /= 2;
	}
	printf("%d\n", answer);
	return 0;
}