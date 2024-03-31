#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define		MAX_NODE_NUM		10
#define		INT_MAX				2147483647

int g_iN;
int g_iCostTable[MAX_NODE_NUM][MAX_NODE_NUM] = { 0, };
int g_iMinCost = INT_MAX;
bool g_bVisited[MAX_NODE_NUM] = { 0, };

void DFS(int _currentNode, int _iCost, int _iDepth, int _iStartNode);
void SetCostTable();
bool CheckAllVisited();

int main(void)
{
	scanf("%d", &g_iN);
	SetCostTable(g_iN);
	DFS(0, 0, 0, 0);

	if (g_iMinCost == INT_MAX)
	{
		printf("%d\n", 0);
	}
	else
	{
		printf("%d\n", g_iMinCost);
	}
	
	return 0;
}

void DFS(int _currentNode, int _iCost, int _iDepth, int _iStartNode)
{
	if (CheckAllVisited() == true && _iDepth == g_iN && _iStartNode == _currentNode)
	{
		g_iMinCost = (g_iMinCost > _iCost) ? _iCost : g_iMinCost;
		return;
	}

	for (int iNode = 0; iNode < g_iN; ++iNode)
	{
		if (g_iCostTable[_currentNode][iNode] == 0 || g_bVisited[iNode] == true)
		{
			continue;
		}

		g_bVisited[iNode] = true;
		DFS(iNode, _iCost + g_iCostTable[_currentNode][iNode], _iDepth + 1, _iStartNode);
		g_bVisited[iNode] = false;
	}
}

void SetCostTable(int _iN)
{
	for (int i = 0; i < _iN; ++i)
	{
		for (int j = 0; j < _iN; ++j)
		{
			scanf("%d", &g_iCostTable[i][j]);
		}
	}
}

bool CheckAllVisited()
{
	for (int iNode = 0; iNode < g_iN; ++iNode)
	{
		if (g_bVisited[iNode] == false)
		{
			return false;
		}
	}
	return true;
}