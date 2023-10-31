#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
	char str[51] = { 0, };
	scanf("%s", str);

	char strs[51][51] = { 0, };
	int strsLen = 0;

	char* token = strtok(str, "-");
	while (token != NULL)
	{
		strcpy(strs[strsLen], token);
		token = strtok(NULL, "-");
		++strsLen;
	}


	long long sum = 0;
	for (int i = 0; i < strsLen; ++i)
	{
		char temp[51] = { 0, };
		strcpy(temp, strs[i]);
		long long sum_part = 0;

		char* token = strtok(temp, "+");
		while (token != NULL)
		{
			sum_part += atoi(token);
			token = strtok(NULL, "+");
		}

		if (i == 0)
			sum += sum_part;
		else
			sum -= sum_part;
	}

	printf("%lld\n", sum);
	return 0;
}