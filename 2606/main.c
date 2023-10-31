#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int network[101][101] = { 0, };

void Dfs(int com, bool* visited[], int computer_num, int* infected_computer)
{
	(*visited)[com - 1] = true;
	for (int other_com = 1; other_com <= computer_num; ++other_com)
	{
		if (network[com][other_com] == 0)
			continue;
		if ((*visited)[other_com - 1] == true)
			continue;
		++(*infected_computer);
		Dfs(other_com, visited, computer_num, infected_computer);
	}
}

void SetNetwork(int com1, int com2)
{
	network[com1][com2] = 1;
	network[com2][com1] = 1;
}

int main(void)
{
	int computer_num = 0;
	int network_num = 0;
	
	int infected_computer = 0;

	scanf("%d", &computer_num);
	scanf("%d", &network_num);

	for (int i = 0; i < network_num; ++i)
	{
		int com1, com2;
		scanf("%d%d", &com1, &com2);
		SetNetwork(com1, com2);
	}

	bool* visited = (bool*)calloc(computer_num, sizeof(bool));
	Dfs(1, &visited, computer_num, &infected_computer);

	printf("%d\n", infected_computer);
	return 0;
}