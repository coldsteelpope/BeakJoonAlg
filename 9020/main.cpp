#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;

int GetAbs(int num)
{
	return num > 0 ? num : -num;
}

int GetLen(int num1, int num2)
{
	return GetAbs(num1 - num2);
}

void SwapNode(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void Solution()
{
	int n;
	cin >> n;
	visited.resize(n + 1, false);

	visited[0] = visited[1] = true;
	for (int num = 2; num * num <= n; ++num)
	{
		if (visited[num] == false)
		{
			for (int mul = num + num; mul <= n; mul += num)
			{
				visited[mul] = true;
			}
		}
	}

	vector<int> primes;
	for (int num = 2; num <= n; ++num)
	{
		if (visited[num] == false)
		{
			primes.emplace_back(num);
		}
	}

	int num1 = 0, num2 = (~0U >> 2);
	for (int i = 0; i < primes.size(); ++i)
	{
		int candidate = n - primes[i];
		if (visited[candidate] == false)
		{
			if (GetLen(num1, num2) > GetLen(primes[i], candidate))
			{
				num1 = primes[i];
				num2 = candidate;
			}
		}
	}

	if (num1 > num2)
	{
		SwapNode(num1, num2);
	}

	cout << num1 << " " << num2 << endl;
	visited.clear();
}

int main(void)
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; ++testCase)
	{
		Solution();
	}
	return 0;
}