#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	long long S;
	scanf("%lld", &S);

	long long answer = 0;
	for (long long i = 1; i <= S; ++i)
	{
		if (((i * i) + i) > (S * 2))
		{
			answer = i - 1;
			break;
		}
		else if (((i * i) + i) == (S * 2))
		{
			answer = i;
			break;
		}
	}

	printf("%lld", answer);
	return 0;
}