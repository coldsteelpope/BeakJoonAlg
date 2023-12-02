#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int GetSquared(int num)
{
	return num * num;
}

int GetLen(int x1, int x2, int y1, int y2)
{
	return GetSquared(x1 - x2) + GetSquared(y1 - y2);
}

int Solution()
{
	int startX, startY, targetX, targetY;
	scanf("%d%d%d%d", &startX, &startY, &targetX, &targetY);
	
	int answer = 0;
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; ++n)
	{
		int circleX, circleY, radius;
		scanf("%d%d%d", &circleX, &circleY, &radius);
		
		int startLen = GetLen(startX, circleX, startY, circleY);
		int targetLen = GetLen(targetX, circleX, targetY, circleY);

		// 두 점이 모두 원 안에 있으면 count X
		if (startLen < GetSquared(radius) && targetLen < GetSquared(radius))
		{
			continue;
		}
		else
		{
			if (startLen < GetSquared(radius))
			{
				++answer;
			}
			if (targetLen < GetSquared(radius))
			{
				++answer;
			}
		}
	}
	return answer;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; ++testCase)
	{
		int result = Solution();
		printf("%d\n", result);
	}
	return 0;
}