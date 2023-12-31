#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<int> v(1, N);
	vector<bool> discovered(N + 1, false);

	queue<pair<int, vector<int>>> q;

	q.push({ 0, v });
	discovered[N] = true;

	int result = (~0U >> 2);
	vector<int> resultSeqs;

	while (q.empty() == false)
	{
		pair<int, vector<int>> here = q.front();
		q.pop();

		int recentNum = here.second.back();

		if (recentNum == 1)
		{
			result = here.first;
			resultSeqs = here.second;
			break;
		}

		if (recentNum % 3 == 0 && discovered[recentNum / 3] == false)
		{
			vector<int> seqs = here.second;
			seqs.push_back(recentNum / 3);
			q.push({ here.first + 1, seqs });
			discovered[recentNum / 3] = true;
		}

		if (recentNum % 2 == 0 && discovered[recentNum / 2] == false)
		{
			vector<int> seqs = here.second;
			seqs.push_back(recentNum / 2);
			q.push({ here.first + 1, seqs });
			discovered[recentNum / 2] = true;
		}

		if (discovered[recentNum - 1] == false)
		{
			vector<int> seqs = here.second;
			seqs.push_back(recentNum - 1);
			q.push({ here.first + 1, seqs });
			discovered[recentNum - 1] = true;
		}
	}

	cout << result << "\n";
	for (int seq : resultSeqs)
	{
		cout << seq << " ";
	}
	return 0;
}