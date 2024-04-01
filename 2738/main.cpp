#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> iA;
vector<vector<int>> iB;
vector<vector<int>> iResult;

int main(void)
{
	int iN, iM;
	cin >> iN >> iM;
	
	iA.resize(iN, vector<int>(iM, 0));
	iB.resize(iN, vector<int>(iM, 0));
	iResult.resize(iN, vector<int>(iM, 0));
	
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cin >> iA[i][j];
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cin >> iB[i][j];
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			iResult[i][j] = iA[i][j] + iB[i][j];
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cout << iResult[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}