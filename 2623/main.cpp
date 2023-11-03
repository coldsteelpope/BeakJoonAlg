#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int inDegrees[1001];
vector<int> adjacentList[1001];

void TopologySort(int N)
{
	vector<int> result;
	queue<int> q;

	for (int node = 1; node <= N; ++node)
	{
		if (inDegrees[node] == 0)
		{
			q.push(node);
		}
	}
	
	while (q.empty() == false)
	{
		int frontNode = q.front();
		q.pop();
		result.push_back(frontNode);
		for (int i = 0; i < adjacentList[frontNode].size(); ++i)
		{
			int there = adjacentList[frontNode][i];
			--inDegrees[there];
			if (inDegrees[there] == 0)
			{
				q.push(there);
			}
		}
	}

	if (result.size() == N)
	{
		for (int i = 0; i < result.size(); ++i)
		{
			printf("%d\n", result[i]);
		}
	}
	else
	{
		printf("0\n");
	}
}

void SetAdjacentList(int N, int M)
{
	for (int m = 0; m < M; ++m)
	{
		vector<int> seqMemo;
		int singersNum = 0;
		scanf("%d", &singersNum);

		for (int singerSeq = 0; singerSeq < singersNum; ++singerSeq)
		{
			int singer = 0;
			scanf("%d", &singer);
			seqMemo.push_back(singer);
		}

		for (int i = 0; i < seqMemo.size() - 1; ++i)
		{
			inDegrees[seqMemo[i + 1]] += 1;
			adjacentList[seqMemo[i]].push_back(seqMemo[i + 1]);
		}
	}
}

// �޸� �ʰ� ����
// input�κ��� �ٲ� => �޸� �ʰ� �߻�
// topology �κ��� �ٲ� => ����
int main()
{
	// N: ������ �� & M: ���� PD�� ��
	int N, M;
	scanf("%d%d", &N, &M);
	SetAdjacentList(N, M);
	TopologySort(N);

	return 0;
}