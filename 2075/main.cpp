#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N * N; ++i)
	{
		int num;
		cin >> num;
		pq.push(num);
		if (pq.size() > N)
		{
			pq.pop();
		}
	}

	cout << pq.top() << "\n";
	return 0;
}