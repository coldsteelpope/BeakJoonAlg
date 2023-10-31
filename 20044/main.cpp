#include <iostream>
#include <vector>
#include <algorithm>
#define INF (~0U >> 2)

using namespace std;

vector<long long> power;

int main(void)
{
	long long N;
	cin >> N;

	for (long long i = 0; i < 2 * N; ++i)
	{
		long long num;
		cin >> num;
		power.push_back(num);
	}

	sort(power.begin(), power.end());

	long long min_value = INF;
	for (long long i = 0; i < N; ++i)
	{
		long long sum = power[i] + power[(2 * N) - 1 - i];
		min_value = (min_value > sum) ? sum : min_value;
	}

	cout << min_value << endl;
	return 0;
}