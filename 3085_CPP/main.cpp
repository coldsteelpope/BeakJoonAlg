#include <iostream>
#include <vector>

using namespace std;

vector<string> map;

inline int GetMax(int a, int b)
{
	return a > b ? a : b;
}

void Swap(int y, int x, int n_y, int n_x)
{
	char temp = map[y][x];
	map[y][x] = map[n_y][n_x];
	map[n_y][n_x] = temp;
}

int GetMaxEle(vector<int> candies)
{
	int max_value = 0;
	for (int i = 0; i < candies.size(); ++i)
	{
		max_value = (max_value > candies[i]) ? max_value : candies[i];
	}
	return max_value;
}

int GetResult(int N)
{
	
	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		vector<int> candies(4, 0);
		bool is_c_con = false;
		bool is_p_con = false;
		bool is_z_con = false;
		bool is_y_con = false;

		for (int j = 0; j < N; ++j)
		{
			switch (map[i][j])
			{
			case 'C':
				if (is_c_con)
					++candies[0];
				else
				{
					is_c_con = true;
					is_p_con = false;
					is_z_con = false;
					is_y_con = false;
					candies[0] = 1;
				}
				break;
			case 'P':
				if (is_p_con)
					++candies[1];
				else
				{
					is_c_con = false;
					is_p_con = true;
					is_z_con = false;
					is_y_con = false;
					candies[1] = 1;
				}

				break;
			case 'Z':
				if (is_z_con)
					++candies[2];
				else
				{
					is_c_con = false;
					is_p_con = false;
					is_z_con = true;
					is_y_con = false;
					candies[2] = 1;
				}

				break;
			case 'Y':
				if (is_y_con)
					++candies[3];
				else
				{
					is_c_con = false;
					is_p_con = false;
					is_z_con = false;
					is_y_con = true;
					candies[3] = 1;
				}
				break;

			default:
				break;
			}
		}
		
		int m = GetMaxEle(candies);
		result = (result > m) ? result : m;
		candies.clear();
	}

	for (int j = 0; j < N; ++j)
	{
		vector<int> candies(4, 0);
		bool is_c_con = false;
		bool is_p_con = false;
		bool is_z_con = false;
		bool is_y_con = false;

		for (int i = 0; i < N; ++i)
		{
			switch (map[i][j])
			{
			case 'C':
				if (is_c_con)
					++candies[0];
				else
				{
					is_c_con = true;
					is_p_con = false;
					is_z_con = false;
					is_y_con = false;
					candies[0] = 1;
				}
				break;
			case 'P':
				if (is_p_con)
					++candies[1];
				else
				{
					is_c_con = false;
					is_p_con = true;
					is_z_con = false;
					is_y_con = false;
					candies[1] = 1;
				}

				break;
			case 'Z':
				if (is_z_con)
					++candies[2];
				else
				{
					is_c_con = false;
					is_p_con = false;
					is_z_con = true;
					is_y_con = false;
					candies[2] = 1;
				}

				break;
			case 'Y':
				if (is_y_con)
					++candies[3];
				else
				{
					is_c_con = false;
					is_p_con = false;
					is_z_con = false;
					is_y_con = true;
					candies[3] = 1;
				}
				break;

			default:
				break;
			}
		}
		int m = GetMaxEle(candies);
		result = (result > m) ? result : m;
		candies.clear();
	}

	return result;
}

void PrintMap(int N)
{
	cout << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(void)
{
	int N;
	cin >> N;

	map.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> map[i];

	int dirs[4][2] = {
		{ +0, +1 },
		{ +1, +0 },
		{ +0, -1 },
		{ -1, +0 }
	};

	int answer = 0;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			for (int dir_i = 0; dir_i < 4; ++dir_i)
			{
				int next_y = y + dirs[dir_i][0];
				int next_x = x + dirs[dir_i][1];

				if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N)
					continue;

				Swap(y, x, next_y, next_x);

				//PrintMap(N);
				
				int result = GetResult(N);
				answer = (answer > result) ? answer : result;
				Swap(y, x, next_y, next_x);
			}
		}
	}

	cout << answer << endl;
	return 0;
}