#include <iostream>

using namespace std;

int main(void)
{
	int iN;
	cin >> iN;

	long long llResult = 1;
	for (int index = 0; index < iN; ++index)
	{
		llResult *= 2;
	}

	cout << llResult << endl;
	return 0;
}