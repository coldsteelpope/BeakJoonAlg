#include <iostream>
#include <stack>
#include <queue>

using namespace std;

queue<int> q;
stack<int> s;

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int sequenceNumber = 0;
		cin >> sequenceNumber;
		q.push(sequenceNumber);
	}

	int seq_number = 1;
	while (q.empty() == false)
	{
		int frontSequenceNumber = q.front();
		if (frontSequenceNumber == seq_number)
		{
			q.pop();
			seq_number++;
		}
		else
		{
			while (s.empty() == false && s.top() == seq_number)
			{
				s.pop();
				seq_number++;
			}
			s.push(frontSequenceNumber);
			q.pop();
		}
	}

	while (s.empty() == false && s.top() == seq_number)
	{
		s.pop();
		seq_number++;
	}

	if (s.empty() && q.empty())
		cout << "Nice" << endl;
	else
		cout << "Sad" << endl;
	return 0;
}
