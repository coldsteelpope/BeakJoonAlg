#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr_one;
vector<long long> arr_two;

vector<long long> sum_arr_one;
vector<long long> sum_arr_two;

long long BinaryUpperBound(long long left, long long right, long long value, vector<long long>& arr)
{
	while (left < right)
	{
		long long mid = (left + right) / 2;
		if (arr[mid] <= value)
		{
			left = mid + 1;

		}
		else
		{
			right = mid;
		}
	}
	return right;

}

long long BinaryLowerBound(long long left, long long right, long long value, vector<long long>& arr)
{
	while (left < right)
	{
		long long mid = (left + right) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return right;
}

void SetSumArr(vector<long long>& arr, vector<long long>& sum_arr)
{
	for (long long left_pointer = 0; left_pointer < arr.size(); ++left_pointer)
	{
		for (long long right_pointer = left_pointer; right_pointer < arr.size(); ++right_pointer)
		{
			long long sum = 0;
			for (long long i = left_pointer; i <= right_pointer; ++i)
			{
				sum += arr[i];
			}
			sum_arr.push_back(sum);
		}
	}
}

int main(void)
{
	long long T;
	cin >> T;

	long long n;
	cin >> n;
	arr_one.resize(n, 0);
	for (long long i = 0; i < n; ++i)
		cin >> arr_one[i];

	long long m;
	cin >> m;
	arr_two.resize(m, 0);
	for (long long i = 0; i < m; ++i)
		cin >> arr_two[i];

	SetSumArr(arr_one, sum_arr_one);
	SetSumArr(arr_two, sum_arr_two);

	sort(sum_arr_two.begin(), sum_arr_two.end());

	long long answer = 0;
	for (long long i = 0; i < sum_arr_one.size(); ++i)
	{
		long long must_two_sum = T - sum_arr_one[i];

		//auto li = lower_bound(sum_arr_two.begin(), sum_arr_two.end(), must_two_sum);
		//auto up = upper_bound(sum_arr_two.begin(), sum_arr_two.end(), must_two_sum);

		long long lowerIndex = BinaryLowerBound(0, sum_arr_two.size(), must_two_sum, sum_arr_two);
		long long upperIndex = BinaryUpperBound(0, sum_arr_two.size(), must_two_sum, sum_arr_two);

		answer += (upperIndex - lowerIndex);
		//answer += up - li;
	}

	cout << answer << endl;


	return 0;
}