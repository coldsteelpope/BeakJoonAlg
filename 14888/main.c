#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_VAL 10000000000
#define MAX_VAL -10000000000

long long numbers[12] = { 0, };

long long max_value = MAX_VAL;
long long min_value = MIN_VAL;

void Calculate(long long idx, long long N, int current_cal, long long result, long long plus_number, long long minus_number, long long mul_number, long long div_number)
{
	switch (current_cal)
	{
	case 0:
		result += numbers[idx];
		break;
	case 1:
		result += numbers[idx];
		break;
	case 2:
		result -= numbers[idx];
		break;
	case 3:
		result *= numbers[idx];
		break;
	case 4:
		result /= numbers[idx];
		break;
	default:
		break;
	}

	if (idx == N)
	{
		max_value = (max_value > result) ? max_value : result;
		min_value = (min_value > result) ? result : min_value;
		return 0;
	}
	else
	{
		if (plus_number != 0)
		{
			Calculate(idx + 1, N, 1, result, plus_number - 1, minus_number, mul_number, div_number);
		}

		if (minus_number != 0)
		{
			Calculate(idx + 1, N, 2, result, plus_number, minus_number - 1, mul_number, div_number);
		}

		if (mul_number != 0)
		{
			Calculate(idx + 1, N, 3, result, plus_number, minus_number, mul_number - 1, div_number);
		}

		if (div_number != 0)
		{
			Calculate(idx + 1, N, 4, result, plus_number, minus_number, mul_number, div_number - 1);
		}
	}
}

int main(void)
{
	long long N, plus_number, minus_number, mul_number, div_number;
	scanf("%lld", &N);
	for (long long i = 0; i < N; ++i)
		scanf("%lld", &numbers[i]);
	scanf("%lld%lld%lld%lld", &plus_number, &minus_number, &mul_number, &div_number);
	Calculate(0, N - 1, 0, 0, plus_number, minus_number, mul_number, div_number);

	printf("%lld\n", max_value);
	printf("%lld", min_value);
	return 0;
}