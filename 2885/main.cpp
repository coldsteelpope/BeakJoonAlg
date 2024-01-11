#include <iostream>

using namespace std;

int main(void)
{
	int K;
	cin >> K;

	int sizeOfChoco = 1;
	while (sizeOfChoco < K)
	{
		sizeOfChoco *= 2;
	}

	cout << sizeOfChoco << " ";

	int countOfCutting = 0;
	while (K != 0)
	{
		if (K < sizeOfChoco)
		{
			sizeOfChoco /= 2;
			++countOfCutting;
		}
		else
		{
			K -= sizeOfChoco;
		}
	}
	
	cout << countOfCutting << "\n";
	return 0;
}