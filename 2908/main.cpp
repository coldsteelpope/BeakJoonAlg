#include <iostream>

using namespace std;

int main(void)
{
	int num1[3];
	int num2[3];

	string str1;
	string str2;
	cin >> str1 >> str2;
	for (int i = 0; i < 3; ++i)
	{
		num1[i] = str1[2 - i] - '0';
		num2[i] = str2[2 - i] - '0';
	}

	int result1 = num1[0] * 100 + num1[1] * 10 + num1[2];
	int result2 = num2[0] * 100 + num2[1] * 10 + num2[2];
	int answer = (result1 > result2) ? result1 : result2;
	cout << answer << endl;
	return 0;
}