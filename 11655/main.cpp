#include <iostream>
#include <string>

#define MAX_STR_LEN		101

using namespace std;

int GetStrLen(char* str)
{
	int iLen = 0;
	while (str[iLen] != '\0')
	{
		++iLen;
	}
	return iLen;
}

int main(void)
{
	char cStr[MAX_STR_LEN];
	cin.getline(cStr, 101);
	
	int cStrLen = GetStrLen(cStr);
	for (int index = 0; index < cStrLen; ++index)
	{
		char cCurrentChar = cStr[index];

		if (cStr[index] >= 'A' && cStr[index] <= 'Z')
		{
			cCurrentChar += 13;
			if (cCurrentChar > 'Z')
			{
				cCurrentChar -= 26;
			}
		}

		if (cStr[index] >= 'a' && cStr[index] <= 'z')
		{
			cCurrentChar += 13;
			if (cCurrentChar > 'z' || cCurrentChar < 'a')
			{
				cCurrentChar -= 26;
			}
		}

		cout << cCurrentChar;
	}
	return 0;
}