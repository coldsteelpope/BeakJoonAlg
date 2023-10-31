#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int N;
	long int M;
	scanf("%d%ld", &N, &M);
	
	int* cards = (int*)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; ++i)
		scanf("%d", &cards[i]);

	long int maxVal = 0;
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = i + 1; j < N - 1; ++j)
		{
			for (int k = j + 1; k < N; ++k)
			{
				long int sum = cards[i] + cards[j] + cards[k];
				if (sum <= M && maxVal <= sum)
					maxVal = sum;
			}
		}
	}
	printf("%ld\n", maxVal);
	return 0;
}