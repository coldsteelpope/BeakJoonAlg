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
		// 사용했던 Chain(useChain)과 현재 Chain(currentChain)으로 currentChain 이후의 chain들을 묶을 수 있는가?
		if (useChain + currentChain <= pq.size() - 1)
		{
			// 딱 묶을 수 있거나, 아직 모자람
			useChain += currentChain;
		}
		else
		{
			// 넘쳐남
			// currentChain + 1 후의 Chain들은 전에 사용했던 Chain(useChain)으로 모두 묶임 
			// 마지막만 묶으면 되기 때문에 pq.size() - 1로 묶음
			// ex) 3, 11
			useChain = pq.size() - 1;
		}
		pq.pop();
	}
	cout << useChain << "\n";
	return 0;
}