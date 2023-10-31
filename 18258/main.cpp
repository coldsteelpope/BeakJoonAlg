#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

queue<int> q;

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		char command[8] = { 0, };
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			int number;
			scanf("%d", &number);
			q.push(number);
		}
		else if (strcmp(command, "pop") == 0)
		{
			if (q.empty() == true)
			{
				printf("%d\n", -1);
			}
			else
			{
				int topValue = q.front();
				q.pop();
				printf("%d\n", topValue);
			}
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", q.size());
		}
		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", (q.empty() == true) ? 1 : 0);
		}
		else if (strcmp(command, "front") == 0)
		{
			printf("%d\n", (q.empty() == true) ? -1 : q.front());
		}
		else if (strcmp(command, "back") == 0)
		{
			printf("%d\n", (q.empty() == true) ? -1 : q.back());
		}
	}
	return 0;
}