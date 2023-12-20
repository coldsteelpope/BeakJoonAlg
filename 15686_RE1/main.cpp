#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int minValue = (~0U >> 2);

vector<pair<int, int>> houses;
int housesLen = 0;

vector<pair<int, int>> chickenHouses;
int chickenHousesLen = 0;

vector<pair<int, int>> selectedChickenHouses;

inline int GetAbs(int num)
{
	return num > 0 ? num : -num;
}

inline int GetMin(int num1, int num2)
{
	return num1 > num2 ? num2 : num1;
}


void SelectChickenHouse(int r, int depth, int nextIdx)
{
	if (depth == r)
	{
		int sum = 0;
		for (int houseIdx = 0; houseIdx < housesLen; ++houseIdx)
		{
			pair<int, int> currentHouse = houses[houseIdx];

			int minLen = (~0U >> 2);
			for (int selIdx = 0; selIdx < r; ++selIdx)
			{
				pair<int, int> currentSelectedChickenHouse = selectedChickenHouses[selIdx];
				int chickenLen = GetAbs(currentHouse.first - currentSelectedChickenHouse.first) + GetAbs(currentHouse.second - currentSelectedChickenHouse.second);
				minLen = (minLen > chickenLen) ? chickenLen : minLen;
			}
			sum += minLen;
		}
		minValue = GetMin(minValue, sum);
	}
	else
	{
		for (int i = nextIdx; i < chickenHousesLen; ++i)
		{
			selectedChickenHouses[depth] = chickenHouses[i];
			SelectChickenHouse(r, depth + 1, i + 1);
		}
	}
}

void SetHouses(int N)
{
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			int num;
			cin >> num;
			if (num == 1)
			{
				houses.emplace_back(make_pair(y, x));
			}
			else if (num == 2)
			{
				chickenHouses.emplace_back(make_pair(y, x));
			}
		}
	}
	housesLen = houses.size();
	chickenHousesLen = chickenHouses.size();
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	selectedChickenHouses.resize(M);
	SetHouses(N);
	for (int r = 1; r <= M; ++r)
	{
		SelectChickenHouse(r, 0, 0);
	}
	cout << minValue << endl;
	return 0;
}