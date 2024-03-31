#include <iostream>
#include <map>

using namespace std;

map<string, bool> bFriends;

int main(void)
{
	int iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		string firstPerson, secondPerson;
		cin >> firstPerson >> secondPerson;

		if (firstPerson == "ChongChong" || secondPerson == "ChongChong")
		{
			bFriends[firstPerson] = true;
			bFriends[secondPerson] = true;
		}

		if (bFriends[firstPerson] == true || bFriends[secondPerson] == true)
		{
			bFriends[firstPerson] = true;
			bFriends[secondPerson] = true;
		}
	}

	int iResult = 0;
	for (auto it = bFriends.begin(); it != bFriends.end(); ++it)
	{
		if (it->second)
		{
			++iResult;
		}
	}

	cout << iResult << endl;
	return 0;
}