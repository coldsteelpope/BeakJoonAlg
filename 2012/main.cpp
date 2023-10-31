#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	long long N;
	cin >> N;
	vector<long long> expected_ranks;
	
	for (long long i = 0; i < N; ++i)
	{
		long long expected_rank;
		cin >> expected_rank;
		expected_ranks.push_back(expected_rank);
	}

	sort(expected_ranks.begin(), expected_ranks.end());
	long long sum = 0;
	for (int rank = 1; rank <= N; ++rank)
		sum += abs(rank - expected_ranks[rank - 1]);
	cout << sum << endl;
	return 0;
}