#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

stack<int> s;

int main(void)
{
	int N;
	scanf("%d", &N);

	
	for (int i = 0; i < N; ++i)
	{
		int command;
		scanf("%d", &command);

		switch (command)
		{
		case 1:
			int number;
			scanf("%d", &number);
			s.push(number);
			break;
		case 2:
			if (s.size() == 0)
				printf("-1\n");
			else
			{
				printf("%d\n", s.top());
				s.pop();
			}
			break;
		case 3:
			printf("%d\n", s.size());
			break;
		case 4:
			if (s.empty() == false)
				printf("0\n");
			else
				printf("1\n");
			break;
		case 5:
			if (s.empty())
				printf("-1\n");
			else
				printf("%d\n", s.top());
			break;
		}
	}

	return 0;
}