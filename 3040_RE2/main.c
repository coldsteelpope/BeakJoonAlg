#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 10

int dwarfs[MAX_LEN] = { 0, };
int realDwarfs[MAX_LEN] = { 0, };

void Permutation(int index, int startIdx)
{
	if (index == 7)
	{
		int sum = 0;
		for (int i = 0; i < 7; ++i)
		{
			sum += realDwarfs[i];
		}

		if (sum == 100)
		{
			for (int i = 0; i < 7; ++i)
			{
				printf("%d\n", realDwarfs[i]);
			}
			exit(0);
		}
	}
	else
	{
		for (int i = startIdx; i < 9; ++i)
		{
			realDwarfs[index] = dwarfs[i];
			// startIdx + 1을 하면 중복됨
			Permutation(index + 1, i + 1);
		}
	}
}

int main(void)
{
	for (int i = 0; i < 9; ++i)
	{
		scanf("%d", &dwarfs[i]);
	}
	Permutation(0, 0);
}