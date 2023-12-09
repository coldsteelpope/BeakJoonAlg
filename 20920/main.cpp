#include <iostream>
#include <vector>
#include <utility>
#include <map>
#define MAX_LEN 100001

using namespace std;

map<string, int> m;
vector<pair<int, string>> v(MAX_LEN);
vector<pair<int, string>> temp(MAX_LEN);

void MergeResult(int left, int mid, int right)
{
	int leftPointer = left;
	int rightPointer = mid + 1;

	int tempIdx = 0;
	while (leftPointer <= mid && rightPointer <= right)
	{
		if (v[leftPointer].first > v[rightPointer].first)
		{
			temp[tempIdx++] = v[leftPointer++];
		}
		else if(v[leftPointer].first < v[rightPointer].first)
		{
			temp[tempIdx++] = v[rightPointer++];
		}
		else
		{
			if (v[leftPointer].second.size() > v[rightPointer].second.size())
			{
				temp[tempIdx++] = v[leftPointer++];
			}
			else if (v[leftPointer].second.size() < v[rightPointer].second.size())
			{
				temp[tempIdx++] = v[rightPointer++];
			}
			else
			{
				if (v[leftPointer].second <= v[rightPointer].second)
				{
					temp[tempIdx++] = v[leftPointer++];
				}
				else if (v[leftPointer].second > v[rightPointer].second)
				{
					temp[tempIdx++] = v[rightPointer++];
				}
			}
		}
	}

	if (mid < leftPointer)
	{
		while (rightPointer <= right)
		{
			temp[tempIdx++] = v[rightPointer++];
		}
	}
	else
	{
		while (leftPointer <= mid)
		{
			temp[tempIdx++] = v[leftPointer++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		v[left + i] = temp[i];
	}
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

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		if (str.size() < M)
			continue;
		m[str] += 1;
	}
	

	int vIdx = 0;
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		v[vIdx++] = make_pair(it->second, it->first);
	}

	MergeSort(0, vIdx - 1);
	for (int i = 0; i < vIdx; ++i)
	{
		cout << v[i].second << "\n";
	}
	return 0;
}