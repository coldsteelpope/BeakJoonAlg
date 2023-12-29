#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ��� * ��� OR ���� * ���� -> answers
// 1�� ���ϴ� �ͺ��� ���� �� ū ���� ���� �� ���� -> answers
// ������ Ȧ������ ��,
//		0�� �����ϴ� ��� -> ���� ���� ������ ���ؼ� ¦���� �����
//		0�� ���Ե��� �ʴ� ��� -> ���� ���� ������ answers�� ������ ���� * ������ �Ѵ�.

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