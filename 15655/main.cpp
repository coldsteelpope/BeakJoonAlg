#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_LEN 9

using namespace std;

vector<int> arr;
int selectedArr[MAX_LEN];

void DFS(int count, int M, int N)
{
	if (count == M)
	{
		for (int index = 0; index < M; ++index)
		{
			cout << selectedArr[index] << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int index = 0; index < N; ++index)
		{
			selectedArr[count] = arr[index];
			DFS(count + 1, M, N);
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
	
	sort(arr.begin(), arr.end());
	DFS(0, M, N);
	return 0;
}