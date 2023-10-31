#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long M = 1234567891;

int main(void)
{
	int L;
	char str[50];
	
	scanf("%d", &L);
	scanf("%s", str);

	long long answer = 0;
	for (int str_index = 0; str_index < L; ++str_index)
	{
		long long current_char_num = str[str_index] - 96;
		for (int t = 0; t < str_index; ++t)
		{
			current_char_num = (current_char_num * 31) % 1234567891;
		}
		answer = (answer + current_char_num) % M;
	}

	printf("%lld", answer);
	return 0;
}