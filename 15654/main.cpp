#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int num[10] = { 0, };
int temp[10] = { 0, };



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
	int mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

void GetAnswer(int select_num, int select_num_max, int num_index, int first_num)
{
	if (select_num == 0)
	{
		for (int i = 0; i < select_num_max; ++i)
			cout << num[i] << " ";
		cout << "\n";
	}
	else
	{
		for (int i = 0; i < arr.size(); ++i)
		{
			num[num_index] = arr[i];
			if (select_num == select_num_max)
				GetAnswer(select_num - 1, select_num_max, num_index + 1, num[0]);
			else
			{
				// 선택한 수 존재?
				bool isSelectedNum = false;
				for (int j = 0; j < select_num_max - select_num; ++j)
				{
					if (arr[i] == num[j])
					{
						isSelectedNum = true;
						break;
					}
				}

				if (isSelectedNum)
					continue;
				else
				{
					GetAnswer(select_num - 1, select_num_max, num_index + 1, first_num);
				}
			}
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	MergeSort(0, arr.size() - 1);
	GetAnswer(M, M, 0, arr[0]);
	return 0;
}