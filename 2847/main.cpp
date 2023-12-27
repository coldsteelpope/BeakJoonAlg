#include <iostream>
#include <vector>

using namespace std;

vector<int> scores;

int main(void)
{
	int N;
	cin >> N;
	scores.resize(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> scores[i];
	}
	
	int sum = 0;
	for (int i = N - 1; i >= 1; --i)
	{
		if (scores[i] > scores[i - 1])
		{
			continue;
		}
		else
		{
			if (scores[i - 1] == 1)
			{
				continue;
			}
			else
			{
				int diff = scores[i - 1] - scores[i] + 1;
				scores[i - 1] -= diff;
				sum += diff;
			}
		}
	}

	cout << sum << "\n";
	return 0;
}