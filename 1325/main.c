#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

int computer_network[10000][10000] = { 0, };
bool visited[10000] = { 0, };

typedef struct _COM
{
	int _num;
	int _hack;
} Com;

Com* coms[10000];
int coms_len = 0;
Com* temp[10000] = { 0, };


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
		else if(coms[leftIdx]->_hack < coms[rightIdx]->_hack)
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

void Dfs(int computer_num, int N, int* hacked_computers_num)
{
	visited[computer_num] = true;
	for (int other_computer_num = 0; other_computer_num < N; ++other_computer_num)
	{
		if (computer_network[computer_num][other_computer_num] == 0)
			continue;
		if (visited[other_computer_num] == true)
			continue;
		++(*hacked_computers_num);
		Dfs(other_computer_num, N, hacked_computers_num);
	}
}

void DfsAll(int N)
{
	for (int computer_num = 0; computer_num < N; ++computer_num)
	{
		int hacked_computers_num = 0;
		Dfs(computer_num, N, &hacked_computers_num);
		coms[computer_num]->_hack = hacked_computers_num;
		memset(visited, 0, sizeof(visited));
	}
}

void SetComs(int N)
{
	int num = 1;
	for (int i = 0; i < N; ++i)
	{
		Com* newCom = (Com*)malloc(sizeof(Com));
		newCom->_num = num++;
		newCom->_hack = 0;
		coms[coms_len++] = newCom;
	}
}

int SetComputerNetwork(int M)
{
	for (int t = 0; t < M; ++t)
	{
		int y, x;
		scanf("%d%d", &y, &x);
		computer_network[x - 1][y - 1] = 1;
	}
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	SetComs(N);
	SetComputerNetwork(M);
	DfsAll(N);
	MergeSort(0, N - 1);

	int maxHack = coms[0]->_hack;
	for (int i = 0; i < N && coms[i]->_hack == maxHack; ++i)
		printf("%d ", coms[i]->_num);

	for (int i = 0; i < N; ++i)
		free(coms[i]);

	int a = 3;
}