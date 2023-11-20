#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	long long int N;
	scanf("%lld", &N);

	long long int seq = 0;
	long long int sum = 0;
	
	while (sum < N)
	{
		sum += (seq + 1);
		++seq;
	}

	long long int T = N - (sum - seq);
	
	long long int numerator;
	long long int denominator;

	if (seq % 2 == 0)
	{
		numerator = T;
		denominator = seq - T + 1;
	}
	else
	{
		numerator = seq - T + 1;
		denominator = T;
	}

	printf("%lld/%lld", numerator, denominator);
	return 0;
}