#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int GetStrLen(char* str)
{
	int len = 0;
	while (str[len] != '\0')
		++len;
	return len;
}

int main(void)
{
	char str[101] = { 0, };
	scanf("%s", str);
	
	int strLen = GetStrLen(str);
	bool isPalien = true;
	for (int ptr = 0; ptr < (strLen / 2); ++ptr)
	{
		if (str[ptr] != str[strLen - 1 - ptr])
		{
			isPalien = false;
			break;
		}
	}
	if (isPalien)
		printf("%d\n", 1);
	else
		printf("%d\n", 0);

	return 0;
}