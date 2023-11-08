#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> gParents;

void SetgParents(int N)
{
	gParents.resize(N + 1, -1);
	for (int n = 0; n < N - 1; ++n)
	{
		int parent, child; cin >> parent >> child;
		gParents[child] = parent;
	}
}

void SetEleParents(int node, vector<int>& eleParents)
{
	eleParents.push_back(node);
	if (gParents[node] == -1)
		return;
	SetEleParents(gParents[node], eleParents);
}

void SwapVector(vector<int>& a, vector<int>& b)
{
	vector<int> temp = a;
	a = b;
	b = temp;
}

int BinarySearch(int left, int right, int value, vector<int>& arr)
{
	int result = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else if (arr[mid] > value)
			right = mid - 1;
		else
		{
			result = mid;
			break;
		}
	}
	return result;
}

int Solution()
{
	int N; cin >> N;
	SetgParents(N);

	int a, b; cin >> a >> b;
	vector<int> aParents, bParents;

	SetEleParents(a, aParents);
	SetEleParents(b, bParents);

	// a vector가 b vector보다 크기가 더 크다.
	if (aParents.size() < bParents.size())
		SwapVector(aParents, bParents);

	std::sort(aParents.begin(), aParents.end());
	int answer = -1;
	for (int i = 0; i < bParents.size(); ++i)
	{
		int result = BinarySearch(0, aParents.size() - 1, bParents[i], aParents);
		if (result != -1)
		{
			answer = bParents[i];
			break;
		}
	}
	return answer;
}

int main(void)
{
	int T; cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int result = Solution();
		cout << result << endl;
		gParents.clear();
	}
	return 0;
}