#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ������ Ǯ ��, if, else���� ���� ���̱�
int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	
	if (a == 60 && b == 60 && c == 60)
	{
		printf("Equilateral\n");
	}
	else if ((a + b + c == 180) && ((a != b) && (b != c) && (a != c)))
	{
		printf("Scalene\n");
	}
	else if ((a + b + c == 180) && ((a == b) || (b == c) || (a == c)))
	{
		printf("Isosceles\n");
	}
	else if ((a + b + c != 180))
	{
		printf("Error\n");
	}
	return 0;
}