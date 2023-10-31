#include <iostream>
#include <vector>
#include <algorithm>

#define INF 100000000000

using namespace std;

vector<long long> arr;

inline long long GetAbs(long long a)
{
	return a < 0 ? -a : a;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int number;
		cin >> number;
		arr.emplace_back(number);
	}
	sort(arr.begin(), arr.end());

	int leftPointer = 0;
	int rightPointer = N - 1;

	long long answerLen = INF;
	int answerLeftPointer = -1;
	int answerRightPointer = -1;

	while (leftPointer < rightPointer)
	{
		long long sum = arr[leftPointer] + arr[rightPointer];
		long long currentLen = GetAbs(sum);

		if (answerLen > currentLen)
		{
			answerLen = currentLen;
			answerLeftPointer = leftPointer;
			answerRightPointer = rightPointer;
		}

		if (sum > 0)
		{
			--rightPointer;
		}
		else if (sum < 0)
		{
			++leftPointer;
		}
		else
		{
			break;
		}
	}

	cout << arr[answerLeftPointer] << " " << arr[answerRightPointer] << endl;
	return 0;
}