#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[21] = { 0, };
bool visited[21] = { 0, };

int answer = 0;

void DFS(int count, int maxCount ,int N, int S, int sum, int startIdx)
{
	if (count == maxCount)
	{
		if (sum == S)
		{
			++answer;
		}
	}
	else
	{
		for (int i = startIdx; i < N; ++i)
		{
			if (visited[i] == true)
				continue;
			visited[i] = true;
			DFS(count + 1, maxCount, N, S, sum + arr[i], i + 1);
			visited[i] = false;
		}
	}
}

int main(void)
{
	int N, S;
	scanf("%d%d", &N, &S);
	for (int n = 0; n < N; ++n)
	{
		scanf("%d", &arr[n]);
	}

	for (int maxCount = 1; maxCount <= N; ++maxCount)
	{
		DFS(0, maxCount, N, S, 0, 0);
	}
	
	printf("%d\n", answer);
	return 0;
}