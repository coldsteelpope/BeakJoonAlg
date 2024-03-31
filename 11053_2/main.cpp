#include <iostream>
#include <vector>

using namespace std;

vector<int> iArr;
vector<int> iDp;

int GetMax(int iNumber1, int iNumber2)
{
	return (iNumber1 > iNumber2) ? iNumber1 : iNumber2;
}

int main(void)
{
	int iN;
	cin >> iN;
	
	for (int index = 0; index < iN; ++index)
	{
		int iElement;
		cin >> iElement;
		iArr.push_back(iElement);
	}

	iDp.resize(iN, 1);
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (iArr[i] > iArr[j])
			{
				iDp[i] = GetMax(iDp[i], iDp[j] + 1);
			}
		}
	}
	
	int iResult = 0;
	for (int index = 0; index < iN; ++index)
	{
		iResult = GetMax(iDp[index], iResult);
	}

	cout << iResult << endl;
	return 0;
}