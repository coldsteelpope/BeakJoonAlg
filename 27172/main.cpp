#include <iostream>
#include <vector>

using namespace std;

int nums[1000004] = { 0, };
int scores[1000004] = { 0, };

vector<int> cards;
vector<int> answer;

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int number;
		cin >> number;
		cards.push_back(number);
		nums[number] = 1;
	}

	for (int i = 0; i < N; ++i)
	{
		int current_card = cards[i];
		for (int j = current_card * 2; j < 1000001; j += current_card)
		{
			if (nums[j] == 1)
			{
				++scores[current_card];
				--scores[j];
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		cout << scores[cards[i]] << " ";
	}
	return 0;
}