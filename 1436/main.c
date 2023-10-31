#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int count = 0;

	int stack[100] = { 0 };
	int stack_pointer = 0;
	
	long long num = 665;
	while (1)
	{
		long long temp = num;
		while (temp != 0)
		{
			int remainder = temp % 10;
			stack[stack_pointer++] = remainder;
			temp /= 10;
		}

		bool sequenced_six = false;
		int sequenced_six_num = 0;
		for (int i = stack_pointer - 1; i >= 0; --i)
		{
			if (stack[i] == 6)
			{
				sequenced_six = true;
				++sequenced_six_num;

				if (sequenced_six_num == 3)
					break;
			}
			else
			{
				sequenced_six = false;
				sequenced_six_num = 0;
			}
		}

		if (sequenced_six && sequenced_six_num >= 3) 
			++count;
		if (count == N)
			break;
		stack_pointer = 0;
		num++;
	}
	printf("%d", num);
	return 0;
}