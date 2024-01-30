#include <iostream>
#include <vector>
#define MAX_DIFF 20

using namespace std;

vector<int> arr;

void PrintArr(int N)
{
	int index = 1;
	while (index <= N)
	{
		cout << arr[index] << " ";
		if (index % MAX_DIFF == 0)
		{
			cout << "\n";
		}
		++index;
	}
}

void BoyAction(int number, int N)
{
	int ratio = number;
	while (number <= N)
	{
		switch (arr[number])
		{
		case 0:
			arr[number] = 1;
			break;
		case 1:
			arr[number] = 0;
			break;
		default:
			break;
		}
		number += ratio;
	}
}

void GirlAction(int position, int N)
{
	int difference = 0;

	switch (arr[position])
	{
	case 0:
		arr[position] = 1;
		break;
	case 1:
		arr[position] = 0;
		break;
	}
	++difference;
	
	while (((position + difference <= N) && (position - difference >= 1)))
	{
		if (arr[position + difference] == arr[position - difference])
		{
			switch (arr[position + difference])
			{
			case 0:
				arr[position + difference] = 1;
				break;
			case 1:
				arr[position + difference] = 0;
				break;
			}

			switch (arr[position - difference])
			{
			case 0:
				arr[position - difference] = 1;
				break;
			case 1:
				arr[position - difference] = 0;
				break;
			}
			++difference;
		}
		else
		{
			break;
		}
	}
}

int main(void)
{
	int N;
	cin >> N;
	arr.resize(N + 1, 0);
	
	for (int index = 1; index <= N; ++index)
	{
		cin >> arr[index];
	}

	int studentsNumber = 0;
	cin >> studentsNumber;

	for (int index = 0; index < studentsNumber; ++index)
	{
		int type;
		int number;
		cin >> type >> number;

		switch (type)
		{
		case 1:
			BoyAction(number, N);
			break;
		case 2:
			GirlAction(number, N);
			break;
		default:
			break;
		}
	}

	PrintArr(N);
	cout << endl;
	return 0;
}