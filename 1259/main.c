#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int num = 0;
	while (1)
	{
		scanf("%d", &num);
		fflush(stdin);

		if (num == 0)
			break;

		int tmp_num = num;
		int num_digit = 0;
		while (tmp_num != 0)
		{
			num_digit += 1;
			tmp_num /= 10;
		}
		
		int* num_q = (int*)malloc(sizeof(int) * num_digit);
		int head = 0;
		int rear = 0;

		while (num != 0)
		{
			num_q[rear++] = num % 10;
			num /= 10;
		}


		bool isPalindrome = true;
		rear--;
		for (int t = 0; t < (num_digit / 2); ++t)
		{
			int head_num = num_q[head++];
			int rear_num = num_q[rear--];

			if (head_num != rear_num)
			{
				isPalindrome = false;
				break;
			}
		}

		if (isPalindrome)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}