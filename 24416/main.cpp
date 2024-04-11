#include <iostream>

#define MAX_LEN 41
using namespace std;

long long g_llRecursionNumber = 0;

int fibonacciDP(int n);
int fibonacciRecursion(int n);

int main(void)
{
	int iN;
	cin >> iN;
	
	fibonacciRecursion(iN);
	int iDp = fibonacciDP(iN);
	cout << g_llRecursionNumber << " " << iDp << endl;
	
	return 0;
}

int fibonacciRecursion(int n)
{
	if (n == 1 || n == 2)
	{
		++g_llRecursionNumber;
		return 1;
	}
	return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

int fibonacciDP(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	int iResult = 0;
	for (int i = 3; i <= n; ++i)
	{
		++iResult;
	}
	return iResult;
}