#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _SCHEDULE
{
	int _t;
	int _p;
} Schedule;

Schedule schedulers[20] = { 0, };
int dp[20] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int day = 1; day <= N; ++day)
	{
		int t, p;
		scanf("%d%d", &t, &p);
		schedulers[day]._t = t;
		schedulers[day]._p = p;
	}
	
	for (int start_date = 1; start_date <= N; ++start_date)
	{
		int start_date_t = schedulers[start_date]._t;
		int start_date_p = schedulers[start_date]._p;

		for (int p_date = start_date + start_date_t; p_date <= N + 1; ++p_date)
		{
			dp[p_date] = GetMax(dp[p_date], dp[start_date] + start_date_p);
		}
	}
	printf("%d", dp[N + 1]);
	return 0;
}