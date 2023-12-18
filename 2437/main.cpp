#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> weights;

int main(void)
{
	int N;
	cin >> N;
	weights.resize(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> weights[i];
	}

	// �׻� sorting�� ���Դ´� ��������
	std::sort(weights.begin(), weights.end());

	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (weights[i] > sum + 1)
		{
			break;
		}
		sum += weights[i];
	}
	cout << ++sum << "\n";
	return 0;
}