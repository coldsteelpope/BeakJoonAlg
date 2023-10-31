#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n + 1), _rank(n + 1, 1)
	{
		for (int i = 0; i <= n; ++i)
			_parent[i] = i;
	}

	int Find(int u)
	{
		if (u == _parent[u])
			return u;
		_parent[u] = Find(_parent[u]);
		return _parent[u];
	}

	void Merge(int u, int v) 
	{
		u = Find(u);
		v = Find(v);

		if (_rank[u] > _rank[v])
			swap(u, v);
		_parent[u] = v;
		
		if (_rank[u] == _rank[v])
			++_rank[v];
	}
private:
	vector<int> _parent;
	vector<int> _rank;
};

typedef struct _EDGE
{
	int _cost;
	int _u;
	int _v;
	
	bool operator<(_EDGE& other)
	{
		return _cost < other._cost;
	}
} Edge;

vector<vector<pair<int, int>>> adjacentList;
vector<Edge> edges;

void CreateGraph(int N, int M)
{
	adjacentList.resize(N + 1);
	for (int t = 0; t < M; ++t)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adjacentList[u].push_back({ v, cost });
	}
}

int Kruskal(int N, int M, vector<Edge>& selected)
{
	int ret = 0;
	for (int u = 1; u < adjacentList.size(); ++u)
	{
		for (int idx = 0; idx < adjacentList[u].size(); ++idx)
		{
			edges.push_back(Edge{ adjacentList[u][idx].second, u, adjacentList[u][idx].first });
		}
	}

	DisjointSet sets(N);
	sort(edges.begin(), edges.end());
	
	for (Edge& edge : edges)
	{
		if (sets.Find(edge._u) == sets.Find(edge._v))
			continue;
		sets.Merge(edge._u, edge._v);
		selected.push_back(edge);
		ret += edge._cost;
	}
	return ret;
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	CreateGraph(N, M);
	vector<Edge> selected;
	Kruskal(N, M, selected);
	selected.pop_back();
	
	long long sum = 0;
	for (int i = 0; i < selected.size(); ++i)
		sum += selected[i]._cost;

	cout << sum << endl;
	return 0;
}