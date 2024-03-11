#include <iostream>
#include <vector>

using namespace std;

vector<int> iArr;
vector<int> iTempArr;

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (iArr[leftIdx] <= iArr[rightIdx])
		{
			iTempArr.push_back(iArr[leftIdx++]);
		}
		else
		{
			iTempArr.push_back(iArr[rightIdx++]);
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			iTempArr.push_back(iArr[rightIdx++]);
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			iTempArr.push_back(iArr[leftIdx++]);
		}
	}

	for (int index = 0; index < iTempArr.size(); ++index)
	{
		iArr[left + index] = iTempArr[index];
	}
	iTempArr.clear();
}

void MergeSort(int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

int main(void)
{
	int iN;
	cin >> iN;

	for (int index = 0; index < iN; ++index)
	{
		int iNumber;
		cin >> iNumber;
		iArr.push_back(iNumber);
	}

	MergeSort(0, iArr.size() - 1);

	for (int iNumber : iArr)
	{
		cout << iNumber << "\n";
	}

	return 0;
}