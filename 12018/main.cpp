#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	// n: 과목 수
	// m: 주어진 마일리지
	int n, m;
	cin >> n >> m;

	vector<int> limit_score;
	int limit_score_ptr = 0;

	for (int t = 0; t < n; ++t)
	{
		int p, l;
		cin >> p >> l;
		vector<int> temp(p, 0);
		for (int i = 0; i < p; ++i)
		{
			cin >> temp[i];
		}

		if (p < l)
		{
			limit_score.push_back(1);
			continue;
		}
		sort(temp.begin(), temp.end(), greater<>());
		limit_score.push_back(temp[l - 1]);
	}

	int answer = 0;
	sort(limit_score.begin(), limit_score.end());
	for (int i = 0; i < limit_score.size(); ++i)
	{
		if (m >= limit_score[i])
		{
			m -= limit_score[i];
			answer++;
		}
		else
		{
			break;
		}
	}

	cout << answer << endl;
}