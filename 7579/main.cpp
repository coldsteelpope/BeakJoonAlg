#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

#define INF 1000000000

using namespace std;


int dp[100001][101] = { 0, };
int processes[101] = { 0, };
int costs[101] = { 0, };

inline int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	

	for (int n = 1; n <= N; ++n)
	{
		cin >> processes[n];
	}

	for (int n = 1; n <= N; ++n)
	{
		cin >> costs[n];
	}

	int result = INF;
	for (int processIdx = 1; processIdx <= N; ++processIdx)
	{
		int currentProcessMemory = processes[processIdx];
		int currentProcessCost = costs[processIdx];

		for (int limitCost = 0; limitCost <= 100000; ++limitCost)
		{
			if (limitCost < currentProcessCost)
				dp[limitCost][processIdx] = dp[limitCost][processIdx - 1];
			else
				dp[limitCost][processIdx] = GetMax(dp[limitCost][processIdx - 1], dp[limitCost - currentProcessCost][processIdx - 1] + currentProcessMemory);

			if (dp[limitCost][processIdx] >= M)
				result = (result > limitCost) ? limitCost : result;
		}
	}
	
	cout << result << endl;
	return 0;
}