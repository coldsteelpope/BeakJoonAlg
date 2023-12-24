#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		pq.push(num);
	}

	int useChain = 0;
	while (useChain < pq.size() - 1)
	{
		int currentChain = pq.top();
		// ����ߴ� Chain(useChain)�� ���� Chain(currentChain)���� currentChain ������ chain���� ���� �� �ִ°�?
		if (useChain + currentChain <= pq.size() - 1)
		{
			// �� ���� �� �ְų�, ���� ���ڶ�
			useChain += currentChain;
		}
		else
		{
			// ���ĳ�
			// currentChain + 1 ���� Chain���� ���� ����ߴ� Chain(useChain)���� ��� ���� 
			// �������� ������ �Ǳ� ������ pq.size() - 1�� ����
			// ex) 3, 11
			useChain = pq.size() - 1;
		}
		pq.pop();
	}
	cout << useChain << "\n";
	return 0;
}