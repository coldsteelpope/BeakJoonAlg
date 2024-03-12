#include <iostream>

#define MAX_LEN		21

using namespace std;

int dp[MAX_LEN][MAX_LEN][MAX_LEN] = { 0, };

void SetDP()
{
	for (int iA = 0; iA <= 20; ++iA)
	{
		for (int iB = 0; iB <= 20; ++iB)
		{
			for (int iC = 0; iC <= 20; ++iC)
			{
				if (iA <= 0 || iB <= 0 || iC <= 0)
				{
					dp[iA][iB][iC] = 1;
				}
				else if (iA < iB && iB < iC)
				{
					dp[iA][iB][iC] = dp[iA][iB][iC - 1] + dp[iA][iB - 1][iC - 1] - dp[iA][iB - 1][iC];
				}
				else
				{
					dp[iA][iB][iC] = dp[iA - 1][iB][iC] + dp[iA - 1][iB - 1][iC] + dp[iA - 1][iB][iC - 1] - dp[iA - 1][iB - 1][iC - 1];
				}
			}
		}
	}
}

int main(void)
{
	SetDP();
	while (true)
	{
		int iNumberOne, iNumberTwo, iNumberThree;
		cin >> iNumberOne >> iNumberTwo >> iNumberThree;

		if (iNumberOne == -1 && iNumberTwo == -1 && iNumberThree == -1)
		{
			break;
		}

		if (iNumberOne <= 0 || iNumberTwo <= 0 || iNumberThree <= 0)
		{
			cout << "w(" << iNumberOne << ", " << iNumberTwo << ", " << iNumberThree << ") = " << dp[0][0][0] << endl;
		}
		else if (iNumberOne > 20 || iNumberTwo > 20 || iNumberThree > 20)
		{
			cout << "w(" << iNumberOne << ", " << iNumberTwo << ", " << iNumberThree << ") = " << dp[20][20][20] << endl;
		}
		else
		{
			cout << "w(" << iNumberOne << ", " << iNumberTwo << ", " << iNumberThree << ") = " << dp[iNumberOne][iNumberTwo][iNumberThree] << endl;
		}
	}
	return 0;
}