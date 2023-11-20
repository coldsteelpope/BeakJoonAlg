#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int answer = 0;
	int leftPointer = 1;
	int rightPointer = 1;
	while (leftPointer <= rightPointer)
	{
		long long int sum = 0;
		for (int i = leftPointer; i <= rightPointer; ++i)
		{
			sum += i;
		}

		if (sum == N)
		{
			//printf("leftPointer: %d, rightPointer: %d\n", leftPointer, rightPointer);
			++answer;
		}


		if (rightPointer < N)
		{
			if (sum < N)
			{
				++rightPointer;
			}
			else
			{
				++leftPointer;
			}
		}
		else
		{
			++leftPointer;
		}
	}

	printf("%d\n", answer);
	return 0;
}