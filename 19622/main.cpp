#include <iostream>
#include <vector>

#define MAX_LEN 100001

using namespace std;

typedef struct _CONF
{
	long long _startT;
	long long _endT;
	long long _num;
} Conference;

long long dp[MAX_LEN][2] = { 0, };

inline long long GetMax(long long a, long long b)
{
	return a > b ? a : b;
}

int main(void)
{
	int N;
	cin >> N;
	vector<Conference> conferences(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> conferences[i]._startT >> conferences[i]._endT >> conferences[i]._num;
	}

	for (int i = 0; i < N; ++i)
	{
		dp[i][0] = -1; dp[i][1] = -1;
	}
	
	dp[0][1] = conferences[0]._num;
	
	// 밑에 있는 코드를 추가하지 않으면
	// if conferences[0]._num = 30, conferences[0]._num = 40이라고 할 때,
	// dp[0][0] = -1, dp[0][1] = 30
	// dp[1][0] = 30, dp[1][1] = dp[i - 1][0] + conferences[1]._num = -1 + 40 = 39...? 가 되어버려 틀리게 된다.
	// 따라서 dp[1][1], dp[1][0]도 초기화해주어야 한다.
	dp[1][1] = conferences[1]._num; dp[1][0] = conferences[0]._num;


	for (int i = 2; i < N; ++i)
	{
		/*
		dp[i][0] = GetMax(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + conferences[i]._num;
		*/
		dp[i][0] = GetMax(dp[i - 1][0], dp[i - 1][1]); // 현재 회의를 선택하지 않는 경우
		dp[i][1] = GetMax(dp[i - 1][0], dp[i - 2][1]) + conferences[i]._num; // 현재 회의를 선택하는 경우
		// 현재 회의를 선택하는 경우
		// i - 1번째는 선택되면 안된다. why? k 회의는 k-1 회의와 k+1이 겹치기 때문에
		// i - 2번째는 선택할 수 있다. why? k 회의는 k-1 회의와 k+1회의만 겹치기 때문에 나머지는 상관X
		// 따라서 i-1 회의를 선택하지 않는 경우와 i-2 회의가 선택된 경우 중 가장 큰 dp값을 선택하고 거기에 현재 num을 더하면, 현재 회의를 선택했을 경우 가장 많은 회의 인원이 된다.
		// 첫 번째 점화식보다 두 번쨰 점화식이 더 이해가 잘된다.
	}

	cout << GetMax(dp[N - 1][0], dp[N - 1][1]) << "\n";
	return 0;
}