#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct _COM
{
	int _num;
	int _hack;
	int _parentnum;
	struct _COM* _parent;
} Com;

Com* coms[10001];
bool visited[10001] = { 0, };
Com* temp[10001];

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (coms[leftIdx]->_hack > coms[rightIdx]->_hack)
		{
			temp[tempIdx++] = coms[leftIdx++];
		}
		else if (coms[leftIdx]->_hack < coms[rightIdx]->_hack)
		{
			temp[tempIdx++] = coms[rightIdx++];
		}
		else
		{
			if (coms[leftIdx]->_num < coms[rightIdx]->_num)
			{
				temp[tempIdx++] = coms[leftIdx++];
			}
			else
			{
				temp[tempIdx++] = coms[rightIdx++];
			}
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = coms[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = coms[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		coms[left + i] = temp[i];
	}
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

void Dfs(int computer_num, int* hacked_computers_num)
{
	visited[computer_num] = true;
	int p_index = 0;
	int parent_num = coms[computer_num]->_parentnum;
	
	Com* parentCom = coms[computer_num]->_parent;
	while (parentCom != NULL)
	{
		if (visited[parentCom->_num] == true)
		{
			parentCom = parentCom->_parent;
			continue;
		}
		++(*hacked_computers_num);
		Dfs(parentCom->_num, hacked_computers_num);
		parentCom = parentCom->_parent;
	}
}

void DfsAll(int N)
{
	for (int computer_num = 1; computer_num <= N; ++computer_num)
	{
		int hacked_computers_num = 0;
		Dfs(computer_num, &hacked_computers_num);
		coms[computer_num]->_hack = hacked_computers_num;
		memset(visited, 0, sizeof(visited));
	}
}

void SetComs(int N)
{
	for (int com_num = 1; com_num <= N; ++com_num)
	{
		Com* newCom = (Com*)malloc(sizeof(Com));
		newCom->_num = com_num;
		newCom->_hack = 0;
		newCom->_parentnum = 0;
		newCom->_parent = NULL;
		coms[com_num] = newCom;
	}
}

void SetComParent(int M)
{
	for (int t = 0; t < M; ++t)
	{
		int y, x;
		scanf("%d%d", &y, &x);
		Com* newCom = (Com*)malloc(sizeof(Com));
		newCom->_num = y;
		newCom->_hack = 0;
		newCom->_parent = NULL;
		
		int p_index = 0;
		Com* currentCom = coms[x];
		int parent_num = currentCom->_parentnum;
		while (p_index != parent_num)
		{
			currentCom = currentCom->_parent;
			++p_index;
		}
		currentCom->_parent = newCom;
		coms[x]->_parentnum++;
	}
}


int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	SetComs(N);
	SetComParent(M);
	DfsAll(N);
	MergeSort(1, N);
	
	int maxHack = coms[1]->_hack;
	for (int i = 1; i <= N && coms[i]->_hack == maxHack; ++i)
	{
		printf("%d ", coms[i]->_num);
	}

	for (int i = 1; i <= N; ++i)
	{
		Com* parentCom = coms[i]->_parent;
		Com* removeCom = parentCom;
		
		while (parentCom != NULL)
		{
			parentCom = parentCom->_parent;
			free(removeCom);
			removeCom = parentCom;
		}
		free(coms[i]);
	}
	return 0;
}