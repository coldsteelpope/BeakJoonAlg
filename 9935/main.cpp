#include <iostream>

using namespace std;

int main(void)
{
	string str;
	cin >> str;
	int strLen = str.length();

	string bomb;
	cin >> bomb;
	int bombLen = bomb.length();
	char bomb_back_char = bomb[bombLen - 1];

	string answer = "";
	
	for (int i = 0; i < strLen; ++i)
	{
		answer += str[i];
		int answerLen = answer.length();

		if (answerLen >= bombLen)
		{
			bool start_bomb = false;
			
			if (bomb_back_char == answer[answerLen - 1])
			{
				int cnt = 0;

				for (int idx = 0; idx < bombLen; ++idx)
				{
					if (bomb[bombLen - 1 - idx] == answer[answerLen - 1 - idx])
						++cnt;
				}

				if (bombLen == cnt)
				{
					for (int i = 0; i < bombLen; ++i)
					{
						answer.pop_back();
					}
				}
			}
		}
	}

	if (answer == "")
		cout << "FRULA" << endl;
	else
		cout << answer << endl;
	return 0;
}