// �켱���� ť�� Ǯ�
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<pair<int, int>> flowers;
	for (int i = 0; i < N; ++i)
	{
		int start_m, start_d, end_m, end_d;
		cin >> start_m >> start_d >> end_m >> end_d;
		// first: end_date, second: start_date
		flowers.push_back({ end_m * 100 + end_d, start_m * 100 + start_d });
	}

	// end_date�� ������������ ����
	std::sort(flowers.begin(), flowers.end(), [](pair<int, int> a, pair<int, int>b)->bool {return a.first > b.first; });
	if (flowers[0].first < 1201)
	{
		// 11�� 30�ϱ��� �Ǵ� ���� ���� ��
		cout << 0 << "\n";
		exit(0);
	}

	// start_date�� ������������ ����
	std::sort(flowers.begin(), flowers.end(), [](pair<int, int> a, pair<int, int> b)->bool { return a.second < b.second; });
	if (flowers[0].second > 301)
	{
		// 3�� 1�ϰ� ���� �� �Ǵ� ������ �Ǵ� ���� ���� ��
		cout << 0 << "\n";
		exit(0);
	}

	std::sort(flowers.begin(), flowers.end(), [](pair<int, int>a, pair<int, int>b)->bool
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			else
			{
				return a.second < b.second;
			}
		}
	);

	int start_date = 301;
	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
	pq.push(flowers[0]);
	for (int i = 1; i < N; ++i)
	{
		if (start_date < flowers[i].second)
		{
			if (flowers[i].second < pq.top().first)
			{
				pq.push(flowers[i]);
				start_date = flowers[i].first;
			}
			else
			{
				cout << 0 << endl;
				exit(0);
			}
		}
		else
		{
			if (flowers[i].first <= pq.top().first)
			{
				continue;
			}
			else
			{
				pq.pop();
				pq.push(flowers[i]);
			}
		}
	}

	cout << pq.size() << endl;
}