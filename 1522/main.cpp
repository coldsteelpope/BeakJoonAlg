#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	cin >> str;
	int strLen = str.size();
	int aNum = 0;
	for (int i = 0; i < strLen; ++i)
	{
		if (str[i] == 'a')
		{
			++aNum;
		}
	}
	

	int minValue = strLen + 1;
	for (int i = 0; i < strLen; ++i)
	{
		int bNum = 0;
		for (int j = 0; j < aNum; ++j)
		{
			if (str[(i + j) % strLen] == 'b')
			{
				++bNum;
			}
		}
		minValue = (minValue > bNum) ? bNum : minValue;
	}

	cout << minValue << endl;
	return 0;
}