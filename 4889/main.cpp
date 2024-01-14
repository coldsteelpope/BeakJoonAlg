#include <iostream>
#include <string>
#include <stack>

using namespace std;

int Solution()
{
	string str;
	cin >> str;

	if (str[0] == '-')
	{
		return -1;
	}
	else
	{
		int strLen = str.size();
		stack<char> s;

		for (int i = 0; i < strLen; ++i)
		{
			if (s.empty() == true)
			{
				s.push(str[i]);
				continue;
			}

			if (s.top() == '{' && str[i] == '}')
			{
				s.pop();
			}
			else
			{
				s.push(str[i]);
			}
		}

		int result = 0;
		int index = 0;

		while (s.empty() == false)
		{
			if (index % 2 == 0)
			{
				if (s.top() == '}')
				{
					s.pop();
				}
				else
				{
					++result;
					s.pop();
				}
			}
			else
			{
				if (s.top() == '{')
				{
					s.pop();
				}
				else
				{
					++result;
					s.pop();
				}
			}
			++index;
		}
		return result;
	}
}

int main(void)
{
	int num = 1;
	while (true)
	{
		int result = Solution();
		if (result == -1)
		{
			break;
		}
		cout << num << ". " << result << "\n";
		++num;
	}
	return 0;
}