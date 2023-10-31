#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char picture[3075][6145] = { 0, };

void ClearPicture(long long N)
{
	long long height = N;
	long long width = height * 2 - 1;
	
	for (int y = 0; y <= height; ++y)
		for (int x = 0; x <= width; ++x)
			picture[y][x] = ' ';
}

void DrawTriangle(long long y, long long x)
{
	picture[y][x] = '*';
	
	picture[y + 1][x - 1] = '*';
	picture[y + 1][x + 1] = '*';

	picture[y + 2][x + 2] = '*';
	picture[y + 2][x + 1] = '*';
	picture[y + 2][x] = '*';
	picture[y + 2][x - 1] = '*';
	picture[y + 2][x - 2] = '*';
}

void DrawTriangles(long long N, long long y, long long x)
{
	if (N == 3)
	{
		DrawTriangle(y, x);
		return;
	}
	else
	{
		DrawTriangles(N / 2, y, x);
		DrawTriangles(N / 2, y + (N / 2), x - (N / 2));
		DrawTriangles(N / 2, y + (N / 2), x + (N / 2));
	}
}

void ShowPicture(long long N)
{
	long long height = N;
	long long width = height * 2 - 1;

	for (long long y = 1; y <= height; ++y)
	{
		for (long long x = 1; x <= width; ++x)
		{
			printf("%c", picture[y][x]);
		}
		printf("\n");
	}
}

int main(void)
{
	long long N;
	scanf("%lld", &N);

	ClearPicture(N);
	long long pivot_x = N;

	DrawTriangles(N, 1, pivot_x);
	ShowPicture(N);
	return 0;
}