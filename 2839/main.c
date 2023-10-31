#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[5001] = { -1, -1, -1, 1, -1, 1 };

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 6; i <= N; ++i)
	{
		int temp = i;
		temp -= 5;
		if (arr[temp] != -1)
			arr[i] = arr[temp] + 1;
		else
		{
			if (i % 3 == 0)
				arr[i] = i / 3;
			else
				arr[i] = -1;
		}
	}
	printf("%d", arr[N]);
	return 0;
}