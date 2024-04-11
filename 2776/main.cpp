#include <iostream>
#include <unordered_map>

using namespace std;

void Test()
{
	unordered_map<int, int> iMemoA;

	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		iMemoA[iNumber] = 1;
	}

	int iM;
	cin >> iM;
	for (int j = 0; j < iM; ++j)
	{
		int iNumber;
		cin >> iNumber;
		if (iMemoA[iNumber] == 1)
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}

	iMemoA.clear();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 0; t < iT; ++t)
	{
		Test();
	}
	return 0;
}