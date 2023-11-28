#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> positions;

inline int GetMin(int num1, int num2)
{
	return num1 > num2 ? num2 : num1;
}

inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

void Solution(int& fast_time, int& slow_time)
{
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < l; ++i)
	{
		int pos; cin >> pos;
		positions.emplace_back(pos);
	}
	std::sort(positions.begin(), positions.end());

	slow_time = ((n - positions[0]) > positions[l - 1]) ? (n - positions[0]) : positions[l - 1];
	
	fast_time = 0;
	for (int i = l - 1; i >= 0; --i)
	{
		int leftDist = positions[i];
		int rightDist = n - positions[i];
		int canFastTime = GetMin(leftDist, rightDist);
		fast_time = GetMax(fast_time, canFastTime);
	}
	positions.clear();
}

int main(void)
{
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; ++testCase)
	{
		int fastTime, slowTime;
		Solution(fastTime, slowTime);
		cout << fastTime << " " << slowTime << endl;
	}
	return 0;
}