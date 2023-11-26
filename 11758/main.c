#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	long long int _x;
	long long int _y;
} Node;

Node nodes[3] = { 0, };

int main(void)
{
	for (int i = 0; i < 3; ++i)
	{
		scanf("%lld%lld", &nodes[i]._x, &nodes[i]._y);
	}

	// 외적을 사용해 방향을 구하는 문제 (CCW)
	long long int crossProductResult = ((nodes[1]._x - nodes[0]._x) * (nodes[2]._y - nodes[1]._y)) - ((nodes[2]._x - nodes[1]._x) * (nodes[1]._y - nodes[0]._y));
	if (crossProductResult < 0)
	{
		printf("%d\n", -1);
	}
	else if (crossProductResult == 0)
	{
		printf("%d\n", 0);
	}
	else
	{
		printf("%d\n", 1);
	}
	return 0;
}