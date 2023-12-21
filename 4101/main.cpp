#include <iostream>

using namespace std;

int main(void)
{
	int num1, num2;
	while (true)
	{
		cin >> num1 >> num2;
		if (num1 == 0 && num2 == 0)
		{
			break;
		}
		if (num1 > num2)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}