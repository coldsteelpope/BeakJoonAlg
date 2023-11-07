#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int leafNodeNum = 0;

int DFS(int here, int cuttingNode)
{
	if (here == cuttingNode)
	{
		return -1;
	}
	if (tree[here].size() == 0)
	{
		++leafNodeNum;
		return 0;
	}

	visited[here] = true;
	for (int there : tree[here])
	{
		if (visited[there] == true)
			continue;
		int tmp = DFS(there, cuttingNode);
		if (tmp == -1 && tree[here].size() == 1)
			++leafNodeNum;
	}
	return 0;
}

int main(void)
{
	int N; cin >> N;
	int root = 0;
	tree.resize(N + 1);
	visited.resize(N + 1, false);

	for (int node = 0; node < N; ++node)
	{
		int parent; cin >> parent;
		if (parent == -1)
		{
			root = node;
			continue;
		}
		tree[parent].push_back(node);
	}

	int cuttingNode; cin >> cuttingNode;

	DFS(root, cuttingNode);
	cout << leafNodeNum << endl;
	return 0;
}