#include <iostream>
#include <vector>

using namespace std;

vector<int> g_iVector;

int main(void)
{
	int iN;
	int iK;
	cin >> iN >> iK;

	for (int i = 0; i < iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		g_iVector.emplace_back(iNumber);
	}

	int iSum = 0;
	int iResult = 0;
	int iLeftPointer = 0;
	int iRightPointer = iK - 1;

	for (int i = iLeftPointer; i <= iRightPointer; ++i)
	{
		iSum += g_iVector[i];
	}
	iResult = iSum;

	for (int i = 0; i < iN - iK; ++i)
	{
		iSum += g_iVector[++iRightPointer];
		iSum -= g_iVector[iLeftPointer++];
		iResult = (iSum > iResult) ? iSum : iResult;
	}

	cout << iResult << endl;
	return 0;
}