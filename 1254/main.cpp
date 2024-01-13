#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	cin >> str;

	int startPointer = 0;
	int endPointer = str.length() - 1;

	while (startPointer < endPointer)
	{
		int leftPointer = startPointer;
		int rightPointer = endPointer;

		bool isPalin = true;

		while (leftPointer < rightPointer)
		{
			if (str[leftPointer] != str[rightPointer])
			{
				isPalin = false;
				break;
			}
			++leftPointer;
			--rightPointer;
		}

		if (isPalin == true)
		{
			break;
		}
		++startPointer;
	}

	cout << str.length() + startPointer << "\n";
	return 0;
}