#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



int main(void)
{
	int N;
	scanf("%d", &N);
	
	if (N >= 1 && N <= 1000000)
	{
		int tmpN = N;
		int digit = 0;
		while (tmpN != 0)
		{
			digit++;
			tmpN /= 10;
		}
		long int answer = -1;
		long int minN = N - (9 * digit);

		char num[1000001] = { 0, };

		for (long int candidate_num = minN; candidate_num <= N; ++candidate_num)
		{
			long int sum = candidate_num;
			sprintf(num, "%ld", candidate_num);
			for (int num_i = 0; num_i < strlen(num); ++num_i)
			{
				sum += (num[num_i] - '0');
			}
			if (sum == N)
			{
				answer = candidate_num;
				break;
			}
		}

		printf("%ld", answer);
	}

	return 0;
}