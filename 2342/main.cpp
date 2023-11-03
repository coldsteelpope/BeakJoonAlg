#include <iostream>
#include <cstring>
#include <algorithm>

#define INF 987654321
using namespace std;

int seqs[100001] = { 0, };
int seqLen = 1;
int weight[5][5] = { 0, };
int dp[100001][5][5] = { 0, };


// memo
// -1인지 체크하여, 이미 계산된 dp라면 그냥 반환 (또 다시 계산할 필요 X)
int move(int seqNum, int left, int right)
{
	if (seqNum == seqLen - 1)
		return 0;
	if ((left != 0 && right != 0) && left == right)
		return INF;

	if (dp[seqNum][left][right] != -1)
		return dp[seqNum][left][right];
	
	return dp[seqNum][left][right] = min(
		move(seqNum + 1, seqs[seqNum + 1], right) + weight[left][seqs[seqNum + 1]],
		move(seqNum + 1, left, seqs[seqNum + 1]) + weight[right][seqs[seqNum + 1]]
	);
}

void SetSeqs()
{
	while (true)
	{
		int num; cin >> num;
		if (num == 0)
			break;
		seqs[seqLen++] = num;
	}
	memset(dp, -1, sizeof(dp));
}

void SetWeight()
{
	for (int i = 0; i <= 4; ++i)
		weight[i][i] = 1;
	for (int i = 1; i <= 4; ++i)
	{
		weight[0][i] = 2;
	}
	weight[1][2] = weight[1][4] = weight[2][1] = weight[2][3] = weight[3][2] = weight[3][4] = weight[4][1] = weight[4][3] = 3;
	weight[1][3] = weight[2][4] = weight[3][1] = weight[4][2] = 4;
}

int main(void)
{
	SetSeqs();
	SetWeight();
	move(0, 0, 0);
	cout << dp[0][0][0] << endl;
	return 0;
}