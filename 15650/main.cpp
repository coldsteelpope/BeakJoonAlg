#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int num[10] = { 0, };
void getAnswer(int max_num, int select_num, int len, int init_num, int index)
{
	if (select_num == 0)
	{
		for (int i = 0; i < len; ++i)
			cout << num[i] << " ";
		cout << endl;
		return;
	}
	else
	{
		for (int i = init_num; i <= max_num; ++i)
		{
			num[index] = i;
			getAnswer(max_num, select_num - 1, len, i + 1, index + 1);
		}
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; ++i)
		arr.push_back(i);
	getAnswer(N, M, M, 1, 0);
}