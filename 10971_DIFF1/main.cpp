#include <iostream>
#include <vector>

#define			MAX_NODE_NUM		10

using namespace std;

int g_iN = 0;
int g_iMinCost = INT32_MAX;
int g_iCostTable[MAX_NODE_NUM][MAX_NODE_NUM] = {0,};
bool g_bVisited[MAX_NODE_NUM] = { 0, };

void SetCostTable();
void DFS(int _iCurrentNode, int _iTargetNode, int _iCost, int _iDepth);

int main(void)
{
	cin >> g_iN;
	SetCostTable();
	DFS(0, 0, 0, 0);
	
	g_iMinCost = (g_iMinCost == INT32_MAX) ? 0 : g_iMinCost;
	cout << g_iMinCost << endl;

	return 0;
}

void SetCostTable()
{
	for (int i = 0; i < g_iN; ++i)
	{
		for (int j = 0; j < g_iN; ++j)
		{
			cin >> g_iCostTable[i][j];
		}
	}
}

void DFS(int _iCurrentNode, int _iTargetNode, int _iCost, int _iDepth)
{
	if (_iCurrentNode == _iTargetNode && _iDepth == g_iN)
	{
		g_iMinCost = (g_iMinCost > _iCost) ? _iCost : g_iMinCost;
		return;
	}

	if (g_bVisited[_iCurrentNode] == true)
	{
		return;
	}

	g_bVisited[_iCurrentNode] = true;
	for (int iNode = 0; iNode < g_iN; ++iNode)
	{
		if (g_iCostTable[_iCurrentNode][iNode] == 0)
		{
			continue;
		}
		DFS(iNode, _iTargetNode, _iCost + g_iCostTable[_iCurrentNode][iNode], _iDepth + 1);
	}
	g_bVisited[_iCurrentNode] = false;
}