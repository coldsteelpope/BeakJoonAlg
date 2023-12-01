#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1001
char str[MAX_LEN] = { 0, };

int GetStrLen()
{
	int len = 0;
	while (str[len] != '\0')
	{
		++len;
	}
	return len;
}

int main(void)
{
	scanf("%s", str);
	char corrects[5] = { 'K', 'O', 'R','E','A' };
	int answer = 0;
	int correctsPointer = 0;
	int strLen = GetStrLen();
	for (int strPointer = 0; strPointer < strLen; ++strPointer)
	{
		if (str[strPointer] == corrects[correctsPointer])
		{
			++answer;
			correctsPointer = (correctsPointer + 1) % 5;
		}
	}
	printf("%d\n", answer);
	return 0;
}