#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int main(void)
{
	long long N, S;
	cin >> N >> S;

	arr.resize(N + 1);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	// sum >= S일 때, s++ => 지금 값을 빼고 움직이기
	long long start_pointer = 0;
	// sum < S일 때, e++ => 지금 값을 더하고 움직이기
	long long end_pointer = 0;
	long long sum = 0;

	long long answer = 0;
	while (end_pointer <= N)
	{
		if (sum >= S)
		{
			sum -= arr[start_pointer++];
		}
		else
		{
			sum += arr[end_pointer++];
		}

		if (sum == S)
		{
			++answer;
		}
	}
	
	cout << answer << endl;
}