#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int start_pos, target_pos;
	int num = 1;

	vector<int> arr;
	cin >> start_pos >> target_pos;
	
	bool is_end = false;
	int t = 0;
	while (1)
	{
		for (int j = 1; j <= num; ++j)
		{
			arr.push_back(num);
			++t;
			if (t == target_pos)
			{
				is_end = true;
				break;
			}
		}
		if (is_end == true)
			break;
		else
			++num;
	}

	int sum = 0;
	for (int i = start_pos - 1; i < target_pos; ++i)
		sum += arr[i];

	cout << sum << endl;
	return 0;
}