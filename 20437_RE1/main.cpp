#include <iostream>
#include <vector>
#include <map>

using namespace std;

inline int GetMin(int num1, int num2)
{
	return num1 > num2 ? num2 : num1;
}

inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

void Solution()
{
	string str;
	cin >> str;
	int K;
	cin >> K;

	int strLen = str.size();
	int maxLen = 0;
	int minLen = (~0U >> 2);

	map<char, vector<int>> alps;

	for (int i = 0; i < strLen; ++i)
	{
		alps[str[i]].push_back(i);
	}

	for (auto it = alps.begin(); it != alps.end(); ++it)
	{
		if (it->second.size() < K)
		{
			continue;
		}

		int lp = 0;
		int rp = K - 1;
		while (rp < it->second.size())
		{
			int temp = it->second[rp] - it->second[lp] + 1;
			maxLen = GetMax(maxLen, temp);
			minLen = GetMin(minLen, temp);
			++rp; ++lp;
		}
	}
	
	if (maxLen == 0 && minLen == (~0U >> 2))
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << minLen << " " << maxLen << "\n";
	}
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