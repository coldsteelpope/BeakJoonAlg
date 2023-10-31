#include <iostream>
#include <vector>

#define INF 100000000001

using namespace std;

vector<long long> liquids;

inline long long GetAbs(long long a)
{
	return (a > 0) ? a : -a;
}

int main(void)
{
	long long N;
	cin >> N;
	liquids.resize(N + 1);

	for (long long i = 0; i < N; ++i)
		cin >> liquids[i];

	long long min_value = INF;
	//long long min_value = (~0U >> 2);
	long long min_start_idx = 0;
	long long min_end_idx = 0;

	for (int i = 0; i < N - 1; ++i)
	{
		long long current_liquid = liquids[i];

		long long start_idx = i + 1;
		long long end_idx = N - 1;
		
		while (start_idx <= end_idx)
		{
			long long mid = (start_idx + end_idx) / 2;
			long long result = current_liquid + liquids[mid];
			

			if (GetAbs(result) <= min_value)
			{
				min_value = GetAbs(result);
				min_start_idx = i;
				min_end_idx = mid;

				if (result == 0)
				{
					break;
				}
			}

			if (result < 0)
			{
				start_idx = mid + 1;
			}
			else
			{
				end_idx = mid - 1;
			}
		}
	}

	cout << liquids[min_start_idx] << " " << liquids[min_end_idx] << endl;
	return 0;
}