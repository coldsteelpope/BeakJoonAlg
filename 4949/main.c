#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char str[100];
char stack[100];
int stack_pointer = 0;

int main(void)
{
	while (1)
	{
		gets(str);
		fflush(stdin);
		if (str[0] == '.')
		{
			break;
		}
		else
		{
			int strLen = strlen(str);
			int strIndex = 0;
			while (str[strIndex] != '.')
			{
				char current_char = str[strIndex];

				if (current_char == '(' || current_char == '[')
				{
					stack[stack_pointer++] = current_char;
				}
				else if (current_char == ')' || current_char == ']')
				{
					if (stack_pointer == 0)
					{
						stack[stack_pointer++] = current_char;
					}
					else
					{
						if (stack[stack_pointer - 1] == '(' && current_char == ')')
						{
							--stack_pointer;
						}
						else if (stack[stack_pointer - 1] == '[' && current_char == ']')
						{
							--stack_pointer;
						}
						else
						{
							stack[stack_pointer++] = current_char;
						}
					}
				}
				strIndex++;
			}

			if (stack_pointer == 0)
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
		memset(stack, 0, 100);
		memset(str, 0, 100);
		stack_pointer = 0;
	}
	return 0;
}