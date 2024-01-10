#include <iostream>

using namespace std;

int main(void)
{
	int currentMoney;
	cin >> currentMoney;

	int changes[] = { 500, 100, 50, 10, 5, 1 };
	int changeIdx = 0;
	
	int answer = 0;
	int currentChange = 1000 - currentMoney;

	while (currentChange != 0)
	{
		if (currentChange - changes[changeIdx] >= 0)
		{
			currentChange -= changes[changeIdx];
			++answer;
		}
		else
		{
			++changeIdx;
		}
	}

	cout << answer << "\n";
	return 0;
}