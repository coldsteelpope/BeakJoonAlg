// ������ȸ�� ������ȸ���� root node�� ã�Ƴ��� ����� �˾Ƴ´�.
// �ٸ�, sub left root node, sub right root node�� ã�Ƴ��� ����� ���� ���ߴ�.
// ���� sub left root node�� sub right root node�� Ȱ���� ���� ��ȸ�ϴ� ������� ���� ���ߴ�.
// ���� ���� ��ȸ�� �� �������� ���� ſ�ϱ�...?

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1001

int g_preOrder[MAX_LEN] = { 0, };
int g_inOrder[MAX_LEN] = { 0, };


void Solution(int rootNodeIdx, int startNodeIdx, int endNodeIdx)
{
	for (int i = startNodeIdx; i < endNodeIdx; ++i)
	{
		if (g_preOrder[rootNodeIdx] == g_inOrder[i])
		{
			Solution(rootNodeIdx + 1, startNodeIdx, i); // Left Sub Tree
			Solution(rootNodeIdx + (i - startNodeIdx) + 1, i + 1, endNodeIdx); // right Sub Tree
			printf("%d ", g_inOrder[i]);
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; ++testCase)
	{
		int N;
		scanf("%d", &N);

		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &g_preOrder[i]);
		}

		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &g_inOrder[i]);
		}

		Solution(0, 0, N);
		printf("\n");
	}
	return 0;
}