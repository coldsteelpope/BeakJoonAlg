#define		_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>



int main(void)
{
	int M, N;
	scanf("%d%d", &M, &N);
	fflush(stdin);

	for (int num = 2; num <= N; ++num)
	{
		bool isPrime = true;
		for (int div_num = 2; div_num <= (int)(sqrt(N)); ++div_num)
		{
			if (num == div_num)
			{
				if (num >= M && num <= N)
				{
					printf("%d\n", num);
				}
				isPrime = false;
				break;
			}
			else
			{
				if (num % div_num == 0)
				{
					isPrime = false;
					break;
				}
			}
		}
		if (isPrime)
		{
			if (num >= M && num <= N)
			{
				printf("%d\n", num);
			}
		}
	}
	return 0;
}