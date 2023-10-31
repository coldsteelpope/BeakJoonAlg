#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (a < b)
		swap(a, b);

	if (a % b == 0)
	{
		return b;
	}
	else if (a % b == 1)
	{
		return 1;
	}
	else
	{
		while (1)
		{
			int r = a % b;
			a = b;
			b = r;
			if (r == 0)
				break;
		}
		return a;
	}
}

int lcm(int a, int b)
{
	return (abs(a * b)) / gcd(a, b);
}

int main(void)
{
	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; ++t)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		
		bool is_existed = false;
		int max_year = lcm(M, N);
		int find_year = 0;
		
		for (int year = x; year <= max_year; year += M)
		{
			int remainder_y = ((year % N) == 0) ? N : (year % N);
			if (remainder_y == y)
			{
				is_existed = true;
				find_year = year;
				break;
			}
		}

		if (is_existed)
			cout << find_year << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}