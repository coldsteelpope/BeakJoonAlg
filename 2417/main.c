#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

int64_t Solution(int64_t value)
{
	int64_t startPointer = 0;
	int64_t endPointer = (int64_t)sqrt(value);
	int64_t mid;
	while (startPointer <= endPointer)
	{
		mid = (endPointer + startPointer) / 2;
		
		if (mid >= (int64_t)sqrt(value))
		{
			endPointer = mid - 1;
		}
		else
		{
			startPointer = mid + 1;
		}
	}

	if (mid * mid < value)
		mid++;
	return mid;
}

int main(void)
{
	int64_t value;
	scanf("%lld", &value);

	printf("%lld\n", Solution(value));
	
	return 0;
}