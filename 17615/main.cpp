#include <iostream>
#include <string>

using namespace std;

inline int GetMin(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int StrLen;
	cin >> StrLen;
	string str;
	cin >> str;

	int RNum = 0;
	int BNum = 0;

	for (int i = 0; i < StrLen; ++i)
	{
		switch (str[i])
		{
		case 'R':
			++RNum;
			break;
		case 'B':
			++BNum;
			break;
		default:
			break;
		}
	}

	char LastChar = str[StrLen - 1];
	int SeqNum = 1;
	for (int i = StrLen - 2; (i >= 0 && str[i] == LastChar); --i)
	{
		++SeqNum;
	}

	int answer = (~0U >> 2);
	if (LastChar == 'R')
	{
		answer = GetMin(BNum, (RNum - SeqNum));
	}
	else
	{
		answer = GetMin(RNum, (BNum - SeqNum));
	}

	char FirstChar = str[0];
	SeqNum = 1;
	for (int i = 1; (i < StrLen && str[i] == FirstChar); ++i)
	{
		++SeqNum;
	}

	if (FirstChar == 'R')
	{
		answer = GetMin(answer, GetMin(BNum, (RNum - SeqNum)));
	}
	else
	{
		answer = GetMin(answer, GetMin(RNum, (BNum - SeqNum)));
	}

	cout << answer << "\n";
}