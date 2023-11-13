#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
int GetStrLen(char* str)
{
	int index = 0;
	while (str[index] != '\0')
		++index;
	return index;
}
int main(void)
{
	char str[16] = { 0, };
	scanf("%s", str);
	int strLen = GetStrLen(str);
	int answer = 0;
	for (int i = 0; i < strLen; ++i)
	{
		answer += arr[str[i] - 'A'];
	}
	printf("%d\n", answer);
	return 0;
}