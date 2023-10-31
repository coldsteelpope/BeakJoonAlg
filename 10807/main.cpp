#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<int>	arr;
	for (int i = 0; i < N; ++i)
	{
		int number;
		cin >> number;
		arr.push_back(number);
	}

	int answer = 0;
	int find_num = 0;
	cin >> find_num;
	
	int arrLen = arr.size();
	for (int i = 0; i < arrLen; ++i)
	{
		if (find_num == arr[i])
		{
			++answer;
		}
	}

	cout << answer << endl;
	return 0;
}