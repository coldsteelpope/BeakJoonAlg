#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

bool dp[2001][2001] = { 0, };

int main(void)
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	arr.resize(N + 1, 0);
	
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	
	for (int i = 1; i <= N; ++i)
		dp[i][i] = true;

	for (int i = 1; i <= N - 1; ++i)
	{
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = true;
	}
	
	for (int len = 3; len <= N; ++len)
	{
		for (int i = 1; i <= (N - len + 1); ++i)
		{
			int j = i + len - 1;
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == true)
			{
				dp[i][j] = true;
			}
		}
	}
	
	int M;
	cin >> M;
	for (int t = 0; t < M; ++t)
	{
		int start_pointer = 0;
		int end_pointer = 0;

		cin >> start_pointer >> end_pointer;
		
		if (dp[start_pointer][end_pointer])
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}