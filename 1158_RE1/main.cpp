#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	queue<int> q;
	int N, K;
	cin >> N >> K;
	for (int n = 1; n <= N; ++n)
	{
		q.push(n);
	}

	vector<int> answer;
	while (q.empty() == false)
	{
		for (int k = 0; k < K - 1; ++k)
		{
			q.push(q.front());
			q.pop();
		}
		answer.emplace_back(q.front());
		q.pop();
	}
	
	cout << "<";
	for (int i = 0; i < answer.size() - 1; ++i)
	{
		cout << answer[i] << ", ";
	}
	cout << answer[answer.size() - 1] << ">";
	return 0;
}