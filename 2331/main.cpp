#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> iArray;
map<int, int> iStorage;


int GetNextNumber(int _iA, int _iP)
{
	int iNextNumber = 0;
	while (_iA != 0)
	{
		int iPartNumber = 1;
		for (int i = 0; i < _iP; ++i)
		{
			iPartNumber *= (_iA % 10);
		}
		iNextNumber += iPartNumber;
		_iA /= 10;
	}
	return iNextNumber;
}

int main(void)
{
	int iA, iP;
	cin >> iA >> iP;

	int iNumber = iA;
	int iSequence = 1;

	do
	{
		iStorage[iNumber] = iSequence++;
		iNumber = GetNextNumber(iNumber, iP);

		if (iStorage[iNumber] != 0)
		{
			cout << iStorage[iNumber] - 1 << endl;
			break;
		}
	} while (true);
	
	return 0;
}