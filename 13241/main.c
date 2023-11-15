#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void SwapNode(long long int* a, long long int*b)
{
	long long int temp = *a;
	*a = *b;
	*b = temp;
}

// a > b
long long int GCD(long long int a, long long int b)
{
	if (a < b)
		SwapNode(&a, &b);

	long long int temp;
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
	long long int a, b;
	scanf("%lld%lld", &a, &b);
	long long int gcd = GCD(a, b);
	long long int lcm = (a * b) / gcd;
	printf("%lld\n", lcm);
	return 0;
}