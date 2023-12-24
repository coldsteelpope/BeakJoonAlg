#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int index = 0;
	while (index < N)
	{
		string str;
		cin >> str;

		int score = 0;
		int adder = 1;
		int strLen = str.size();

		for (int i = 0; i < strLen; ++i)
		{
			if (str[i] == 'O')
			{
				score += adder;
				++adder;
			}
			else
			{
				adder = 1;
			}
		}
		cout << score << "\n";
		++index;
	}
	return 0;
}