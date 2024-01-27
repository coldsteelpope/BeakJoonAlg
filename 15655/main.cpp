#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_LEN 8

using namespace std;


vector<int> arr;
int selectedArr[MAX_LEN] = { 0, };

void DFS(int depth, int N, int M, int startIdx)
{
	if (M == depth)
	{
		for (int index = 0; index < M; ++index)
		{
			cout << selectedArr[index] << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int index = startIdx; index < N; ++index)
		{
			selectedArr[depth] = arr[index];
			DFS(depth + 1, N, M, index + 1);
		}
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	for (int index = 0; index < N; ++index)
	{
		int num;
		cin >> num;
		arr.emplace_back(num);
	}

	std::sort(arr.begin(), arr.end());
	DFS(0, N, M, 0);
	return 0;
}