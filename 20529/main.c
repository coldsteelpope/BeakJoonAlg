#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char FRIENDS_MBTI[100000][5];
char COMBI_FRIENDS_MBTI[100000][5];
char RESULT_MBTI[2][5];

int MIN_VAL = 2147483647;
int FRIENDS_MBTI_LEN = 0;

int GetPsychologicalDistance(char* m1, char* m2)
{
	int psychologicalDistance = 0;
	if (m1[0] != m2[0])
		++psychologicalDistance;
	if (m1[1] != m2[1])
		++psychologicalDistance;
	if (m1[2] != m2[2])
		++psychologicalDistance;
	if (m1[3] != m2[3])
		++psychologicalDistance;
	return psychologicalDistance;
}

void final_combination(int n, int r, int* distance)
{
	if (r == 0)
	{
		(*distance) += GetPsychologicalDistance(RESULT_MBTI[0], RESULT_MBTI[1]);
		return;
	}
	else if (n < r)
	{
		return;
	}
	else
	{
		strcpy(RESULT_MBTI[r - 1], COMBI_FRIENDS_MBTI[n - 1]);
		final_combination(n - 1, r - 1, distance);
		final_combination(n - 1, r, distance);
	}
}

void combination(int n, int r, int pure_r)
{
	if (r == 0)
	{
		int final_n = pure_r;
		int final_r = 2;
		int final_distance = 0;
		final_combination(final_n, final_r, &final_distance);
		MIN_VAL = (MIN_VAL > final_distance) ? final_distance : MIN_VAL;
	}
	else if (n < r)
	{
		return;
	}
	else
	{
		strcpy(COMBI_FRIENDS_MBTI[r - 1], FRIENDS_MBTI[n - 1]);
		combination(n - 1, r - 1, pure_r);
		combination(n - 1, r, pure_r);
	}
}

int main(void)
{
	int testcase = 0;
	scanf("%d", &testcase);

	for (int t = 0; t < testcase; ++t)
	{
		scanf("%d", &FRIENDS_MBTI_LEN);
		if (FRIENDS_MBTI_LEN < 33)
		{
			for (int i = 0; i < FRIENDS_MBTI_LEN; ++i)
				scanf("%s", FRIENDS_MBTI[i]);

			int n = FRIENDS_MBTI_LEN; int r = 3;
			combination(n, r, r);
			printf("%d\n", MIN_VAL);
			MIN_VAL = 2147483647;
		}
		else
		{
			printf("0\n");
		}
	}
	
	return 0;
}