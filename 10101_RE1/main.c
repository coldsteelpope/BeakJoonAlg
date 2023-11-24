#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	if (a + b + c == 180)
	{
		if (a == b && b == c)
		{
			printf("Equilateral\n");
		}
		else if (a != b && b != c && a != c)
		{
			printf("Scalene\n");
		}
		else
		{
			printf("Isosceles\n");
		}
	}
	else
	{
		printf("Error\n");
	}
	return 0;
}