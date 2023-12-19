#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> board;

inline int GetAbs(int num)
{
	return num > 0 ? num : -num;
}

class Shark
{
public:
	Shark(int y, int x) : _y(y), _x(x), _level(2), _eat(0), _seconds(0) {}
	
	void Scan()
	{
		_candidates.clear();

		queue<pair<int, pair<int, int>>> q;
		vector<vector<bool>> discovered;
		discovered.resize(N, vector<bool>(N, false));

		q.push(make_pair(0, make_pair(this->_y, this->_x)));
		discovered[this->_y][this->_x] = true;
		
		while (q.empty() == false)
		{
			pair<int, pair<int, int>> here = q.front();
			q.pop();
			
			if (board[here.second.first][here.second.second] != 9 && board[here.second.first][here.second.second] > 0 && board[here.second.first][here.second.second] < this->_level)
			{
				this->_candidates.push_back(make_pair(here.first, make_pair(here.second.first, here.second.second)));
			}

			for (int dirIdx = 0; dirIdx < 4; ++dirIdx)
			{
				int nextY = here.second.first + _dirs[dirIdx][0];
				int nextX = here.second.second + _dirs[dirIdx][1];

				if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
				{
					continue;
				}

				if (board[nextY][nextX] > this->_level)
				{
					continue;
				}

				if (discovered[nextY][nextX] == true)
				{
					continue;
				}

				discovered[nextY][nextX] = true;
				q.push(make_pair(here.first + 1, make_pair(nextY, nextX)));
			}
		}
	}

	bool CallMom()
	{
		//int zero_num = 0;

		//for (int i = 0; i < N; ++i)
		//{
		//	for (int j = 0; j < N; ++j)
		//	{
		//		if (board[i][j] == 0 || board[i][j] == 9)
		//		{
		//			++zero_num;
		//		}
		//	}
		//}
		
		return (this->_candidates.size() == 0 /*|| zero_num == (N * N)*/) ? true : false;
	}

	void Eat()
	{

		if (this->_candidates.size() > 1)
		{
			std::sort(this->_candidates.begin(), this->_candidates.end(), [](pair<int, pair<int, int>> pos1, pair<int, pair<int, int>> pos2)->bool
			{
				if (pos1.first == pos2.first)
				{
					if (pos1.second.first == pos2.second.first)
					{
						return pos1.second.second < pos2.second.second;
					}
					else
					{
						return pos1.second.first < pos2.second.first;
					}
				}
				else
				{
					return pos1.first < pos2.first;
				}
			});
		}
		pair<int, pair<int, int>> fishPos = this->_candidates[0];
		
		this->_seconds += fishPos.first;

		board[this->_y][this->_x] = 0;
		this->_y = fishPos.second.first; this->_x = fishPos.second.second;

		this->_eat++;
		if (this->_eat == this->_level)
		{
			this->_level++;
			this->_eat = 0;
		}
		board[this->_y][this->_x] = 9;
	}

	int GetSeconds()
	{
		return this->_seconds;
	}

	void ShowInfo()
	{
		cout << "--sharkInfo--" << endl;
		cout << "y: " << this->_y << endl;
		cout << "x: " << this->_x << endl;
		cout << "level: " << this->_level << endl;
		cout << "eat: " << this->_eat << endl;
		cout << "seconds: " << this->_seconds << endl;
	}

private:
	int _y;
	int _x;
	int _level;
	int _eat;
	int _seconds;
	int _dirs[4][2] = {
		{ +0, +1 },
		{ +1, +0 },
		{ +0, -1 },
		{ -1, +0 }
	};
	vector<pair<int, pair<int, int>>> _candidates;
};

void PrintBoard(int N)
{
	cout << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

pair<int, int> SetBoard(int N)
{
	pair<int, int> sharkPos;
	board.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				sharkPos.first = i;
				sharkPos.second = j;
			}
		}
	}
	return sharkPos;
}

int main(void)
{
	cin >> N;
	pair<int, int> sharkPos = SetBoard(N);
	Shark babyShark = Shark(sharkPos.first, sharkPos.second);
	
	int answer = 0;
	while (true)
	{
		//PrintBoard(N);
		//babyShark.ShowInfo();

		babyShark.Scan();
		bool callMom = babyShark.CallMom();
		if (callMom == true)
		{
			answer = babyShark.GetSeconds();
			break;
		}
		babyShark.Eat();
		
	}
	cout << answer << endl;
}