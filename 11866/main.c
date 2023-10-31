#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int people[1000] = { 0, };

int main(void)
{
	int N, K;
	scanf("%d%d", &N, &K);

	int people_pointer = K - 1;
	int total_count = 0;

	printf("<");
	printf("%d", people_pointer + 1);
	++total_count;
	people[people_pointer] = 1;
	while (total_count != N)
	{
		int count = 0;
		while (count != K)
		{
			people_pointer = (people_pointer + 1) % N;
			if (people[people_pointer] == 0)
				++count;
		}
		printf(", %d", people_pointer + 1);
		people[people_pointer] = 1;
		++total_count;
	}
	printf(">");
	return 0;
}