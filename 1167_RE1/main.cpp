#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int len = 0;
int node = 0;

vector<vector<pair<int, int>>> adjacentList;
vector<bool> visited;

void DFS(int here, int sum)
{
	if (len < sum)
	{
		len = sum;
		node = here;
	}
	visited[here] = true;

	for (int i = 0; i < adjacentList[here].size(); ++i)
	{
		pair<int, int> there = adjacentList[here][i];
		if (visited[there.first] == true)
		{
			continue;
		}
		DFS(there.first, sum + there.second);
	}
}

void Input(int N)
{
	adjacentList.resize(N + 1);
	visited.resize(N + 1);

	vector<int> inputs;
	for (int i = 1; i <= N; ++i)
	{
		int num = 0;
		while (num != -1)
		{
			cin >> num;
			inputs.emplace_back(num);
		}
		for (int j = 1; inputs[j] != -1; j += 2)
		{
			adjacentList[inputs[0]].push_back(make_pair(inputs[j], inputs[j + 1]));
		}
		inputs.clear();
	}
}

int main(void)
{
	int N;
	cin >> N;

	Input(N);
	
	node = 1;
	len = 0;

	DFS(node, len);
	
	fill(visited.begin(), visited.end(), false);
	len = 0;
	DFS(node, len);
	cout << len << "\n";
	return 0;
}