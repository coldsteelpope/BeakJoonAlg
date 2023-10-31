#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void SwapNode(int& node1, int& node2)
{
	int temp = node1;
	node1 = node2;
	node2 = temp;
}

class DisjointSet
{
public:
	DisjointSet(int n) : _parents(n + 1, 0), _ranks(n + 1, 0)
	{
		for (int i = 0; i <= n; ++i)
		{
			_parents[i] = i;
			_ranks[i] = 0;
		}
	}

	int FindParent(int node)
	{
		if (this->_parents[node] == node)
			return this->_parents[node];
		this->_parents[node] = FindParent(this->_parents[node]);
		return this->_parents[node];
	}

	bool IsInSet(int node1, int node2)
	{
		node1 = FindParent(node1);
		node2 = FindParent(node2);
		return this->_parents[node1] == this->_parents[node2];
	}

	// node1의 rank가 node2의 rank보다 더 크다.
	void Merge(int node1, int node2)
	{
		node1 = FindParent(node1);
		node2 = FindParent(node2);

		if (node1 == node2)
			return;

		if (this->_ranks[node1] < this->_ranks[node2])
			SwapNode(node1, node2);

		this->_parents[node2] = node1;
		if (this->_ranks[node1] == this->_ranks[node2])
			++this->_ranks[node1];
	}

private:
	vector<int> _parents;
	vector<int> _ranks;
};

int main(void)
{

	int n, m;
	scanf("%d%d", &n, &m);
	
	
	DisjointSet disjointSet(n);
	for (int i = 0; i < m; ++i)
	{
		int command, num1, num2;
		scanf("%d%d%d", &command, &num1, &num2);

		if (command == 0)
		{
			disjointSet.Merge(num1, num2);
		}
		else if (command == 1)
		{
			bool result = disjointSet.IsInSet(num1, num2);
			if (result)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}

	return 0;
}