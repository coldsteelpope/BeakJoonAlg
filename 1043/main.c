#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _DISJOINTSET
{
	struct _DISJOINTSET*	_parent;
} DisjointSet;

DisjointSet* CreateDisjointSet(int data)
{
	DisjointSet* set = (DisjointSet*)malloc(sizeof(DisjointSet));
	set->_parent = NULL;
	return set;
}

DisjointSet* Find(DisjointSet* set)
{
	while (set->_parent != NULL)
		set = set->_parent;
	return set;
}

void Union(DisjointSet* set1, DisjointSet* set2)
{
	set2 = Find(set2);
	set2->_parent = set1;
}

DisjointSet* members[51] = { 0, };
int party_list[51][51] = { 0, };

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; ++i)
		members[i] = CreateDisjointSet(i);

	DisjointSet* trust_set = NULL;
	
	int trust_members_num = 0;
	scanf("%d", &trust_members_num);

	for (int i = 0; i < trust_members_num; ++i)
	{
		int trust_member = 0;
		scanf("%d", &trust_member);
		
		if (trust_set == NULL)
		{
			members[trust_member]->_parent = NULL;
			trust_set = members[trust_member];
		}
		else
		{
			Union(trust_set, members[trust_member]);
		}
	}

	for (int p_index = 0; p_index < M; ++p_index)
	{
		int party_members_num = 0;
		scanf("%d", &party_members_num);
		
		DisjointSet* exSet = NULL;


		for (int p_m_index = 0; p_m_index < party_members_num; ++p_m_index)
		{
			int party_member = 0;
			scanf("%d", &party_member);
			party_list[p_index][p_m_index] = party_member;

			if (exSet != NULL)
			{
				if (Find(members[party_member]) != Find(exSet))
				{
					if (trust_set == Find(members[party_member]))
					{
						Union(members[party_member], exSet);
					}
					else
					{
						Union(exSet, members[party_member]);
					}
				}
				/*if (trust_set == Find(members[party_member]))
				{
					Union(members[party_member], exSet);
				}
				else if(Find(members[party_member]) != Find(exSet))
				{
					Union(exSet, members[party_member]);
				}*/
			}
			
			exSet = members[party_member];
		}
	}

	int answer = 0;
	for (int p_index = 0; p_index < M; ++p_index)
	{
		bool is_there_trust = false;
		for (int p_m_index = 0; p_m_index < N && party_list[p_index][p_m_index] != 0; ++p_m_index)
		{
			int current_member = party_list[p_index][p_m_index];
			if (trust_set == members[current_member])
			{
				is_there_trust = true;
				break;
			}
			else if (trust_set == Find(members[current_member]))
			{
				is_there_trust = true;
				break;
			}
		}
		if (is_there_trust == false)
			++answer;
	}

	printf("%d\n", answer);
	for (int i = 0; i < 51; ++i)
		free(members[i]);
	return 0;
}