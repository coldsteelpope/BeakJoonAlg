#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	map<string, string> notepad;
	for (int i = 0; i < N; ++i)
	{
		string siteurl, password;
		cin >> siteurl >> password;
		notepad.insert({ siteurl, password });
	}
	
	for (int i = 0; i < M; ++i)
	{
		string siteurl;
		cin >> siteurl;
		cout << notepad[siteurl] << "\n";
	}
	return 0;
}