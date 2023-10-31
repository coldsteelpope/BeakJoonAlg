#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> arr;

inline long long GetAbs(long long a)
{
	return a < 0 ? -a : a;
}

int main(void)
{
	long long N;
	cin >> N;
	arr.resize(N);
	for (long long i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	vector<long long> answer(3, 0);
	long long total = 100000000000;

	for (long long pointer_one = 0; pointer_one < N - 2; ++pointer_one)
	{
		long long pointer_two = pointer_one + 1;
		long long pointer_three = N - 1;

		while (pointer_two < pointer_three)
		{
			long long current_sum = arr[pointer_one] + arr[pointer_two] + arr[pointer_three];
			if (GetAbs(current_sum) < total)
			{
				total = GetAbs(current_sum);
				answer[0] = arr[pointer_one];
				answer[1] = arr[pointer_two];
				answer[2] = arr[pointer_three];
			}
			
			if (current_sum < 0)
			{
				pointer_two++;
			}
			else
			{
				pointer_three--;
			}
		}
	}

	for (long long i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}
	return 0;
}
