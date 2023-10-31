#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int Table[1001][1001] = { 0, };

int LCS(char* X, char* Y, int i, int j)
{
	int m = 0;
	int n = 0;

	for (m = 0; m <= i; ++m)
		Table[m][0] = 0;
	for (n = 0; n <= j; ++n)
		Table[0][n] = 0;

	for (m = 1; m <= i; ++m)
	{
		for (n = 1; n <= j; ++n)
		{
			if (X[m - 1] == Y[n - 1])
			{
				Table[m][n] = Table[m - 1][n - 1] + 1;
			}
			else
			{
				if (Table[m][n - 1] >= Table[m - 1][n])
					Table[m][n] = Table[m][n - 1];
				else
					Table[m][n] = Table[m - 1][n];
			}
		}
	}
	return Table[i][j];
}

void LCS_TraceBack(char* X, char* Y, int m, int n, char* LCS)
{
	if (m == 0 || n == 0)
		return;
	
	if 
	(
		Table[m][n] > Table[m][n - 1] &&
		Table[m][n] > Table[m - 1][n] &&
		Table[m][n] > Table[m - 1][n - 1]
	)
	{
		char TempLCS[1001];
		strcpy(TempLCS, LCS);
		sprintf(LCS, "%c%s", X[m - 1], TempLCS);
		
		LCS_TraceBack(X, Y, m - 1, n - 1, LCS);
	}
	else if 
	(
		Table[m][n] > Table[m - 1][n] &&
		Table[m][n] == Table[m][n - 1]
	)
	{
		LCS_TraceBack(X, Y, m, n - 1, LCS);
	}
	else
	{
		LCS_TraceBack(X, Y, m - 1, n, LCS);
	}
}

void LCS_PrintTable(char* X, char* Y, int LEN_X, int LEN_Y)
{
	int i = 0;
	int j = 0;

	printf("%4s", "");
	for (i = 0; i < LEN_Y + 1; ++i)
		printf("%c ", Y[i]);
	printf("\n");

	for (int i = 0; i < LEN_X + 1; ++i)
	{
		if (i == 0)
			printf("%2s", "");
		else
			printf("%-2c", X[i - 1]);
		for (int j = 0; j < LEN_Y + 1; ++j)
		{
			printf("%d ", Table[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	//char* X = "ACAYKP";
	//char* Y = "CAPCAK";
	char X[1001] = { 0, };
	char Y[1001] = { 0, };
	scanf("%s", X);
	scanf("%s", Y);

	int LEN_X = strlen(X);
	int LEN_Y = strlen(Y);

	int i = 0;
	int Length = 0;

	Length = LCS(X, Y, LEN_X, LEN_Y);
	
	//LCS_PrintTable(&Table, X, Y, LEN_X, LEN_Y);
	
	char Result[1001] = { 0, };

	LCS_TraceBack(X, Y, LEN_X, LEN_Y, Result);
	printf("%d\n", Length);
	printf("%s\n", Result);

	return 0;
}