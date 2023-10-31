#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int temp[10] = { 0, };
int nums[10] = { 0, };

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (arr[leftIdx] < arr[rightIdx])
			temp[tempIdx++] = arr[leftIdx++];
		else
			temp[tempIdx++] = arr[rightIdx++];
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
			temp[tempIdx++] = arr[rightIdx++];
	}
	else
	{
		while (leftIdx <= mid)
			temp[tempIdx++] = arr[leftIdx++];
	}

	for (int i = 0; i < tempIdx; ++i)
		arr[left + i] = temp[i];
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (right + left) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

void GetAnswer(int select_num, int select_num_max, int nums_index)
{
	if (select_num == 0)
	{
		for (int i = 0; i < select_num_max; ++i)
			cout << nums[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < arr.size(); ++i)
		{
			nums[nums_index] = arr[i];

			if (nums_index == 0)
				GetAnswer(select_num - 1, select_num_max, nums_index + 1);
			else
			{
				if (nums[nums_index] >= nums[nums_index - 1])
					GetAnswer(select_num - 1, select_num_max, nums_index + 1);
			}
		}
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	MergeSort(0, arr.size() - 1);
	
	GetAnswer(M, M, 0);
	return 0;
}