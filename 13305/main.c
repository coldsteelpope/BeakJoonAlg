#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long nodes[100001] = { 0, };
long long edges[100001] = { 0, };

int main(void)
{
	long long N;
	scanf("%lld", &N);

	for (long long i = 0; i < N - 1; ++i)
		scanf("%lld", &edges[i]);

	for (long long i = 0; i < N; ++i)
		scanf("%lld", &nodes[i]);

	long long current_cost = 0;
	long long current_node = nodes[0];
	long long pathLen = 0;

	for (long long i = 1; i < N; ++i)
	{
		if (current_node > nodes[i] || i == N - 1)
		{
			pathLen += edges[i - 1];
			current_cost += (pathLen * current_node);
			pathLen = 0;
			current_node = nodes[i];
		}
		else
		{
			pathLen += edges[i - 1];
		}
	}

	printf("%lld", current_cost);
	return 0;
}