#include <iostream>
#include <vector>

#define INF 9223372036854775807

using namespace std;

vector<long long> arr;

inline long long GetMin(long long a, long long b)
{
	return a > b ? b : a;
}

int main(void)
{
	long long N, S;
	cin >> N >> S;

	arr.resize(N + 1);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	long long start_pointer = 0;
	long long end_pointer = 0;
	long long sum = 0;
	
	long long len = INF;
	while (end_pointer <= N)
	{
		if (sum >= S)
		{
			len = GetMin(end_pointer - start_pointer, len);

			sum -= arr[start_pointer++];
		}
		else
		{
			sum += arr[end_pointer++];
		}

	}

	if (len == INF)
		cout << 0 << endl;
	else
		cout << len << endl;
	return 0;
}