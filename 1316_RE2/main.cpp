#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, bool> alps;

bool IsGroupWord(string str)
{
	bool result = true;
	int strLen = str.size();
	for (int i = 0; i < strLen;)
	{
		char pivot = str[i];
		if (alps[pivot] == false)
		{
			while (str[i] == pivot)
			{
				++i;
			}
			alps[pivot] = true;
		}
		else
		{
			result = false;
			break;
		}
	}
	alps.clear();
	return result;
}

int main(void)
{
	int N;
	cin >> N;

	int answer = 0;
	int index = 0;
	while (index < N)
	{
		string str;
		cin >> str;
		bool isGroupWord = IsGroupWord(str);
		if (isGroupWord == true)
		{
			++answer;
		}
		++index;
	}
	cout << answer << "\n";
	return 0;
}