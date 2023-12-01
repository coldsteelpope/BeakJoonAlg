#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	string str;
	cin >> str;

	int answer = 0;
	int strLen = str.size();
	
	stack<int> s;
	for (int i = 0; i < strLen; ++i)
	{
		char currentChar = str[i];
		if (currentChar == '(')
		{
			s.push(i);
		}
		else
		{
			if (s.top() + 1 == i)
			{
				s.pop();
				answer += s.size();
			}
			else
			{
				answer += 1;
				s.pop();
			}
		}
	}
	cout << answer << endl;
	return 0;
}