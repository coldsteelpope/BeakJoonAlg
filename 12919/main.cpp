#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void SwapNum(char& num1, char& num2)
{
	char temp = num1;
	num1 = num2;
	num2 = temp;
}

int main(void)
{
	string S, T;
	cin >> S >> T;

	queue<string> q;
	q.push(T);

	while (q.empty() == false)
	{
		string currentStr = q.front();
		int currentStrSize = currentStr.size();
		q.pop();

		if (currentStr.length() == 0)
		{
			continue;
		}

		if (currentStr == S)
		{
			cout << 1 << endl;
			exit(0);
		}

		if (currentStr[currentStrSize - 1] == 'A')
		{
			string nextStr = currentStr.substr(0, currentStrSize - 1);
			q.push(nextStr);
		}

		std::reverse(currentStr.begin(), currentStr.end());
		if (currentStr[currentStrSize - 1] == 'B')
		{
			string nextStr = currentStr.substr(0, currentStrSize - 1);
			q.push(nextStr);
		}
	}
	cout << 0 << endl;
	return 0;
}