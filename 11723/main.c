#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int set[20] = { 0, };

int main(void)
{
	int M;
	scanf("%d", &M);
	
	char instruction[7];
	int x;
	int flag = 0;

	for (int i_num = 0; i_num < M; ++i_num)
	{
		scanf("%s%d", instruction, &x);

		if (strcmp(instruction, "add") == 0)
		{
			flag |= (1 << x);
		}
		else if (strcmp(instruction, "remove") == 0)
		{
			flag &= ~(1 << x);
		}
		else if (strcmp(instruction, "check") == 0)
		{
			int result = flag & (1 << x);
			if (result != 0)
				printf("%d\n", 1);
			else
				printf("%d\n", 0);
		}
		else if (strcmp(instruction, "toggle") == 0)
		{
			flag ^= (1 << x);
		}
		else if (strcmp(instruction, "all") == 0)
		{
			flag |= (1 << 21) - 1;
		}
		else if (strcmp(instruction, "empty") == 0)
		{
			flag &= 0;
		}
	}
	return 0;
}