#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool IsThreatened(int columns[], int row)
{
	bool threatened = false;
	for (int current_row = 1; current_row < row; ++current_row)
	{
		if
		(
			columns[current_row] == columns[row] ||
			abs(columns[current_row] - columns[row]) == abs(current_row - row)
		)
		{
			threatened = true;
			break;
		}
	}
	return threatened;
}

void PrintChess(int columns[], int num)
{
	printf("\n");
	for (int i = 1; i <= num; ++i)
	{
		for (int j = 1; j <= num; ++j)
		{
			if (columns[i] == j)
				printf("Q");
			else
				printf(".");
		}
		printf("\n");
	}
	printf("\n");
}


void GetAnswer(int columns[], int row, int num, int* count)
{
	if (IsThreatened(columns, row))
		return;
	else
	{
		if (row == num)
		{
			++(*count);
			//PrintChess(columns, num);
		}
		else
		{
			for (int i = 1; i <= num; ++i)
			{
				columns[row + 1] = i;
				GetAnswer(columns, row + 1, num, count);
			}
		}
	}
}


int main(void)
{
	int N;
	scanf("%d", &N);

	int* columns = (int*)calloc(N + 1, sizeof(int));
	int count = 0;

	for (int i = 1; i <= N; ++i)
	{
		columns[1] = i;
		GetAnswer(columns, 1, N, &count);
	}
	printf("%d", count);
	free(columns);
	return 0;
}