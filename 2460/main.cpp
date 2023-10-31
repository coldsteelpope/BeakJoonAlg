#include <iostream>
using namespace std;

int main(void)
{
	int answer = 0;
	int max_value = 0;
	for (int station = 1; station <= 10; ++station)
	{
		int get_on, get_in;
		cin >> get_on >> get_in;
		answer -= get_on;
		answer += get_in;
		max_value = (max_value > answer) ? max_value : answer;
	}
	cout << max_value << endl;
	return 0;
}