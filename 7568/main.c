#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _PERSON
{
	int _weight;
	int _height;
	int _rank;
} Person;

Person people[51];

void SetPeople(int n)
{
	for (int i = 0; i < n; ++i)
	{
		int weight, height;
		scanf("%d%d", &weight, &height);
		people[i]._height = height;
		people[i]._weight = weight;
		people[i]._rank = 0;
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	SetPeople(n);


	for (int i = 0; i < n; ++i)
	{
		int betterThanMeNum = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			else
			{
				if ((people[i]._weight < people[j]._weight) && (people[i]._height < people[j]._height))
				{
					betterThanMeNum++;
				}
			}
		}
		people[i]._rank = betterThanMeNum + 1;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", people[i]._rank);
	}

	return 0;
}