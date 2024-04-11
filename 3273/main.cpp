#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int g_iN;
int g_iX;
vector<int> iArray;

void Set_And_Sort_Array();

int main(void)
{
	Set_And_Sort_Array();
	cin >> g_iX;
	
	int iLeftIdx = 0;
	int iRightIdx = iArray.size() - 1;

	int iResult = 0;
	while (iLeftIdx < iRightIdx)
	{
		int iSmallNumber = iArray[iLeftIdx];
		int iBigNumber = iArray[iRightIdx];
		
		if (iSmallNumber + iBigNumber == g_iX)
		{
			++iResult;
			--iRightIdx;
		}
		else if (iSmallNumber + iBigNumber > g_iX)
		{
			--iRightIdx;
		}
		else if (iSmallNumber + iBigNumber < g_iX)
		{
			++iLeftIdx;
		}
	}
	cout << iResult << endl;
	return 0;
}

void Set_And_Sort_Array()
{
	cin >> g_iN;
	for (int i = 0; i < g_iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		iArray.emplace_back(iNumber);
	}
	std::sort(iArray.begin(), iArray.end());
}
