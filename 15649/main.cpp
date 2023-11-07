#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int selectedNums[10] = { 0, };
bool selected[10] = { 0, };

void Solution(int N, int M, int index)
{
	if (index == M)
	{
		for (int i = 0; i < index; ++i)
			printf("%d ", selectedNums[i]);
		printf("\n");
		return;
	}
	else
	{
		for (int num = 1; num <= N; ++num)
		{
			if (selected[num] == true)
				continue;
			selected[num] = true;
			selectedNums[index] = num;
			Solution(N, M, index + 1);
			selected[num] = false;
		}
	}
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	Solution(N, M, 0);
	return 0;
}