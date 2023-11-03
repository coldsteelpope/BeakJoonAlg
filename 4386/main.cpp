#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjacentMatrix;

class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n, 0), _rank(n, 0) {};

	int FindParent(int node)
	{
		if (this->_parent[node] == node)
			return this->_parent[node];
		// ÃÖÀûÈ­
		this->_parent[node] = FindParent(node);
		return this->_parent[node];
	}

	void Merge(int node1, int node2)
	{
		node1 = FindParent(node1);
		node2 = FindParent(node2);

		if (node1 == node2)
			return;

		if (this->_rank[node1] < this->_rank[node2])
			SwapNode(node1, node2);

		this->_parent[node2] = node1;
		if (this->_rank[node1] == this->_rank[node2])
			++this->_rank[node1];
	}

private:
	void SwapNode(int& node1, int& node2)
	{
		int temp = node1;
		node1 = node2;
		node2 = temp;
	}

	vector<int> _parent;
	vector<int> _rank;
};

void SetAdjacentMatrix()
{
	int N; cin >> N;
	adjacentMatrix.resize(N + 1, vector<int>(N + 1, 0));
	
}

int main(void)
{

}