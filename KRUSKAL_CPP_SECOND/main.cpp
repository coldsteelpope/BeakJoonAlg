#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class DisjointSet
{
public:
	DisjointSet(int n): _parent(n), _rank(n, 1)
	{
		// ó���� ��� �ڱ� �ڽ��� �θ��.
		for (int i = 0; i < n; ++i)
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
		// ���� ������ �ϴ� ������ �´�.
		u = Find(u);
		v = Find(v);

		// ���� ������ ���� ������ ��ĥ �ʿ䰡 ����.
		if (u == v)
			return;

		// �׻� v�� �� rank�� Ŀ���ϹǷ�, u�� rank�� v rank���� Ŭ ��, ������ �ڸ��� �ٲ��ش�.
		if (_rank[u] > _rank[v])
			swap(u, v);
		
		_parent[u] = v;
		if (_rank[u] == _rank[v])
			_rank[v]++;
	}

private:
	vector<int> _parent; // �ش� ���� �θ� ��� (����ȭ: ó�� �������� �ʱ�ȭ�Ұ��̴�)
	vector<int> _rank; // Ʈ���� ����
};

struct Vertex
{

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;


void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));

	adjacent[0][1] = 15;
	adjacent[0][3] = 35;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;
	adjacent[3][4] = 5;
	adjacent[3][5] = 10;
	adjacent[5][4] = 5;
}

struct Edge
{
	int _cost;
	int _u;
	int _v;
};

int Kruskal(vector<Edge>& selected)
{
	int ret = 0;
	selected.clear();

	vector<Edge> edges;
	for (int u = 0; u < adjacent.size(); ++u)
	{
		for (int v = 0; v < adjacent[u].size(); ++v)
		{
			int cost = adjacent[u][v];
			if (cost == -1)
				continue;
			edges.push_back(Edge{ cost, u, v });
		}
	}

	sort(edges.begin(), edges.end());
	
	
	DisjointSet sets(vertices.size());
	for (Edge& edge : edges)
	{
		if (sets.Find(edge._u) == sets.Find(edge._v))
		{
			continue;
		}

		sets.Merge(edge._u, edge._v);
		selected.push_back(edge);
		ret += edge._cost;
	}
	return ret;
}

int main(void)
{

}