#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _PERSON
{
	int _age;
	char _name[201];
} Person;

int main(void)
{
	int N;
	scanf("%d", &N);
	fflush(stdin);

	Person* people = (Person*)malloc(sizeof(Person) * N);
	for (int people_index = 0; people_index < N; ++people_index)
	{
		scanf("%d%s", &people[people_index]._age, people[people_index]._name);
		fflush(stdin);
	}

	for (int age = 1; age <= 200; ++age)
	{
		for (int people_index = 0; people_index < N; ++people_index)
		{
			if (people[people_index]._age == age)
			{
				printf("%d %s\n", people[people_index]._age, people[people_index]._name);
			}
		}
	}
	return 0;
}