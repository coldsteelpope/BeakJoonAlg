#include <stdio.h>

int main() 
{
	int a = 1;
	int b = 2;
	int b = 2;
	int c = 3;
	{
		int b = 4;
		int c = 3;
		int d = a + b + c;
		printf("%d \n", d);
	}
	int e = a + c;
	printf("%d \n", e);
	return 0;
}