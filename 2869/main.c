#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	long int A, B, V;
	scanf("%ld%ld%ld", &A, &B, &V);
	
	long int day = (V - B) / (A - B);
	long int remainder = (V - B) % (A - B);
	
	day = (remainder != 0) ? day + 1 : day;

	printf("%ld\n", day);
	return 0;
}