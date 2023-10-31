#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char operator_stack[101] = { 0, };
char result_stack[101] = { 0, };

int operator_stack_pointer = 0;
int result_stack_pointer = 0;

int GetRank(char op)
{
	if (op == '(' || op == ')')
		return 3;
	else
		return (op == '*' || op == '/') ? 1 : 2;
}

int main(void)
{
	char eq[101];
	scanf("%s", eq);
	int eq_pointer = 0;
	
	while (eq[eq_pointer] != '\0')
	{
		if 
		(
			eq[eq_pointer] == '+' ||
			eq[eq_pointer] == '-' ||
			eq[eq_pointer] == '*' ||
			eq[eq_pointer] == '/' ||
			eq[eq_pointer] == '(' ||
			eq[eq_pointer] == ')'
		)
		{
			if ((operator_stack_pointer == 0 || eq[eq_pointer] == '(') && eq[eq_pointer] != ')')
			{
				operator_stack[operator_stack_pointer++] = eq[eq_pointer++];
			}
			else if (eq[eq_pointer] == ')')
			{
				while (operator_stack_pointer != 0)
				{
					char top_operator = operator_stack[operator_stack_pointer - 1];
					if (top_operator == '(')
					{
						--operator_stack_pointer;
						break;
					}
					else
					{
						result_stack[result_stack_pointer++] = top_operator;
						--operator_stack_pointer;
					}
				}
				++eq_pointer;
			}
			else
			{
				char current_operator = eq[eq_pointer];
				char top_operator = operator_stack[operator_stack_pointer - 1];
				
				int current_operator_rank = GetRank(current_operator);
				int top_operator_rank = GetRank(top_operator);

				if (current_operator_rank < top_operator_rank)
				{
					operator_stack[operator_stack_pointer++] = current_operator;
					++eq_pointer;
				}
				else
				{
					while (operator_stack_pointer != 0)
					{
						top_operator = operator_stack[operator_stack_pointer - 1];
						top_operator_rank = GetRank(top_operator);
						if (top_operator == '(' || (current_operator_rank < top_operator_rank))
						{
							break;
						}
						else
						{
							result_stack[result_stack_pointer++] = top_operator;
							--operator_stack_pointer;
						}
					}
					operator_stack[operator_stack_pointer++] = current_operator;
					++eq_pointer;
				}
			}
		}
		else
		{
			result_stack[result_stack_pointer++] = eq[eq_pointer++];
		}
	}

	while (operator_stack_pointer != 0)
	{
		result_stack[result_stack_pointer++] = operator_stack[--operator_stack_pointer];
	}
	
	result_stack[result_stack_pointer] = '\0';
	printf("%s", result_stack);
	return 0;
}