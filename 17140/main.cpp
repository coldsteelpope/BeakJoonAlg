#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

int A[101][101] = { 0, };
int R = 3, C = 3;

vector<pair<int, int>> temp(100);

int inline GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

void MergeResult(int left, int mid, int right, vector<pair<int, int>>& v)
{
	int lowPointer = left;
	int highPointer = mid + 1;
	int tempIdx = 0;

	while (lowPointer <= mid && highPointer <= right)
	{
		if (v[lowPointer].second < v[highPointer].second)
		{
			temp[tempIdx++] = v[lowPointer++];
		}
		else if (v[lowPointer].second > v[highPointer].second)
		{
			temp[tempIdx++] = v[highPointer++];
		}
		else
		{
			if (v[lowPointer].first <= v[highPointer].first)
			{
				temp[tempIdx++] = v[lowPointer++];
			}
			else
			{
				temp[tempIdx++] = v[highPointer++];
			}
		}
	}

	if (mid < lowPointer)
	{
		while (highPointer <= right)
		{
			temp[tempIdx++] = v[highPointer++];
		}
	}
	else
	{
		while (lowPointer <= mid)
		{
			temp[tempIdx++] = v[lowPointer++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		v[left + i] = temp[i];
	}
}

void MergeSort(int left, int right, vector<pair<int, int>>& v)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(left, mid, v);
	MergeSort(mid + 1, right, v);
	MergeResult(left, mid, right, v);
}


void SetA()
{
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			cin >> A[i][j];
		}
	}
}

void RowCal()
{
	int maxC = 0;
	for (int r = 1; r <= R; ++r)
	{
		map<int, int> m;
		for (int c = 1; c <= C; ++c)
		{
			if (A[r][c] == 0)
			{
				continue;
			}
			m[A[r][c]] += 1;
		}
		map<int, int>::iterator it;
		vector<pair<int, int>> arr;
		for (it = m.begin(); it != m.end(); ++it)
		{
			arr.push_back({ it->first, it->second });
		}
		MergeSort(0, arr.size() - 1, arr);
		int arrIdx = 0; int i = 1;
		int newCLen = 0;
		for (i = 1; i <= 100 && arrIdx < arr.size(); i += 2)
		{
			A[r][i] = arr[arrIdx].first;
			A[r][i + 1] = arr[arrIdx].second;
			++arrIdx;
			newCLen += 2;
		}

		for (int remainderIdx = i; remainderIdx <= 100; ++remainderIdx)
		{
			A[r][remainderIdx] = 0;
		}
		maxC = GetMax(maxC, newCLen);
	}
	C = (maxC != C) ? maxC : C;
}

void ColCal()
{
	int maxR = 0;
	for (int c = 1; c <= C; ++c)
	{
		map<int, int> m;
		for (int r = 1; r <= R; ++r)
		{
			if (A[r][c] == 0)
			{
				continue;
			}
			m[A[r][c]] += 1;
		}
		map<int, int>::iterator it;
		vector<pair<int, int>> arr;
		for (it = m.begin(); it != m.end(); ++it)
		{
			arr.push_back({ it->first, it->second });
		}
		MergeSort(0, arr.size() - 1, arr);
		
		int arrIdx = 0, i = 1, newRLen = 0;
		for (i = 1; i <= 100 && arrIdx < arr.size(); i += 2)
		{
			A[i][c] = arr[arrIdx].first;
			A[i + 1][c] = arr[arrIdx].second;
			++arrIdx;
			newRLen += 2;
		}

		for (int remainderIdx = i; remainderIdx <= 100; ++remainderIdx)
		{
			A[remainderIdx][c] = 0;
		}
		maxR = GetMax(maxR, newRLen);
	}
	R = (maxR != R) ? maxR : R;
}

//void PrintA()
//{
//	cout << endl;
//	for (int i = 1; i <= R; ++i)
//	{
//		for (int j = 1; j <= C; ++j)
//		{
//			cout << A[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}

int main(void)
{
	int r, c, k;
	cin >> r >> c >> k;
	SetA();
	
	bool find = false;
	int answer = 0;
	for (int t = 0; t <= 100; ++t)
	{
		if (A[r][c] == k)
		{
			find = true;
			break;
		}
		if (R >= C)
		{
			RowCal();
			++answer;
		}
		else
		{
			ColCal();
			++answer;
		}
	}

	if (find)
	{
		cout << answer << endl;
	}
	else
	{
		cout << -1 << endl;
	}

	return 0;
}
