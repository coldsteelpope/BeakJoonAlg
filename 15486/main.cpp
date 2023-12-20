#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// first: T, second: P
vector<pair<int, int>> schedules;
vector<int> dp;

inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

void PrintDP(int N)
{
	for (int i = 0; i <= N; ++i)
	{
		cout << dp[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	int N;
	cin >> N;

	schedules.resize(N + 2);
	dp.resize(N + 2, 0);

	for (int i = 1; i <= N; ++i)
	{
		cin >> schedules[i].first >> schedules[i].second;
	}

	// 해당 코드가 더 이해가 잘된다.
	for (int i = 1; i <= N + 1; ++i)
	{
		// 이 식이 더 간단하다.
		// dp는 i일 째 최대 얻을 수 있는 월급. 따라서, 기존의 최대 값이 그대로 이어져야 한다(dp[i - 1] vs dp[i]).
		dp[i] = GetMax(dp[i - 1], dp[i]);
		if (i + schedules[i].first > N + 1)
		{
			// dp size를 N + 2로 제한했기 때문에, 인덱스가 N + 1이 넘어가면 길이가 N + 2가 넘어가 out of range error가 발생할 것이다.
			// 따라서, continue로 더 이상 진행되는 것을 막아주자!
			continue;
		}
		dp[i + schedules[i].first] = GetMax(dp[i + schedules[i].first], dp[i] + schedules[i].second);
	}
	cout << dp[N + 1] << "\n";
	return 0;
}