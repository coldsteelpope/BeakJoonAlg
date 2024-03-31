#include <iostream>
#include <map>

using namespace std;

map<string, bool> mMessages;

int main(void)
{
	int iN = 0;
	cin >> iN;

	int iTotal = 0;

	for (int i = 0; i < iN; ++i)
	{
		string szName;
		cin >> szName;
		
		if (szName == "ENTER")
		{
			iTotal += mMessages.size();
			mMessages.clear();
		}
		else
		{
			mMessages[szName] = true;
		}
	}

	iTotal += mMessages.size();
	cout << iTotal << endl;

	return 0;
}