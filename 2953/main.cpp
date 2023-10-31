#include <iostream>
using namespace std;

int main(void)
{
	int max_value = 0;
	int max_person = 0;

	for (int person = 1; person <= 5; ++person)
	{
		int sum = 0;
		for (int i = 0; i < 4; ++i)
		{
			int score = 0;
			cin >> score;
			sum += score;
		}

		if (max_value < sum)
		{
			max_value = sum;
			max_person = person;
		}
	}

	cout << max_person << " " << max_value << endl;
	return 0;
}