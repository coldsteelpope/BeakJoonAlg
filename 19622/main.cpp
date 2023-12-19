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
	
	// �ؿ� �ִ� �ڵ带 �߰����� ������
	// if conferences[0]._num = 30, conferences[0]._num = 40�̶�� �� ��,
	// dp[0][0] = -1, dp[0][1] = 30
	// dp[1][0] = 30, dp[1][1] = dp[i - 1][0] + conferences[1]._num = -1 + 40 = 39...? �� �Ǿ���� Ʋ���� �ȴ�.
	// ���� dp[1][1], dp[1][0]�� �ʱ�ȭ���־�� �Ѵ�.
	dp[1][1] = conferences[1]._num; dp[1][0] = conferences[0]._num;


	for (int i = 2; i < N; ++i)
	{
		/*
		dp[i][0] = GetMax(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + conferences[i]._num;
		*/
		dp[i][0] = GetMax(dp[i - 1][0], dp[i - 1][1]); // ���� ȸ�Ǹ� �������� �ʴ� ���
		dp[i][1] = GetMax(dp[i - 1][0], dp[i - 2][1]) + conferences[i]._num; // ���� ȸ�Ǹ� �����ϴ� ���
		// ���� ȸ�Ǹ� �����ϴ� ���
		// i - 1��°�� ���õǸ� �ȵȴ�. why? k ȸ�Ǵ� k-1 ȸ�ǿ� k+1�� ��ġ�� ������
		// i - 2��°�� ������ �� �ִ�. why? k ȸ�Ǵ� k-1 ȸ�ǿ� k+1ȸ�Ǹ� ��ġ�� ������ �������� ���X
		// ���� i-1 ȸ�Ǹ� �������� �ʴ� ���� i-2 ȸ�ǰ� ���õ� ��� �� ���� ū dp���� �����ϰ� �ű⿡ ���� num�� ���ϸ�, ���� ȸ�Ǹ� �������� ��� ���� ���� ȸ�� �ο��� �ȴ�.
		// ù ��° ��ȭ�ĺ��� �� ���� ��ȭ���� �� ���ذ� �ߵȴ�.
	}

	cout << GetMax(dp[N - 1][0], dp[N - 1][1]) << "\n";
	return 0;
}