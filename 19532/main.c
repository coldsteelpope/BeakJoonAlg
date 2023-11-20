#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	
	
	bool result = false;
	int answerX = 0;
	int answerY = 0;
	for (int x = -999; x <= 999; ++x)
	{
		for (int y = -999; y <= 999; ++y)
		{
			bool result1 = (a * x + b * y == c);
			bool result2 = (d * x + e * y == f);
			if (result1 == true && result2 == true)
			{
				result = true;
				answerX = x;
				answerY = y;
				break;
			}
		}
		if (result == true)
		{
			break;
		}
	}
	printf("%d %d", answerX, answerY);
	return 0;
}