#include <iostream>
using namespace std;

int GetStrLen(string str)
{
	int len = 0;
	while (str[len] != '\0')
		++len;
	return len;
}

bool Solution(string str)
{
	bool visited[26] = { 0, }, result = true;
	int len = GetStrLen(str);
	char exChar = str[0];
	for (int i = 1; i < len; ++i)
	{
		if (visited[str[i] - 'a'] == false)
		{
			if (exChar != str[i])
			{
				visited[exChar - 'a'] = true;
				exChar = str[i];
			}
		}
		else
		{
			result = false;
			break;
		}
	}
	return result;
}

int main(void)
{
	int T; cin >> T;
	int answer = 0;
	for (int testCase = 0; testCase < T; ++testCase)
	{
		string str; cin >> str;
		bool isSeq = Solution(str);
		if (isSeq)
			++answer;
	}
	cout << answer << endl;
	return 0;
}