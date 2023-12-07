#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class DisjointSet
{
public:
	DisjointSet(int n)
	{
		this->_parents.resize(n + 1, 0);
		this->_ranks.resize(n + 1, 0);

		for (int i = 0; i <= n; ++i)
		{
			this->_parents[i] = i;
		}
	}

	int FindParent(int node)
	{
		if (this->_parents[node] == node)
			return node;
		this->_parents[node] = FindParent(this->_parents[node]);
		return this->_parents[node];
	}

	void Merge(int node1, int node2)
	{
		node1 = FindParent(node1);
		node2 = FindParent(node2);
		
		if (node1 == node2)
		{
			return;
		}
		
		if (this->_ranks[node1] < this->_ranks[node2])
			SwapNode(node1, node2);

		this->_parents[node2] = node1;
		if (this->_ranks[node1] == this->_ranks[node2])
		{
			++this->_ranks[node1];
		}
	}

private:
	void SwapNode(int& num1, int& num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

private:
	vector<int> _parents;
	vector<int> _ranks;
};

class Edge
{
public:
	Edge(int start, int target, int cost) : _start(start), _target(target), _cost(cost) { }
	
	bool operator > (const Edge& other) const
	{
		return this->_cost > other._cost;
	}

	bool operator < (const Edge& other) const
	{
		return this->_cost < other._cost;
	}

	bool operator == (const Edge& other) const
	{
		return this->_cost == other._cost;
	}


	int GetStart()
	{
		return this->_start;
	}
	
	int GetTarget()
	{
		return this->_target;
	}

	int GetCost()
	{
		return this->_cost;
	}
private:
	int _start;
	int _target;
	int _cost;
};

vector<vector<pair<int ,int>>> adjacentList;

void SetAdjacentList(int N, int M)
{
	adjacentList.resize(N + 1);
	for (int m = 0; m < M; ++m)
	{
		int start, target, cost;
		cin >> start >> target >> cost;
		adjacentList[start].push_back({ target, cost });
		adjacentList[target].push_back({ start, cost });
	}
}

vector<Edge> KruskalAlg(int N, int M)
{
	vector<Edge> edges;
	for (int node = 1; node <= N; ++node)
	{
		for (int otherNodeIdx = 0; otherNodeIdx < adjacentList[node].size(); ++otherNodeIdx)
		{
			pair<int, int> otherNode = adjacentList[node][otherNodeIdx];
			if (node > otherNode.first)
				continue;
			edges.push_back(Edge(node, otherNode.first, otherNode.second));
		}
	}

	std::sort(edges.begin(), edges.end(), less<Edge>());
	
	vector<Edge> result;
	DisjointSet s(N);
	for (int i = 0; i < edges.size(); ++i)
	{
		int start = edges[i].GetStart();
		int target = edges[i].GetTarget();
		
		if (s.FindParent(start) == s.FindParent(target))
		{
			continue;
		}
		s.Merge(start, target);
		result.push_back(edges[i]);
	}

	return result;
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	SetAdjacentList(N, M);
	vector<Edge> graph = KruskalAlg(N, M);
	
	int sum = 0;
	for (int i = 0; i < graph.size(); ++i)
	{
		sum += graph[i].GetCost();
	}
	
	cout << sum << endl;
	return 0;
}