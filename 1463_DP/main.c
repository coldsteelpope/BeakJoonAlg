#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int num[1000001] = { 0, };

int main(void)
{
	int N;
	scanf("%d", &N);
	
	num[0] = 0;
	num[1] = 0;
	num[2] = 1;
	num[3] = 1;

	for (int current_num = 4; current_num <= N; ++current_num)
	{
		num[current_num] = num[current_num - 1] + 1;
		
		if (current_num % 6 == 0 || current_num % 2 == 0)
		{
			int candidate_t_num = num[current_num / 2] + 1;
			num[current_num] = (candidate_t_num > num[current_num]) ? num[current_num] : candidate_t_num;
		}
		//if (current_num % 2 == 0)
		//{
		//	int candidate_t_num = num[current_num / 2] + 1;
		//	num[current_num] = (candidate_t_num > num[current_num]) ? num[current_num] : candidate_t_num;
		//}
		if (current_num % 3 == 0)
		{
			int candidate_t_num = num[current_num / 3] + 1;
			num[current_num] = (candidate_t_num > num[current_num]) ? num[current_num] : candidate_t_num;
		}
	}
	printf("%d", num[N]);
	return 0;
}