#include <iostream>
#include <vector>

using namespace std;



typedef struct _HOUSE
{
	int _y;
	int _x;
	int _chicken_len;
} House;

typedef struct _CHICKEN_STORE
{
	int _y;
	int _x;
} ChickenStore;

vector<House> houses;
vector<ChickenStore> chickenStores;
ChickenStore selectedChickenStores[14] = { 0, };

int min_len = 2147483647;

int GetAbsolute(int num)
{
	return num > 0 ? num : -num;
}

void CombinationChickenStore(int N, int R, int max_R)
{
	if (R == 0)
	{
		for (int house_index = 0; house_index < houses.size(); ++house_index)
		{
			for (int i = max_R - 1; i >= 0; --i)
			{
				ChickenStore current_selected_chicken_store = selectedChickenStores[i];
				int current_chicken_len = GetAbsolute(houses[house_index]._y - current_selected_chicken_store._y) + GetAbsolute(houses[house_index]._x - current_selected_chicken_store._x);
				
				if (houses[house_index]._chicken_len > current_chicken_len)
					houses[house_index]._chicken_len = current_chicken_len;
			}
		}

		int sum = 0;
		for (int house_index = 0; house_index < houses.size(); ++house_index)
		{
			sum += houses[house_index]._chicken_len;
		}

		min_len = (min_len > sum) ? sum : min_len;

		for (int i = 0; i < houses.size(); ++i)
			houses[i]._chicken_len = 2147483647;
		return;
	}
	else if (N < R)
	{
		return;
	}
	else
	{
		selectedChickenStores[R - 1] = chickenStores[N - 1];
		CombinationChickenStore(N - 1, R - 1, max_R);
		CombinationChickenStore(N - 1, R, max_R);
	}
}


void SetHouses(int N)
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++ x)
		{
			int type;
			cin >> type;
			if (type == 1)
				houses.push_back({ y, x, 2147483647 });
			else if(type == 2)
				chickenStores.push_back({ y, x });
		}
	}
}

int main(void)
{
	// N: width & height
	// M: Chicken stores
	int N, M;
	cin >> N >> M;
	SetHouses(N);

	for (int r = 1; r <= M; ++r)
	{
		CombinationChickenStore(chickenStores.size(), r, r);
	}

	

	printf("%d", min_len);
	return 0;
}