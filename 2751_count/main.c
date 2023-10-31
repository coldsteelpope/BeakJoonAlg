#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int g_num_set[1000001] = { 0, };
int g_max_val = 0;

int main(void)
{
	int N;
	scanf("%d", &N);
	
	for (int t = 0; t < N; ++t)
	{
		int num_set_index = 0;
		scanf("%d", &num_set_index);
		g_num_set[num_set_index] += 1;
		g_max_val = (num_set_index > g_max_val) ? num_set_index : g_max_val;
	}

	for (int num_set_index = 1; num_set_index <= g_max_val; ++num_set_index)
	{
		if (g_num_set[num_set_index] != 0)
		{
			for (int t = 0; t < g_num_set[num_set_index]; ++t)
			{
				printf("%d\n", num_set_index);
			}
		}
	}
	return 0;
}