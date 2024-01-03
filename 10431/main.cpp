#include <iostream>
#include <deque>

#define MAX_NUM 20

using namespace std;

void SwapSeq(deque<int>& mainSeq, deque<int>& subSeq)
{
	deque<int> temp = mainSeq;
	mainSeq = subSeq;
	subSeq = temp;
}

int Solution()
{
	int answer = 0;

	deque<int> mainSeq;
	deque<int> subSeq;

	for (int i = 0; i < MAX_NUM; ++i)
	{
		int num;
		cin >> num;
		int maxValueNum = 0;

		for (int p = mainSeq.size() - 1; p >= 0; --p)
		{
			if (mainSeq[p] <= num)
			{
				break;
			}
			++maxValueNum;
		}

		for (int j = 0; j < maxValueNum; ++j)
		{
			subSeq.push_front(mainSeq.back());
			mainSeq.pop_back();
		}

		answer += maxValueNum;
		subSeq.push_front(num);

		while (mainSeq.empty() == false)
		{
			subSeq.push_front(mainSeq.back());
			mainSeq.pop_back();
		}

		SwapSeq(mainSeq, subSeq);
	}
	return answer;
}

int main(void)
{
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; ++testCase)
	{
		int seq;
		cin >> seq;
		int result = Solution();
		cout << seq << " " << result << "\n";
	}
	return 0;
}