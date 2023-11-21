
#include <iostream>
#include <stack>
using namespace std;


// ( �� )�� ���ؼ� Ǫ�� ���
// ( �� )�� ���� ���ؼ� Ǫ�� ��� -> (�� ���� )�� ���� ���� �ʴٸ�(¦�� �� �´� ���), ������ ���� ������
// ������ Ǯ ���� if�� else���� �ٿ�����

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