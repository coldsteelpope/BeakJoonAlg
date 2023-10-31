#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000007

long long Power(long long A, long long X)
{
	long long result = 1;
	while (X != 0)
	{
		if (X % 2 != 0)
			result = (result * A) % MOD;
		A = (A * A) % MOD;
		X /= 2;
	}
	return result;
}

int main(void)
{
	long long A;
	long long X;
	scanf("%lld%lld", &A, &X);
	printf("%lld", Power(A % MOD, X));
	return 0;
}