#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int five_count = 0;
	int two_count = 0;
	for (long i = 1; i <= N; ++i)
	{
		int num = i;
		while (num % 2 == 0)
		{
			++two_count;
			num /= 2;
		}
		while (num % 5 == 0)
		{
			++five_count;
			num /= 5;
		}
	}
	int answer = (five_count > two_count) ? two_count : five_count;
	printf("%d", answer);
	return 0;
}