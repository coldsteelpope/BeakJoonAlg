#include <iostream>
#include <string>
#include <memory>

using namespace std;

#define MAX_LEN 1001

int g_iCall = 0;
char szBuffer[MAX_LEN] = { 0, };

int DFS(const char* _str, int _l, int _r);
int GetStrLen(const char* _str);
void ClearStatus(int _iStrLen);

int main(void)
{
	int iT;
	cin >> iT;
	for (int t = 0; t < iT; ++t)
	{
		cin >> szBuffer;
		int strLen = GetStrLen(szBuffer);
		int iResult = DFS(szBuffer, 0, strLen - 1);
		cout << iResult << " " << g_iCall << endl;
		ClearStatus(strLen);

	}
	return 0;
}

int GetStrLen(const char* _str)
{
	int iResult = 0;
	while (_str[iResult] != '\0')
	{
		++iResult;
	}
	return iResult;
}

int DFS(const char* _str, int _l, int _r)
{
	if (_l >= _r)
	{
		++g_iCall;
		return 1;
	}
	else if (_str[_l] != _str[_r])
	{
		++g_iCall;
		return 0;
	}
	else
	{
		++g_iCall;
		return DFS(_str, _l + 1, _r - 1);
	}
}

void ClearStatus(int _iStrLen)
{
	for (int i = 0; i < _iStrLen; ++i)
	{
		szBuffer[i] = 0;
	}
	g_iCall = 0;
}
