#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long PowerTwo(int A, int B, int C)
{
	long long result = 1;
	while (B != 0)
	{
		if (B % 2 != 0)
			result *= A;
		A *= A;
		B /= 2;
	}
	return result;
}

// 시간 초과
long long PowerOne(int A, int B, int C)
{
	if (B == 0)
	{
		return 1;
	}
	else if (B == 1)
	{
		return A % C;
	}
	else
	{
		if (B % 2 == 0)
			return (PowerOne(A, B / 2, C) * PowerOne(A, B / 2, C)) % C;
		else
			return (PowerOne(A, (B - 1) / 2, C) * PowerOne(A, (B - 1) / 2, C) % C) * A % C;
	}
}

int main(void)
{
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);

	long long result1 = PowerOne(A % C, B, C);
	printf("%lld", result1);
	return 0;
}