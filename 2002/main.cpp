#include <iostream>
#include <queue>
#include <map>

using namespace std;

map<string, bool> passingCars;
queue<string> inputCars;
queue<string> outputCars;

int main(void)
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		string car;
		cin >> car;
		inputCars.push(car);
		passingCars[car] = false;
	}

	for (int i = 0; i < N; ++i)
	{
		string car;
		cin >> car;
		outputCars.push(car);
	}

	int answer = 0;
	while (outputCars.empty() == false)
	{
		while (passingCars[inputCars.front()] == true)
		{
			inputCars.pop();
		}

		string inputCar = inputCars.front();
		string outputCar = outputCars.front();

		if (inputCar == outputCar)
		{
			passingCars[outputCar] = true;
			outputCars.pop();
			inputCars.pop();
		}
		else
		{
			passingCars[outputCar] = true;
			outputCars.pop();
			++answer;
		}
	}

	cout << answer << "\n";
	return 0;
}