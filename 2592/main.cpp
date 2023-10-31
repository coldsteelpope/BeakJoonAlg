#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Number
{
public:
	Number(int number);
	void SetNumber(int number);
	int GetNumber();
	void SetCount(int count);
	int GetCount();
private:
	int _number;
	int _count;
};

Number::Number(int number) { this->_number = number; this->_count = 1; }
void Number::SetNumber(int number) { this->_number = number; }
void Number::SetCount(int count) { this->_count = count; }
int Number::GetNumber() { return this->_number; }
int Number::GetCount() { return this->_count; }

bool compare(Number& a, Number& b)
{
	return a.GetCount() > b.GetCount();
}

int main(void)
{
	int sum = 0;
	vector<Number> arr;
	for (int t = 1; t <= 10; ++t)
	{
		int number;
		cin >> number;
		sum += number;

		bool is_existed = false;
		for (int i = 0; i < arr.size(); ++i)
		{
			if (number == arr[i].GetNumber())
			{
				is_existed = true;
				arr[i].SetCount(arr[i].GetCount() + 1);
			}
		}

		if (is_existed == false)
		{
			Number newNumber(number);
			arr.push_back(newNumber);
		}
	}


	int ave = sum / 10;
	sort(arr.begin(), arr.end(), compare);
	int mode = arr[0].GetNumber();

	cout << ave << endl;
	cout << mode << endl;
	return 0;
}