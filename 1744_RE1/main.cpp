#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 양수 * 양수 OR 음수 * 음수 -> answers
// 1은 곱하는 것보다 더할 때 큰 수를 만들 수 있음 -> answers
// 음수가 홀수개일 때,
//		0이 포함하는 경우 -> 가장 작은 음수를 곱해서 짝수를 만든다
//		0이 포함되지 않는 경우 -> 가장 작은 음수를 answers로 보내고 음수 * 음수를 한다.

vector<int> positives;
vector<int> negatives;
vector<int> zeros;
vector<int> answers;

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		
		if (num > 1)
		{
			positives.emplace_back(num);
		}
		else if (num == 1)
		{
			answers.push_back(num);
		}
		else if (num == 0)
		{
			zeros.emplace_back(num);
		}
		else
		{
			negatives.emplace_back(num);
		}
	}

	std::sort(positives.begin(), positives.end(), greater<int>());

	int positivesLen = positives.size();
	if (positivesLen % 2 != 0)
	{
		answers.emplace_back(positives.back());
		positives.pop_back();
	}
	
	for (int i = 0; i < positivesLen - 1; i += 2)
	{
		answers.emplace_back(
			positives[i] * positives[i + 1]
		);
	}
	
	std::sort(negatives.begin(), negatives.end());
	int negativesLen = negatives.size();
	if (negativesLen % 2 != 0)
	{
		if (zeros.empty() == false)
		{
			negatives.pop_back();
		}
		else
		{
			answers.emplace_back(negatives.back());
			negatives.pop_back();
		}
	}

	for (int i = 0; i < negativesLen - 1; i += 2)
	{
		answers.emplace_back(
			negatives[i] * negatives[i + 1]
		);
	}

	int sum = 0;
	for (int i = 0; i < answers.size(); ++i)
	{
		sum += answers[i];
	}

	cout << sum << "\n";
	return 0;
}