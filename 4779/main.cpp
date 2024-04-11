#include <iostream>

#define	MAX_LEN		531442

using namespace std;

char cStr[MAX_LEN] = { 0, };

void DFS(int _iStart, int _iEnd);
void SetStr(int _iStrLen);
int GetStrLen(int _iN);

int main(void)
{
	while (true)
	{
		int iN;
		cin >> iN;
		if (cin.eof())
		{
			break;
		}
		int iStrLen = GetStrLen(iN);
		SetStr(iStrLen);
		DFS(0, iStrLen);
		for (int i = 0; i < iStrLen; ++i)
		{
			cout << cStr[i];
		}
		cout << endl;
	}
	return 0;
}

void DFS(int _iStart, int _iEnd)
{
	if (_iStart >= _iEnd - 1)
	{
		return;
	}

	int iLimitStart = _iStart + ((_iEnd - _iStart) / 3);
	int iLimitEnd = _iStart + (((_iEnd - _iStart) / 3) * 2);

	for (int i = iLimitStart; i < iLimitEnd; ++i)
	{
		cStr[i] = ' ';
	}

	DFS(_iStart, iLimitStart);
	DFS(iLimitEnd, _iEnd);
}

void SetStr(int _iStrLen)
{
	for (int i = 0; i < _iStrLen; ++i)
	{
		cStr[i] = '-';
	}
}

int GetStrLen(int _iN)
{
	int iResult = 1;
	for (int i = 0; i < _iN; ++i)
	{
		iResult *= 3;
	}
	return iResult;
}