#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Swap(int* a, int* b)
{
	int* temp = *a;
	*a = *b;
	*b = temp;
}

int GCD(int a, int b)
{
	if (a < b)
	{
		Swap(&a, &b);
	}

	int temp;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; ++testCase)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		long long int gcd = GCD(a, b);
		long long int lcm = ((long long int)a * b) / gcd;
		printf("%lld\n", lcm);
	}
	return 0;
}