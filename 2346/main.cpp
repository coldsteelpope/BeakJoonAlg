#include <iostream>
#include <deque>
#include <utility>
#include <vector>

using namespace std;


deque<pair<int, int>> dq;

int main(void)
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		int number;
		cin >> number;
		dq.push_back({ i + 1, number });
	}

	vector<int> answer;

	bool isFront = true;
	while (dq.empty() == false)
	{
		pair<int, int> bombed;
		int bombedCard;
		if (isFront)
		{
			bombed = dq.front();
			int bombedNum = bombed.first;
			bombedCard = bombed.second;
			answer.push_back(bombedNum);
			dq.pop_front();
		}
		else
		{
			bombed = dq.back();
			int bombedNum = bombed.first;
			bombedCard = bombed.second;
			answer.push_back(bombedNum);
			dq.pop_back();
		}

		
		if (bombedCard > 0)
		{
			while (bombedCard > 1 && dq.empty() == false)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				--bombedCard;
			}
			isFront = true;
		}
		else if (bombedCard < 0)
		{
			while (bombedCard < -1 && dq.empty() == false)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				++bombedCard;
			}
			isFront = false;
		}
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}
	return 0;
}