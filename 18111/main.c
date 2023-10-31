#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define MAX_WIDTH	500
#define MAX_HEIGHT	500


int map[MAX_HEIGHT][MAX_WIDTH] = { 0, };
int labMap[MAX_HEIGHT][MAX_WIDTH] = { 0, };

int main(void)
{
	int N, M, B;
	int highest = 0;
	int lowest = 2147483647;

	scanf("%d%d%d", &N, &M, &B);
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			scanf("%d", &map[y][x]);
			highest = (map[y][x] > highest) ? map[y][x] : highest;
			lowest = (map[y][x] < lowest) ? map[y][x] : lowest;
		}
	}

	int maxHeight = 0;
	int minTimeToWork = 2147483647;
	for (int blockHeight = lowest; blockHeight <= highest; ++blockHeight)
	{
		int currentBlock = B;
		int timeToWork = 0;
		bool isChanged = false;

		for (int y = 0; y < N; ++y)
			for (int x = 0; x < M; ++x)
				labMap[y][x] = blockHeight;
		
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < M; ++x)
			{
				int labMapBlock = labMap[y][x];
				int mapBlock = map[y][x];
				int diff = mapBlock - labMapBlock;
				if (diff > 0)
					timeToWork += (2 * abs(diff));
				else if (diff < 0)
					timeToWork += abs(diff);
				// diff > 0 => 파기
				// diff < 0 => 쌓기
				// diff == 0 => 그대로두기
				currentBlock += diff;
			}
		}
		if (currentBlock < 0)
			continue;
		else
		{
			if (minTimeToWork >= timeToWork)
			{
				minTimeToWork = timeToWork;
				isChanged = true;
			}
			if (isChanged)
			{
				maxHeight = blockHeight;
			}	
		}
	}
	printf("%d %d", minTimeToWork, maxHeight);
	return 0;
}