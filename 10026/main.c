#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

char picture[100][100] = { 0, };
bool visited[100][100] = { 0, };


void DfsColorBlind(int y, int x, int N, char current_color)
{
	if (y < 0 || x < 0 || x >= N || y >= N)
		return;
	if (visited[y][x] == true)
		return;

	if (picture[y][x] == 'R' || picture[y][x] == 'G')
	{
		if (current_color == 'B')
			return;
	}
	else
	{
		if (picture[y][x] != current_color)
			return;
	}

	visited[y][x] = true;

	DfsColorBlind(y, x + 1, N, current_color);
	DfsColorBlind(y + 1, x, N, current_color);
	DfsColorBlind(y, x - 1, N, current_color);
	DfsColorBlind(y - 1, x, N, current_color);
}


void DfsAllColorBlind(int N, int* red_green_zone, int* blue_zone)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (visited[y][x] == true)
				continue;
			if (picture[y][x] == 'R' || picture[y][x] == 'G')
				++(*red_green_zone);
			else if (picture[y][x] == 'B')
				++(*blue_zone);
			DfsColorBlind(y, x, N, picture[y][x]);
		}
	}
}

void DfsNormalVersion(int y, int x, int N, char current_color)
{
	if (y < 0 || x < 0 || x >= N || y >= N)
		return;
	if (visited[y][x] == true)
		return;
	if (picture[y][x] != current_color)
		return;
	visited[y][x] = true;

	DfsNormalVersion(y, x + 1, N, current_color);
	DfsNormalVersion(y + 1, x, N, current_color);
	DfsNormalVersion(y, x - 1, N, current_color);
	DfsNormalVersion(y - 1, x, N, current_color);
}

void DfsAllNormalVersion(int N, int* red_zone, int* green_zone, int* blue_zone)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (visited[y][x] == true)
				continue;
			
			if (picture[y][x] == 'R')
				++(*red_zone);
			else if (picture[y][x] == 'G')
				++(*green_zone);
			else if (picture[y][x] == 'B')
				++(*blue_zone);

			DfsNormalVersion(y, x, N, picture[y][x]);
		}
	}
}

void SetPicture(int N)
{
	for (int y = 0; y < N; ++y)
		scanf("%s", picture[y]);
}

void PrintPicture(int N)
{
	for (int y = 0; y < N; ++y)
		printf("%s\n", picture[y]);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	SetPicture(N);
	//PrintPicture(N);

	int red_zone = 0;
	int blue_zone = 0;
	int green_zone = 0;

	DfsAllNormalVersion(N, &red_zone, &green_zone, &blue_zone);

	memset(visited, 0, sizeof(visited));
	int red_green_zone = 0;
	int blue_blind_zone = 0;
	DfsAllColorBlind(N, &red_green_zone, &blue_blind_zone);

	int total_normal_zone = red_zone + blue_zone + green_zone;
	int total_blind_zone = red_green_zone + blue_blind_zone;

	printf("%d %d", total_normal_zone, total_blind_zone);
	return 0;
}