
#include <iostream>
#include <stack>
using namespace std;


// ( 와 )를 비교해서 푸는 방법
// ( 와 )의 수를 비교해서 푸는 방법 -> (의 수와 )의 수가 맞지 않다면(짝이 안 맞는 경우), 균형이 맞지 않은것
// 다음에 풀 때는 if와 else절을 줄여보자

void Solution()
{
	string str;
	cin >> str;

	stack<char> s;
	int strLen = str.size();

	bool isVPS = true;
	int index = 0;
	while (str[index] != 0)
	{
		char currentChar = str[index];
		if (s.empty() == true)
		{
			if (currentChar == ')')
			{
				isVPS = false;
				break;
			}
			else
			{
				s.push(currentChar);
				++index;
			}
		}
		else
		{
			if (currentChar == '(')
			{
				s.push(currentChar);
				++index;
			}
			else
			{
				char topChar = s.top();
				if (topChar == '(')
				{
					s.pop();
					++index;
				}
				else
				{
					isVPS = false;
					break;
				}
			}
		}
	}

	if (isVPS == false)
	{
		cout << "NO" << endl;
	}
	else
	{
		if (s.empty() == true)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
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