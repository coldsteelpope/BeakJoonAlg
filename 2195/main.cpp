#include <iostream>
using namespace std;

inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string S, P;
	cin >> S >> P;

	int Plen = P.size();
	int Slen = S.size();
	int answer = 0;

	for (int pPointer = 0; pPointer < Plen; ++pPointer)
	{
		int maxLen = 0;
		for (int sPointer = 0; sPointer < Slen; ++sPointer)
		{
			if (P[pPointer] == S[sPointer])
			{
				int len = 0;
				while ((P[len + pPointer] == S[len + sPointer]) && (pPointer + len != Plen) && (sPointer + len != Slen))
				{
					++len;
				}
				maxLen = GetMax(maxLen, len);
			}
		}
		pPointer = pPointer + maxLen - 1;
		++answer;
	}
	cout << answer << "\n";
	return 0;
}