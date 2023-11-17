#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// why pow함수가 먹히지 않은거지?
long long int Pow(long long int a, long long int b)
{
	long long int result = 1;
	while (b != 0)
	{
		if (b % 2 != 0)
			result = (result * a) % 10;
		a = (a * a) % 10;
		b = (b / 2) % 10;
	}
	return result % 10;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; ++testCase)
	{
		long long int a, b;
		scanf("%lld%lld", &a, &b);

		
		long long int result = 1;
		for (int i = 1; i <= b; ++i)
		{
			result = (result * a) % 10;
		}
		if (result == 0)
		{
			printf("%lld\n", 10);
		}
		else
		{
			printf("%lld\n", result);
		}
	}
	return 0;
}