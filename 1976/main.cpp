#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> boardMap;
vector<int> paths;

class DisjointSet
{
public:
	DisjointSet(int n) : _parents(n + 1, 0), _ranks(n + 1, 0)
	{
		for (int i = 0; i <= n; ++i)
		{
			this->_parents[i] = i;
		}
	}

	int FindParent(int node)
	{
		if (this->_parents[node] == node)
			return this->_parents[node];
		this->_parents[node] = FindParent(this->_parents[node]);
		return this->_parents[node];
	}

	int GetParent(int node)
	{
		return this->_parents[node];
	}

	void Merge(int node1, int node2)
	{
		node1 = FindParent(node1);
		node2 = FindParent(node2);

		if (node1 == node2)
			return;
		
		// rank(node1) < rank(node2) 만족해야 하므로
		if (this->_ranks[node1] > this->_ranks[node2])
			SwapNode(node1, node2);

		this->_parents[node1] = node2;
		if (this->_ranks[node1] == this->_ranks[node2])
			++this->_ranks[node2];
	}
private:
	void SwapNode(int& node1, int& node2)
	{
		int temp = node1;
		node1 = node2;
		node2 = temp;
	}
	vector<int> _parents;
	vector<int> _ranks;
};

struct Edge
{
	int _cost;
	int _start;
	int _target;
	
	bool operator<(Edge& other)
	{
		return _cost < other._cost;
	}
};


void SetBoardMap(int N)
{
	boardMap.resize(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> boardMap[i][j];
}

void SetPaths(int M)
{
	for (int m = 0; m < M; ++m)
	{
		int number; cin >> number;
		paths.push_back(number);
	}
}



int main(void)
{
	int N, M;
	cin >> N >> M;
	
	SetBoardMap(N);
	SetPaths(M);

	DisjointSet sets(N);
	for (int startNode = 1; startNode <= N; ++startNode)
	{
		for (int targetNode = 1; targetNode <= N; ++targetNode)
		{
			if (startNode >= targetNode)
				continue;
			int cost = boardMap[startNode][targetNode];
			if (cost == 0)
				continue;
			
			if (sets.FindParent(startNode) == sets.FindParent(targetNode))
				continue;
			else
				sets.Merge(startNode, targetNode);
		}
	}

	

	vector<int> pathParents;
	for (int i = 0; i < paths.size(); ++i)
	{
		sets.FindParent(paths[i]);
		pathParents.push_back(sets.GetParent(paths[i]));
	}
		

	bool isSame = true;
	int firstEle = pathParents[0];
	for (int i = 1; i < pathParents.size(); ++i)
	{
		if (firstEle != pathParents[i])
		{
			isSame = false;
			break;
		}
	}

	if (isSame)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}