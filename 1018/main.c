#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char maps[50][50];

void PrintMaps(int start_y, int start_x)
{
	for (int y = start_y; y < start_y + 8; ++y)
	{
		for (int x = start_x; x < start_x + 8; ++x)
		{
			printf("%c", maps[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int row = 0; row < N; ++row)
	{
		scanf("%s", maps[row]);
	}

	int minVal = 99999;
	for (int start_y = 0; start_y < (N + 1) - 8; ++start_y)
	{
		for (int start_x = 0; start_x < (M + 1) - 8; ++start_x)
		{
			//printf("Current Matrix (%d, %d) \n", start_y, start_x);
			//PrintMaps(start_y, start_x);
			int candidateMinVal = 0;
			char startCurrentColor = 'B';
			for (int row = start_y; row < start_y + 8; ++row)
			{
				char mustBeColor = startCurrentColor;
				for (int col = start_x; col < start_x + 8; ++col)
				{
					char currentColor = maps[row][col];
					if (currentColor != mustBeColor)
						candidateMinVal++;
					mustBeColor = (mustBeColor == 'W') ? 'B' : 'W';
				}
				startCurrentColor = (startCurrentColor == 'B') ? 'W' : 'B';
			}
			minVal = (minVal > candidateMinVal) ? candidateMinVal : minVal;

			candidateMinVal = 0;
			startCurrentColor = 'W';
			for (int row = start_y; row < start_y + 8; ++row)
			{
				char mustBeColor = startCurrentColor;
				for (int col = start_x; col < start_x + 8; ++col)
				{
					char currentColor = maps[row][col];
					if (currentColor != mustBeColor)
						candidateMinVal++;
					mustBeColor = (mustBeColor == 'W') ? 'B' : 'W';
				}
				startCurrentColor = (startCurrentColor == 'B') ? 'W' : 'B';
			}
			minVal = (minVal > candidateMinVal) ? candidateMinVal : minVal;
		}
	}
	
	printf("%d", minVal);
	return 0;
}