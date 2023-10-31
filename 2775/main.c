#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOOR	15
#define MAX_HO		15

int apartment[MAX_FLOOR][MAX_HO] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

int main(void)
{
	for (int k = 1; k < MAX_FLOOR; ++k)
	{
		for (int n = 0; n < MAX_HO; ++n)
		{
			for (int a = 0; a <= n; ++a)
			{
				apartment[k][n] += apartment[k - 1][a];
			}
		}
	}
	
	int testCaseNum = 0;
	scanf("%d", &testCaseNum);
	
	for (int i = 0; i < testCaseNum; ++i)
	{
		int k, n;
		scanf("%d%d", &k, &n);
		printf("%d\n", apartment[k][n - 1]);
	}
	return 0;
}