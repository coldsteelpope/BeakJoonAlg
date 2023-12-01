#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1000001

int arr[MAX_LEN] = { 0, };
int dp[MAX_LEN] = { 0, };

int BinarySearchLowerBound(int left, int right, int value)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (dp[mid] >= value)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; ++n)
	{
		scanf("%d", &arr[n]);
	}

	int answer = 1;
	dp[0] = arr[0];
	int dpLen = 1;
	for (int i = 1; i < N; ++i)
	{
		int currentValue = arr[i];
		int dpIdx = BinarySearchLowerBound(0, dpLen, currentValue);
		
		// 나는 dpIdx를 구한 후에 currentValue와 dp[dpIdx]를 비교했다.
		
		// 하지만, 풀이 과정에서는 dp에서 가장 마지막 수랑 currentValue를 비교한 후에
		// 만약 가장 마지막 수보다 currentValue가 더 작을 때, Binary Search를 사용했다.
		// 이러한 방식을 사용하면 불필요한 Binary Search를 사용하지 않기 때문에 더 효과적이다.
		if (dp[dpIdx] < currentValue)
		{
			dp[dpLen++] = currentValue;
		}
		else
		{
			dp[dpIdx] = currentValue;
		}
	}

	printf("%d\n", dpLen);
	return 0;
}