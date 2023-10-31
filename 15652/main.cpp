#include <iostream>

using namespace std;

int answer[10] = { 0, };
void PrintAnswer(int N, int select_num, int select_num_max, int init_num, int index)
{
	if (select_num == 0)
	{
		for (int i = 0; i < select_num_max; ++i)
			cout << answer[i] << " ";
		cout << endl;
		return;
	}
	else
	{
		for (int i = init_num; i <= N; ++i)
		{
			answer[index] = i;
			PrintAnswer(N, select_num - 1, select_num_max, i, index + 1);
		}
	}
}

int main(void)
{
	// 1부터 N까지 자연수 중에서 M개를 고른 수열
	int N, M;
	cin >> N >> M;
	PrintAnswer(N, M, M, 1, 0);
}