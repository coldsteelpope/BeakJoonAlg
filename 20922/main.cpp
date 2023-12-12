#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> m;
vector<int> v;

int main(void)
{
	int N, K;
	cin >> N >> K;
	v.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	int lowPointer = 0;
	int highPointer = 0;

	int vectorSize = v.size();
	m[v[lowPointer]] += 1;

	int maxLen = 0;
	while (lowPointer <= highPointer)
	{
		bool hate = false;
		if (m[v[highPointer]] > K)
		{
			hate = true;
		}

		if (highPointer == vectorSize - 1)
		{
			if (hate == true)
			{
				--m[v[lowPointer++]];
			}
			else
			{
				int len = highPointer - lowPointer + 1;
				maxLen = (maxLen > len) ? maxLen : len;
				--m[v[lowPointer++]];
			}
		}
		else
		{
			if (hate == true)
			{
				--m[v[lowPointer++]];
			}
			else
			{
				int len = highPointer - lowPointer + 1;
				maxLen = (maxLen > len) ? maxLen : len;
				m[v[++highPointer]]++;
			}
		}
	}

	cout << maxLen << endl;
	return 0;
}