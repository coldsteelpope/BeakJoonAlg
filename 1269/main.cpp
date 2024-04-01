#include <iostream>
#include <map>

using namespace std;

map<int, bool> mapA;
map<int, bool> mapB;

int main(void)
{
	int iA;
	int iB;
	cin >> iA >> iB;

	for (int i = 0; i < iA; ++i)
	{
		int iNumber;
		cin >> iNumber;
		mapA[iNumber] = true;
	}

	for (int i = 0; i < iB; ++i)
	{
		int iNumber;
		cin >> iNumber;
		mapB[iNumber] = true;
	}

	int iResultA = 0;
	int iResultB = 0;
	for (auto it = mapA.begin(); it != mapA.end(); ++it)
	{
		if (!mapB[it->first])
		{
			++iResultA;
		}
	}

	for (auto it = mapB.begin(); it != mapB.end(); ++it)
	{
		if (!mapA[it->first])
		{
			++iResultB;
		}
	}

	int iSum = iResultA + iResultB;
	cout << iSum << endl;
	return 0;
}