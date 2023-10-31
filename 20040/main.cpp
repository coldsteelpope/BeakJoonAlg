#include <iostream>
#include <vector>
#include <utility>

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
	DisjointSet(int n) : _parents(n, 0), _ranks(n, 0)
	{
		for (int node = 0; node < n; ++node)
		{
			_parents[node] = node;
			_ranks[node] = 0;
		}
	}

	int FindParent(int node)
	{
		if (this->_parents[node] == node)
			return this->_parents[node];
		this->_parents[node] = FindParent(this->_parents[node]);
		return this->_parents[node];
	}

	// node1의 rank가 node2의 rank보다 더 커야한다.
	bool Merge(int node1, int node2)
	{
		node1 = FindParent(node1);
		node2 = FindParent(node2);

		if (node1 == node2)
			return true;

		if (this->_ranks[node1] < this->_ranks[node2])
			SwapNode(node1, node2);
		
		this->_parents[node2] = node1;
		if (this->_ranks[node1] == this->_ranks[node2])
			++this->_ranks[node1];
		
		return false;
	}

private:
	vector<int> _parents;
	vector<int> _ranks;
};

vector<pair<int, int>> points;

int main(void)
{
	// n: 점의 개수, m: 차례의 수
	int n, m;
	cin >> n >> m;
	
	int turn_number = 1;
	bool cycleExisted = false;

	for (int i = 0; i < m; ++i)
	{
		int start_pos, target_pos;
		cin >> start_pos >> target_pos;
		points.push_back({ start_pos, target_pos });
	}
	
	DisjointSet disjointSet(n);
	for (int t = 0; t < m; ++t)
	{
		pair<int, int> current_points = points[t];
		cycleExisted = disjointSet.Merge(current_points.first, current_points.second);
		if (cycleExisted == true)
			break;
		++turn_number;
	}

	if (cycleExisted)
		cout << turn_number << endl;
	else
		cout << 0 << endl;
}