#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int stack[1000001] = { 0 };

int main(void)
{
	int stack_pointer = 0;
	int K;
	scanf("%d", &K);

	for (int i = 0; i < K; ++i)
	{
		int num = 0;
		scanf("%d", &num);
		if (num != 0)
			stack[stack_pointer++] = num;
		else
			--stack_pointer;
	}
	
	int answer = 0;
	for (int i = 0; i < stack_pointer; ++i)
		answer += stack[i];
	
	printf("%d", answer);
	return 0;
}