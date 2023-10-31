#include <iostream>
#include <vector>

using namespace std;

typedef struct _NODE
{
	int _next;
	int _weight;
} Node;

vector<Node> nodes[10001];
bool visited[10001] = { 0, };

int maxVal = 0;
int endPoint = 0;
void Dfs(int here, int cost)
{
	visited[here] = true;
	if (maxVal < cost)
	{
		maxVal = cost;
		endPoint = here;
	}
	for (int there = 0; there < nodes[here].size(); ++there)
	{
		Node nextNode = nodes[here][there];
		if (visited[nextNode._next] == true)
			continue;
		Dfs(nextNode._next, cost + nextNode._weight);
	}
}

int main(void)
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n - 1; ++i)
	{
		int parent_num, child_num, weight;
		cin >> parent_num >> child_num >> weight;
		nodes[parent_num].push_back({ child_num, weight });
		nodes[child_num].push_back({ parent_num, weight });
	}
	Dfs(1, 0);
	for (int i = 0; i <= 10000; ++i)
		visited[i] = false;
	maxVal = 0;
	Dfs(endPoint, 0);
	cout << maxVal << endl;
	return 0;
}