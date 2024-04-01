#include <iostream>
#include <vector>

using namespace std;

int g_iMaxValue = INT32_MIN;

vector<int> g_iArray;
vector<int> g_iSum;

int main(void)
{
	int iN;
	int iK;
	cin >> iN >> iK;
	
	g_iArray.resize(iN, 0);
	g_iSum.resize(iN + 1, 0);

	for (int i = 0; i < iN; ++i)
	{
		cin >> g_iArray[i];
		g_iSum[i + 1] = g_iArray[i] + g_iSum[i];
	}
	
	for (int i = iK; i <= iN; ++i)
	{
		int iSum = (g_iSum[i] - g_iSum[i - iK]);
		g_iMaxValue = max(g_iMaxValue, iSum);
	}

	cout << g_iMaxValue << endl;
	return 0;
}