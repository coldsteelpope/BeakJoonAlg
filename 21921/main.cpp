#include <iostream>
#include <vector>

using namespace std;

vector<int> visited_numbers;

int main(void)
{
	int X, N;
	cin >> N >> X;
	
	for (int i = 0; i < N; ++i)
	{
		int visited_num;
		cin >> visited_num;
		visited_numbers.push_back(visited_num);
	}

	
	int current_sum = 0;
	for (int i = 0; i < X; ++i)
		current_sum += visited_numbers[i];

	int max_num = current_sum;
	int max_num_count = 1;

	for (int i = X; i < N; ++i)
	{
		current_sum -= visited_numbers[i - X];
		current_sum += visited_numbers[i];
		
		if (current_sum == max_num)
		{
			++max_num_count;
		}
		else if(current_sum > max_num)
		{
			max_num = current_sum;
			max_num_count = 1;
		}
	}

	if (max_num == 0)
		cout << "SAD" << endl;
	else
	{
		cout << max_num << endl;
		cout << max_num_count << endl;
	}
	
	return 0;
}