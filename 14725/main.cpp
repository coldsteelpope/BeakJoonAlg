#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str, '\n');

	cout << str << endl;

	int strLen = str.size();

	for(int i = 0; i < strLen; ++i)
	{
		string first = str.substr(0, 1);
		string second = str.substr(1, strLen - 1);
		str = second + first;
		cout << str << endl;
	}
	return 0;
}