#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, bool> subStringMap;

int main(void)
{
	string str;
	cin >> str;

	int iStrLen = str.size();
	for (int iGroupSize = 1; iGroupSize <= iStrLen; ++iGroupSize)
	{
		for (int index = 0; index < iStrLen + 1 - iGroupSize; ++index)
		{
			subStringMap[str.substr(index, iGroupSize)] = true;
		}
	}

	cout << subStringMap.size() << endl;
	return 0;
}