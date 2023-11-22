#define _CRT_SECURE_NO_WARNINGS

// 다음에 풀 때는 이중 반복문으로 풀어보기
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dwarfs[9] = { 0, };
bool visited[9] = { 0, };

int realDwarfs[7] = { 0, };

void Permutation(int realDwarfsIdx)
{
	if (realDwarfsIdx == 7)
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
		return;
	}
	else
	{
		for (int numIdx = 0; numIdx < 9; ++numIdx)
		{
			if (visited[numIdx] == true)
				continue;
			visited[numIdx] = true;
			realDwarfs[realDwarfsIdx] = dwarfs[numIdx];
			Permutation(realDwarfsIdx + 1);
			visited[numIdx] = false;
		}
	}
}


int main(void)
{
	for (int i = 0; i < 9; ++i)
	{
		scanf("%d", &dwarfs[i]);
	}
	Permutation(0);
	return 0;
}