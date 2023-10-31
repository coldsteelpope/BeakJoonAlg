#include <stdio.h>

int arr[5] = { 1,2,3,4,5 };
int A[5] = { 0, };

void combination(int N, int R, int pure_r)
{
	if (R == 0)
	{
		for (int i = pure_r - 1; i >= 0; --i)
		{
			printf("%d\t", A[i]);
		}
		printf("\n");
	}
	else if (N < R)
	{
		// 선택지가 더 이상 존재하지 않을 때
		return;
	}
	else
	{
		A[R - 1] = arr[N - 1];
		combination(N - 1, R - 1, pure_r);
		combination(N - 1, R, pure_r);
	}
	
}

int main(void)
{
	int N = 5;
	int R = 3;
	
	combination(N, R, R);
}