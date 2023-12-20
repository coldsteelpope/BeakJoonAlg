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

	// �ش� �ڵ尡 �� ���ذ� �ߵȴ�.
	for (int i = 1; i <= N + 1; ++i)
	{
		// �� ���� �� �����ϴ�.
		// dp�� i�� ° �ִ� ���� �� �ִ� ����. ����, ������ �ִ� ���� �״�� �̾����� �Ѵ�(dp[i - 1] vs dp[i]).
		dp[i] = GetMax(dp[i - 1], dp[i]);
		if (i + schedules[i].first > N + 1)
		{
			// dp size�� N + 2�� �����߱� ������, �ε����� N + 1�� �Ѿ�� ���̰� N + 2�� �Ѿ out of range error�� �߻��� ���̴�.
			// ����, continue�� �� �̻� ����Ǵ� ���� ��������!
			continue;
		}
		dp[i + schedules[i].first] = GetMax(dp[i + schedules[i].first], dp[i] + schedules[i].second);
	}
	cout << dp[N + 1] << "\n";
	return 0;
}