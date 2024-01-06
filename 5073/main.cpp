#include <iostream>

using namespace std;

inline int GetMax(int a, int b, int c)
{
	int maxLen = a > b ? a : b;
	maxLen = maxLen > c ? maxLen : c;
	return maxLen;
}

inline int GetSum(int maxValue, int a, int b, int c)
{
	int sum = 0;
	if (maxValue == a)
	{
		return b + c;
	}
	else if (maxValue == b)
	{
		return a + c;
	}
	else
	{
		return a + b;
	}
}

int main(void)
{
	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) 
		{
			break;
		}
		
		if (a == b && b == c)
		{
			cout << "Equilateral" << "\n";
		}
		else
		{
			int maxLen = GetMax(a, b, c);
			int sum = GetSum(maxLen, a, b, c);

			if (maxLen < sum)
			{
				if (a == b || b == c || a == c)
				{
					cout << "Isosceles" << "\n";
				}
				else
				{
					cout << "Scalene" << "\n";
				}
			}
			else
			{
				cout << "Invalid" << "\n";
			}
		}
	}
}