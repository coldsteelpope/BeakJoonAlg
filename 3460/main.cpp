#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int number;
		cin >> number;

		queue<int> q;
		while (number != 0)
		{
			int remainder = number % 2;
			q.push(remainder);
			number /= 2;
		}

		vector<int> answer;
		int pos = 0;
		while (q.empty() == false)
		{
			int topNumber = q.front();
			if (topNumber == 1)
			{
				answer.push_back(pos);
			}
			++pos;
			q.pop();
		}
		
		int answerLen = answer.size();
		for (int i = 0; i < answerLen; ++i)
			cout << answer[i] << " ";
		cout << endl;
	}
	return 0;
}