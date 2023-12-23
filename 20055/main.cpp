#include <iostream>
#include <deque>

using namespace std;

deque<int> convey;
deque<bool> robots;

int zeroNum = 0;

void Rotate(int N)
{
	convey.push_front(convey.back());
	convey.pop_back();

	robots.push_front(robots.back());
	robots.pop_back();
	robots[N - 1] = false;
}

void Move(int N)
{
	for (int i = N - 2; i >= 0; --i)
	{
		if (robots[i + 1] == false && convey[i + 1] > 0 && robots[i] == true)
		{
			robots[i] = false;
			robots[i + 1] = true;
			--convey[i + 1];

			if (convey[i + 1] == 0)
			{
				++zeroNum;
			}

		}
	}
	robots[N - 1] = false;
}

void LiftUp()
{
	if (convey[0] > 0 && robots[0] == false)
	{
		robots[0] = true;
		--convey[0];
		
		if (convey[0] == 0)
		{
			++zeroNum;
		}
	}
}

int Count(int N)
{
	int result = 0;
	for (int i = 0; i < (2 * N); ++i)
	{
		if (convey[i] == 0)
		{
			++result;
		}
	}
	return result;
}

void PrintConvey(int N)
{
	cout << endl;
	for (int i = 0; i < 2 * N; ++i)
	{
		cout << convey[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	for (int n = 0; n < 2 * N; ++n)
	{
		int durability;
		cin >> durability;
		convey.emplace_back(durability);
		robots.emplace_back(false);
	}

	int count = 0;
	while (true)
	{
		Rotate(N);
		//PrintConvey(N);

		Move(N);
		//PrintConvey(N);

		LiftUp();
		//PrintConvey(N);

		//int zeroCount = Count(N);
		++count;
		if (zeroNum >= K)
		{
			break;
		}
	}

	cout << count << "\n";
	return 0;
}