#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main(void)
{
	int N;
	scanf("%d", &N);

	int num_count[10001] = { 0, };

	int num_count_index = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &num_count_index);
		num_count[num_count_index] += 1;
	}
	
	for (int i = 1; i < 10001; ++i)
	{
		if (num_count[i] != 0)
		{
			for (int j = 1; j <= num_count[i]; ++j)
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}