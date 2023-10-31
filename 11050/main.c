#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		int factorial = 1;
		for (int i = 1; i <= n; ++i)
			factorial *= i;
		return factorial;
	}
}


int GetBinomialCoefficient(int n, int k)
{
	if (k < 0)
	{
		return 0;
	}
	else if (k > n)
	{
		return 0;
	}
	else
	{
		return Factorial(n) / (Factorial(k) * Factorial(n - k));
	}
}

int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	fflush(stdin);
	printf("%d\n", GetBinomialCoefficient(n, k));
	return 0;
}