#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long nums[101] = { 0, };

int main(void)
{
	nums[1] = 1;
	nums[2] = 1;
	nums[3] = 1;
	nums[4] = 2;
	nums[5] = 2;
	for (int i = 6; i <= 100; ++i)
		nums[i] = nums[i - 1] + nums[i - 5];
	int T, N;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		scanf("%d", &N);
		printf("%lld\n", nums[N]);
	}
	return 0;
}