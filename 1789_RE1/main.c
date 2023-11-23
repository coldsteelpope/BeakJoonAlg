#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	long long int S;
	scanf("%lld", &S);
	
	long long int num = 1;
	long long int answer = 0;
	while (num <= S)
	{
		S = S - num;
		++answer;
		++num;
	}
	printf("%lld\n", answer);
	return 0;
}