#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int compare(const void* str1, const void* str2) 
{
	int str1_len = strlen(*(char**)str1);
	int str2_len = strlen(*(char**)str2);
	if (str1_len > str2_len) 
		return 1;
	else if (str1_len < str2_len) 
		return -1;
	else 
		return strcmp(*(char**)str1, *(char**)str2);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	char** strs = (char**)malloc(sizeof(char*) * (N + 1));
	for (int i = 0; i < N; ++i)
	{
		strs[i] = (char*)malloc(sizeof(char) * 51);
		scanf("%s", strs[i]);
	}
	
	
	qsort(strs, N, sizeof(char*), compare);
	for (int i = 0; i < N - 1; ++i)
	{
		if (strcmp(strs[i], strs[i + 1]) != 0)
		{
			printf("%s\n", strs[i]);
		}
	}
	printf("%s\n", strs[N - 1]);

	for (int i = 0; i < N; ++i)
	{
		strs[i] = NULL;
		free(strs[i]);
	}
	strs = NULL;
	free(strs);
	return 0;
}