#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<double>> adjacentMatrix;
vector<pair<double, double>> coordinates;

inline double GetAbs(double num)
{
	return num > 0 ? num : -num;
}

double GetDistance(pair<double, double> startCord, pair<double, double> targetCord)
{
	double startCordX = startCord.first;
	double startCordY = startCord.second;
	double targetCordX = targetCord.first;
	double targetCordY = targetCord.second;

	double diffX = GetAbs(startCordX - targetCordX);
	double diffY = GetAbs(startCordY - targetCordY);

	return sqrt((diffX * diffX) + (diffY * diffY));
}

class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n + 1, 0), _rank(n + 1, 0) 
	{
		for (int i = 0; i <= n; ++i)
		{
			this->_parent[i] = i;
		}
	};

	int FindParent(int node)
	{
		if (this->_parent[node] == node)
			return node;
		// ÃÖÀûÈ­
		this->_parent[node] = FindParent(this->_parent[node]);
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

void SetAdjacentMatrix(int N)
{

	adjacentMatrix.resize(N + 1, vector<double>(N + 1, -1));
	coordinates.push_back({ 0.0, 0.0 });
	for (int n = 0; n < N; ++n)
	{
		double x, y; cin >> x >> y;
		coordinates.push_back({ x, y });
	}

	for (int start_node = 1; start_node <= N; ++start_node)
	{
		for (int target_node = start_node; target_node <= N; ++target_node)
		{
			if (start_node == target_node)
				adjacentMatrix[start_node][target_node] = 0.0;
			else
				adjacentMatrix[start_node][target_node] = GetDistance(coordinates[start_node], coordinates[target_node]);
		}
	}
}

struct CostEdge
{
	double cost;
	int start_node;
	int target_node;
	bool operator<(CostEdge& other)
	{
		return cost < other.cost;
	}
};

double Kruskal(vector<CostEdge>& selected, int N)
{
	double ret = 0.0;
	selected.clear();

	vector<CostEdge> edges;
	for (int start_node = 1; start_node <= N; ++start_node)
	{
		for (int target_node = 1; target_node <= N; ++target_node)
		{
			double cost = adjacentMatrix[start_node][target_node];
			if (cost == -1.0 || cost == 0.0)
				continue;
			edges.push_back(CostEdge{ cost, start_node, target_node });
		}
	}
	
	std::sort(edges.begin(), edges.end());
	DisjointSet sets(N);
	
	for (CostEdge& edge : edges)
	{
		if (sets.FindParent(edge.start_node) == sets.FindParent(edge.target_node))
			continue;
		sets.Merge(edge.start_node, edge.target_node);
		selected.push_back(edge);
		ret += edge.cost;
	}

	return ret;
}

int main(void)
{
	int N; cin >> N;
	SetAdjacentMatrix(N);
	vector<CostEdge> selected;
	double cost = Kruskal(selected, N);
	cout.precision(3);
	cout << cost << endl;
	return 0;
}