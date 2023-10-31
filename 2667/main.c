#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int map[25][25] = { 0, };
bool visited[25][25] = { 0, };
int danji_nums[625] = { 0, };
int temp[625] = { 0, };
int danji_nums_len = 0;

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (danji_nums[leftIdx] <= danji_nums[rightIdx])
		{
			temp[tempIdx++] = danji_nums[leftIdx++];
		}
		else
		{
			temp[tempIdx++] = danji_nums[rightIdx++];
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = danji_nums[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = danji_nums[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		danji_nums[left + i] = temp[i];
	}
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (right + left) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

void Dfs(int y, int x, int N, int danji_nums_len)
{
	if (x < 0 || y < 0 | x >= N || y >= N)
		return;
	if (map[y][x] == 0)
		return;
	if (visited[y][x] == true)
		return;
	visited[y][x] = true;
	++danji_nums[danji_nums_len];
	Dfs(y, x + 1, N, danji_nums_len);
	Dfs(y + 1, x, N, danji_nums_len);
	Dfs(y, x - 1, N, danji_nums_len);
	Dfs(y - 1, x, N, danji_nums_len);
}

void DfsAll(int N)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (map[y][x] == 0)
				continue;
			if (visited[y][x] == true)
				continue;
			Dfs(y, x, N, danji_nums_len);
			++danji_nums_len;
		}
	}
}

void SetMap(int N)
{
	char* temp_str = (char*)malloc(sizeof(char) * 25);
	for (int y = 0; y < N; ++y)
	{	
		scanf("%s", temp_str);
		int temp_str_len = strlen(temp_str);

		for (int x = 0; x < temp_str_len; ++x)
			map[y][x] = temp_str[x] - '0';
	}
	free(temp_str);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	SetMap(N);
	DfsAll(N);

	printf("%d\n", danji_nums_len);
	MergeSort(0, danji_nums_len - 1);
	for (int i = 0; i < danji_nums_len; ++i)
		printf("%d\n", danji_nums[i]);
	return 0;
}