#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int main(void)
{
	int N, M;
	cin >> N >> M;
	for (int index = 0; index < N; ++index)
	{
		int num;
		cin >> num;
		arr.emplace_back(num);
	}

	int answer = 0;
	int arrLen = arr.size();
	int startPointer = 0;
	int endPointer = 0;
	int sum = arr[startPointer];

	while (startPointer <= endPointer)
	{
		if (endPointer == arrLen - 1)
		{
			if (sum == M)
			{
				++answer;
			}
			sum -= arr[startPointer++];
		}
		else
		{
			if (sum < M)
			{
				sum += arr[++endPointer];
			}
			else if (sum == M)
			{
				++answer;
				sum += arr[++endPointer];
			}
			else
			{
				if (startPointer == endPointer)
				{
					sum += arr[++endPointer];
				}
				else
				{
					sum -= arr[startPointer++];
				}
			}
		}
	}

	cout << answer << "\n";
	return 0;
}