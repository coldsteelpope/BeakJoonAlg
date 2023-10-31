#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int map[1001][1001] = { 0, };
char str1[1001] = { 0, };
char str2[1001] = { 0, };

int LCS(int len_y, int len_x)
{
	for (int i = 0; i <= len_y; ++i)
		map[i][0] = 0;
	for (int j = 0; j <= len_x; ++j)
		map[0][j] = 0;

	for (int i = 1; i <= len_y; ++i)
	{
		for (int j = 1; j <= len_x; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				map[i][j] = map[i - 1][j - 1] + 1;
			}
			else
			{
				if (map[i][j - 1] >= map[i - 1][j])
					map[i][j] = map[i][j - 1];
				else
					map[i][j] = map[i - 1][j];
			}
		}
	}
	return map[len_y][len_x];
}


int main(void)
{
	scanf("%s%s", str1, str2);
	
	int len_y = strlen(str1);
	int len_x = strlen(str2);

	printf("%d", LCS(len_y, len_x));

	return 0;
}