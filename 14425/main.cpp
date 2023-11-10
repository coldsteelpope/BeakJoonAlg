#include <iostream>
#include <map>

using namespace std;

map<string, int> s;

void SetS(int N)
{

	for (int n = 0; n < N; ++n)
	{
		string str; cin >> str;
		s[str] += 1;
	}
}

int main(void)
{
	int N, M; cin >> N >> M;
	SetS(N);
	int answer = 0;
	for (int m = 0; m < M; ++m)
	{
		string str; cin >> str;
		auto item = s.find(str);
		if (item != s.end())
			++answer;
	}
	cout << answer << endl;
	return 0;
}