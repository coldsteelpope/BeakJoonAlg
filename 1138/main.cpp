#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _NUM
{
	int _data;
	int _seq;
} Num;

Num arr[10] = { 0, };
Num sorted_arr[10] = { 0, };

bool compare(Num num1, Num num2)
{
	return num1._seq < num2._seq;
}

int main(void)
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		arr[i]._data = i + 1;
		cin >> arr[i]._seq;
	}

	//sort(arr, arr + N, compare);

	for (int i = 0; i < N; ++i)
	{
		sorted_arr[i]._data = -1;
		sorted_arr[i]._seq = -1;
	}
	
	for (int i = 0; i < N; ++i)
	{
		Num current_num = arr[i];
		
		int blank_idx = 0;
		int blank_num = 0;
		for (int idx = 0; idx < N; ++idx)
		{
			if (blank_num == current_num._seq)
			{
				if (sorted_arr[idx]._data != -1)
				{
					continue;
				}
				else
				{
					blank_idx = idx;
					break;
				}
			}
			else
			{
				if (sorted_arr[idx]._data == -1)
				{
					++blank_num;
				}
			}
		}

		sorted_arr[blank_idx]._data = current_num._data;
		sorted_arr[blank_idx]._seq = current_num._seq;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << sorted_arr[i]._data << " ";
	}
	return 0;
}