#include <iostream>
#include <vector>
#include <cmath>
#define INF (~0U >> 2)
using namespace std;

vector<bool> arr;
vector<int> primeNums;
int main(void)
{
	int N = 10000;
	int start_pos, target_pos;
	cin >> start_pos >> target_pos;
	arr.resize(N + 1, false);
	arr[0] = arr[1] = true;
	for (int num = 2; num <= (int)sqrt(N); ++num)
	{
		if (arr[num] == false)
		{
			for (int i = num + num; i <= N; i += num)
			{
				arr[i] = true;
			}
		}
	}
	for (int i = 0; i <= N; ++i)
	{
		if (arr[i] == false)
			primeNums.push_back(i);
	}
	
	int sum = 0;
	int min_value = INF;
	for (int i = 0; i < primeNums.size(); ++i)
	{
		if(primeNums[i] >= start_pos && primeNums[i] <= target_pos)
		{
			sum += primeNums[i];
			min_value = (min_value > primeNums[i]) ? primeNums[i] : min_value;
		}
	}

	min_value = (min_value == INF) ? -1 : min_value;



	if(sum != 0)
		cout << sum << endl;
	cout << min_value << endl;
	return 0;
}