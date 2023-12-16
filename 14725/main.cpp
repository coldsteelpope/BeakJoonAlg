#include <iostream>
#include <map>
#include <vector>

#define MAX_LEN 1000 * 15 + 5

using namespace std;

int root = 1;
int unused = 2;
// 자식 번호를 가지고 있다.
map<string, int> nxt[MAX_LEN];

void insert(vector<string>& v)
{
	int cur = root;
	for (auto s : v)
	{
		if (nxt[cur][s] == 0)
		{
			nxt[cur][s] = unused++;
		}
		cur = nxt[cur][s];
	}
}

void printTri(int cur, int level)
{
	for (auto m : nxt[cur])
	{
		for (int i = 0; i < level; ++i)
		{
			cout << "--";
		}
		cout << m.first << "\n";
		printTri(m.second, level + 1);
	}
}

int main(void)
{
	int N;
	cin >> N;
	for (int n = 0; n < N; ++n)
	{
		int K;
		cin >> K;
		vector<string> v(K);
		for (int k = 0; k < K; ++k)
		{
			cin >> v[k];
		}
		insert(v);
	}
	printTri(root, 0);
	return 0;
}