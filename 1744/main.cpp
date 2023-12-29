#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> positives;
	vector<int> negatives;
	vector<int> answer;
	vector<int> zeros;

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
			answer.push_back(num);
		}
		else if (num == 0)
		{
			zeros.push_back(num);
		}
		else
		{
			negatives.push_back(num);
		}
	}

	std::sort(positives.begin(), positives.end(), greater<int>());
	
	int positivesLen = positives.size();
	if (positivesLen % 2 != 0)
	{
		answer.push_back(positives.back());
		positives.pop_back();
		--positivesLen;
	}

	for (int i = 0; i < positivesLen - 1; i += 2)
	{
		int one = positives[i];
		int two = positives[i + 1];
		answer.push_back(one * two);
	}

	std::sort(negatives.begin(), negatives.end());
	
	int negativesLen = negatives.size();
	if (negativesLen % 2 != 0 && zeros.empty() == false)
	{
		negatives.pop_back();
	}
	else if (negativesLen % 2 != 0 && zeros.empty() == true)
	{
		answer.push_back(negatives.back());
		negatives.pop_back();
	}

	for (int i = 0; i < negativesLen - 1; i += 2)
	{
		int one = negatives[i];
		int two = negatives[i + 1];
		answer.push_back(one * two);
	}

	int sum = 0;
	for (int i = 0; i < answer.size(); ++i)
	{
		sum += answer[i];
	}

	cout << sum << "\n";
	return 0;
}