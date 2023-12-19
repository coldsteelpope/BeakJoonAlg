#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<int> weights(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> weights[i];
	}

	std::sort(weights.begin(), weights.end());
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (sum + 1 < weights[i])
		{
			break;
		}
		sum += weights[i];
	}
	cout << sum + 1 << endl;
	return 0;
}