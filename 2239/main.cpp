#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> zeros;

int sudoku[10][10] = { 0, };

bool CanSet(int i, int j, int value)
{
	for (int x = 1; x <= 9; ++x)
	{
		if (sudoku[i][x] == value)
			return false;
	}

	for (int y = 1; y <= 9; ++y)
	{
		if (sudoku[y][j] == value)
			return false;
	}

	int r_start = ((i - 1) / 3) + 1;
	int c_start = ((j - 1) / 3) + 1;

	if (i == 1 && j == 5)
	{
		int a = 3;
	}

	for (int y = (3 * r_start - 2); y <= (3 * r_start); ++y)
	{
		for (int x = (3 * c_start - 2); x <= (3 * c_start); ++x)
		{
			if (sudoku[y][x] == value)
				return false;
		}
	}

	return true;
}

void SetSudoku()
{
	for (int i = 1; i <= 9; ++i)
	{
		string oneline;
		cin >> oneline;
		for (int j = 1; j <= 9; ++j)
		{
			sudoku[i][j] = oneline[j - 1] - '0';
			if (sudoku[i][j] == 0)
			{
				zeros.push_back({ i, j });
			}
		}
	}
}


void PrintSudoku()
{
	for (int y = 1; y <= 9; ++y)
	{
		for (int x = 1; x <= 9; ++x)
		{
			cout << sudoku[y][x];
		}
		cout << endl;
	}
}

void DFS(int count)
{
	if (count == zeros.size())
	{
		PrintSudoku();
		exit(0);
	}
	
	for (int num = 1; num <= 9; ++num)
	{
		pair<int, int> current_zero_pos = zeros[count];
		if (CanSet(current_zero_pos.first, current_zero_pos.second, num))
		{
			sudoku[current_zero_pos.first][current_zero_pos.second] = num;
			DFS(count + 1);
			sudoku[current_zero_pos.first][current_zero_pos.second] = 0;
		}
	}
}

int main(void)
{
	SetSudoku();
	DFS(0);
	return 0;
}