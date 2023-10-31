#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <memory.h>

int num[50001];

int main(void)
{
	int n;
	scanf("%d", &n);
	
	num[0] = 0;
	num[1] = 1;
	for (int i = 0; i < 50001; ++i)
		num[i] = 4;

	for (int current_num = 1; current_num <= n; ++current_num)
	{
		double d_sqrt_current_num = sqrt(current_num);
		if (d_sqrt_current_num == (int)d_sqrt_current_num)
		{
			num[current_num] = 1;
		}
		else
		{
			for (int j = 1; j * j <= current_num; ++j)
			{
				num[current_num] = ((num[j * j] + num[current_num - j * j]) > num[current_num]) ? num[current_num] : (num[j * j] + num[current_num - j * j]);
			}
		}
	}
	printf("%d", num[n]);
	return 0;
}