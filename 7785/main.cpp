#include <iostream>
#include <map>

using namespace std;

map<string, string, greater<>> logs;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int iN;
	cin >> iN;
	for (int index = 0; index < iN; ++index)
	{
		string sName, sStatus;
		cin >> sName >> sStatus;

		logs[sName] = sStatus;
	}

	for (auto it = logs.begin(); it != logs.end(); ++it)
	{
		if (it->second == "enter")
		{
			cout << it->first << "\n";
		}
	}

	return 0;
}