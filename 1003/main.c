#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int one_nums[41];
int zero_nums[41];

int main(void)
{
	one_nums[0] = 0;
	zero_nums[0] = 1;
	
	one_nums[1] = 1;
	zero_nums[1] = 0;
	
	one_nums[2] = 1;
	zero_nums[2] = 1;
	
	zero_nums[3] = 1;
	for (int one_nums_index = 3; one_nums_index <= 40; ++one_nums_index)
	{
		one_nums[one_nums_index] = one_nums[one_nums_index - 1] + one_nums[one_nums_index - 2];
	}

	for (int zero_nums_index = 4; zero_nums_index <= 40; ++zero_nums_index)
	{
		zero_nums[zero_nums_index] = zero_nums[zero_nums_index - 1] + zero_nums[zero_nums_index - 2];
	}
	
	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; ++i)
	{
		int num_index = 0;
		scanf("%d", &num_index);
		printf("%d %d\n", zero_nums[num_index], one_nums[num_index]);
	}
	return 0;
}