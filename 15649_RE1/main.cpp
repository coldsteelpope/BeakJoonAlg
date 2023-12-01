#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int g_selectedNums[10] = { 0, };
bool g_visitedNums[10] = { 0, };

void Solution(int N, int index, int M)
{
	if (index == M)
	{
		for (int i = 0; i < M; ++i)
		{
			printf("%d ", g_selectedNums[i]);
			//cout << g_selectedNums[i] << " ";
		}
		printf("\n");
		//cout << endl;
		return;
	}
	else
	{
		for (int num = 1; num <= N; ++num)
		{
			if (g_visitedNums[num] == true)
			{
				continue;
			}

			g_visitedNums[num] = true;
			g_selectedNums[index] = num;
			Solution(N, index + 1, M);
			g_visitedNums[num] = false;
		}
	}
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	//cin >> N >> M;
	Solution(N, 0, M);
	return 0;
}