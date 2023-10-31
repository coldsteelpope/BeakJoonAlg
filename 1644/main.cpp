#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primeNumbers;

int main(void)
{
	int N;
	cin >> N;

	vector<bool> numbers(N + 1, false);
	numbers[0] = numbers[1] = true;

	for (int i = 2; i <= (int)sqrt(N); ++i)
	{
		if (numbers[i] == false)
		{
			for (int j = i + i; j <= N; j += i)
			{
				numbers[j] = true;
			}
		}
	}

	for (int i = 0; i <= N; ++i)
	{
		if (numbers[i] == false)
			primeNumbers.emplace_back(i);
	}

	int answer = 0;
	int left_pointer = 0;
	int right_pointer = 0;

	while (left_pointer <= right_pointer && left_pointer < primeNumbers.size())
	{
		int sum = 0;
		if (right_pointer < primeNumbers.size() - 1)
		{
			for (int i = left_pointer; i <= right_pointer; ++i)
				sum += primeNumbers[i];

			if (sum < N)
			{
				++right_pointer;
			}
			else if (sum > N)
			{
				++left_pointer;
			}
			else
			{
				++answer;
				++right_pointer;
			}
		}
		else
		{
			for (int i = left_pointer; i < primeNumbers.size(); ++i)
				sum += primeNumbers[i];

			if (sum == N)
			{
				++answer;
			}
			++left_pointer;
		}
	}
	
	cout << answer << endl;
	return 0;
}