#include <iostream>
#include <vector>
#include <map>

using namespace std;


inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

inline int GetMin(int num1, int num2)
{
	return num1 < num2 ? num1 : num2;
}

void Solution()
{
	map<char, vector<int>> alps;
	
	string str;
	cin >> str;
	int K;
	cin >> K;

	int strLen = str.size();
	for (int i = 0; i < strLen; ++i)
	{
		alps[str[i]].push_back(i);
	}

	int maxLen = 0;
	int minLen = (~0U >> 2);
	
	for (auto it = alps.begin(); it != alps.end(); ++it)
	{
		if (it->second.size() < K)
			continue;
		
		int leftPointer = 0;
		int rightPointer = K - 1;

		while (rightPointer < it->second.size())
		{
			int temp = it->second[rightPointer] - it->second[leftPointer] + 1;
			maxLen = GetMax(temp, maxLen);
			minLen = GetMin(temp, minLen);
			++rightPointer; ++leftPointer;
		}
	}

	if (minLen == (~0U >> 2) && maxLen == 0)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << minLen << " " << maxLen << "\n";
	}
	alps.clear();
}

int main(void)
{
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; ++testCase)
	{
		Solution();
	}
	return 0;
}