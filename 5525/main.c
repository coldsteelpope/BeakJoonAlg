#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char S[1000001] = { 0, };
int SPointer = 0;

int main(void)
{
	int N;
	scanf("%d", &N);
	int M;
	scanf("%d", &M);

	scanf("%s", S);

	int answer = 0;
	int IOICount = 0;
	while (SPointer < M - 1)
	{
		if (S[SPointer] == 'I' && S[SPointer + 1] == 'O' && S[SPointer + 2] == 'I')
		{
			++IOICount;
			SPointer += 2;
			if (IOICount == N)
			{
				++answer;
				--IOICount;
			}
		}
		else
		{
			SPointer++;
			IOICount = 0;
		}
	}

	printf("%d\n", answer);
	return 0;
}