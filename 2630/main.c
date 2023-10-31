#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int paper[128][128] = { 0, };

bool Innocent(int init_y, int init_x, int N)
{
	bool isInnocent = true;
	for (int y = init_y; y < init_y + N; ++y)
	{
		for (int x = init_x; x < init_x + N; ++x)
		{
			if (paper[init_y][init_x] != paper[y][x])
			{
				isInnocent = false;
				break;
			}
		}
		if (isInnocent == false)
			break;
	}
	return isInnocent;
}

void DivideAndConquer(int init_y, int init_x, int N, int* blue_num, int* white_num)
{
	if (N == 1 || Innocent(init_y, init_x, N))
	{
		if (paper[init_y][init_x] == 1)
			(*blue_num)++;
		else
			(*white_num)++;
		return;
	}
	else
	{
		DivideAndConquer(init_y, init_x, N / 2, blue_num, white_num);
		DivideAndConquer(init_y + (N / 2), init_x, N / 2, blue_num, white_num);
		DivideAndConquer(init_y, init_x + (N / 2), N / 2, blue_num, white_num);
		DivideAndConquer(init_y + (N / 2), init_x + (N / 2), N / 2, blue_num, white_num);
	}
}

void PrintPaper(int N)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			printf("%d\t", paper[y][x]);
		}
		printf("\n");
	}
}

int main(void)
{
	int N;
	int blue_num = 0, white_num = 0;
	scanf("%d", &N);

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			scanf("%d", &paper[y][x]);

	DivideAndConquer(0, 0, N, &blue_num, &white_num);
	
	printf("%d\n", white_num);
	printf("%d\n", blue_num);
	
	return 0;
}