#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	long long num = 0;
	long long N, M;
	scanf("%lld%lld", &N, &M);

	if (N == 1)
	{
		printf("%lld", 1);
	}
	else if (N == 2)
	{
		num = ((M - 1) / 2 + 1);
		if (num >= 4)
			printf("%lld", 4);
		else
			printf("%lld", num);
	}
	else
	{
		if (M <= 4)
		{
			num = M;
			printf("%lld", num);
		}
		else if (M >= 5 && M <= 6)
		{
			num = 4;
			printf("%lld", num);
		}
		else
		{
			num = (2 + (M - 5)) + 1;
			printf("%lld", num);
		}
	}
	return 0;
}