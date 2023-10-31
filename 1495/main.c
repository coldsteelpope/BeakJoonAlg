#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int V[51] = { 0, };
int dp[51] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

void InitDP(int N)
{
	for (int i = 0; i < 51; ++i)
		dp[i] = -1;
}

void SetDP(int dp_index, int sound, int max_sound, int N)
{
	if (sound > max_sound)
		return;
	if (sound < 0)
		return;
	
	

	if (dp_index == N)
	{
		dp[dp_index] = GetMax(dp[dp_index], sound);
		return;
	}
	else
	{
		dp[dp_index] = sound;
		int current_sound = dp[dp_index];

		SetDP(dp_index + 1, current_sound + V[dp_index], max_sound, N);
		SetDP(dp_index + 1, current_sound - V[dp_index], max_sound, N);
	}
}

int main(void)
{
	int N, S, M;
	scanf("%d%d%d", &N, &S, &M);

	for (int i = 0; i < N; ++i)
		scanf("%d", &V[i]);

	InitDP(N);

	int current_sound = S;
	dp[0] = current_sound;

	SetDP(1, current_sound + V[0], M, N);
	SetDP(1, current_sound - V[0], M, N);

	printf("%d", dp[N]);
	return 0;
}

