#include <iostream>

using namespace std;

int main(void)
{
	long long llValue = 1;
	
	int iMaxNum;
	cin >> iMaxNum;

	if (iMaxNum == 0)
	{
		cout << llValue << endl;
		return 0;
	}
	
	for (int iNum = 1; iNum <= iMaxNum; ++iNum)
	{
		llValue *= iNum;
	}
	
	cout << llValue << endl;
	return 0;
}