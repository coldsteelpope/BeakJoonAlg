#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_FUNC(x, y) ((x > y) ? (x) : (y))
#define MIN_FUNC(x, y) ((x < y) ? (x) : (y))
#define INF (~0U >> 2)


int max_map[2][3] = { 0, };
int min_map[2][3] = { 0, };

int main(void)
{
	int N;
	scanf("%d", &N);

	int a1, a2, a3;
	int k = 0;

	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d%d", &a1, &a2, &a3);

		max_map[k][0] = MAX_FUNC(max_map[1 - k][0], max_map[1 - k][1]) + a1;
		max_map[k][1] = MAX_FUNC(max_map[1 - k][0], (MAX_FUNC(max_map[1 - k][1], max_map[1 - k][2]))) + a2;
		max_map[k][2] = MAX_FUNC(max_map[1 - k][1], max_map[1 - k][2]) + a3;

		min_map[k][0] = MIN_FUNC(min_map[1 - k][0], min_map[1 - k][1]) + a1;
		min_map[k][1] = MIN_FUNC(min_map[1 - k][0], (MIN_FUNC(min_map[1 - k][1], min_map[1 - k][2]))) + a2;
		min_map[k][2] = MIN_FUNC(min_map[1 - k][1], min_map[1 - k][2]) + a3;

		k = (k == 1) ? 0 : 1;
	}

	int max_value = 0;
	int min_value = INF;
	
	for (int j = 0; j < 3; ++j)
	{
		max_value = (max_value > max_map[1 - k][j]) ? max_value : max_map[1 - k][j];
		min_value = (min_value > min_map[1 - k][j]) ? min_map[1 - k][j] : min_value;
	}

	printf("%d %d", max_value, min_value);
	return 0;
}