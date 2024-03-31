#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> vDsts;
vector<bool> visited;

void DFS(int _index)
{
	visited[_index] = true;
	
	int iCurrentIndex = vDsts[_index].first;
	int iNextDstIndex = vDsts[_index].second;

	if (visited[iNextDstIndex] == false)
	{
		DFS(iNextDstIndex);
	}
}

int main(void)
{
	int iT;
	cin >> iT;
	for (int t = 0; t < iT; ++t)
	{
		int iN;
		cin >> iN;
		for (int i = 0; i < iN; ++i)
		{
			int iDst;
			cin >> iDst;
			vDsts.push_back({ i , iDst - 1 });
		}
		visited.resize(iN, false);

		int iResult = 0;
		for (int i = 0; i < vDsts.size(); ++i)
		{
			pair<int, int> currentVDst = vDsts[i];
			if (visited[currentVDst.first] == false)
			{
				++iResult;
				DFS(currentVDst.first);
			}
		}
		cout << iResult << endl;
		vDsts.clear();
		visited.clear();
	}

	return 0;
}