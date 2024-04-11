#include <iostream>

#define MAX_LEN 100
using namespace std;

long long iA[MAX_LEN][MAX_LEN] = { 0, };
long long iB[MAX_LEN][MAX_LEN] = { 0, };
long long iResult[MAX_LEN][MAX_LEN] = { 0, };


int main(void)
{
	int iN, iM;
	cin >> iN >> iM;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cin >> iA[i][j];
		}
	}

	int iK;
	cin >> iM >> iK;
	for (int i = 0; i < iM; ++i)
	{
		for (int j = 0; j < iK; ++j)
		{
			cin >> iB[i][j];
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int k = 0; k < iK; ++k)
		{
			for (int m = 0; m < iM; ++m)
			{
				iResult[i][k] += (iA[i][m] * iB[m][k]);
			}
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iK; ++j)
		{
			cout << iResult[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}