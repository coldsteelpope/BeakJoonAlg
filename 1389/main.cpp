#include <iostream>
#include <numeric>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct _USER
{
	int _usernum;
	int _network;
} User;

vector<User> users;
vector<vector<int>> adjacent;
vector<bool> discovered;

bool cmp(const User& a, const User& b)
{
	if (a._network < b._network)
	{
		return true;
	}
	else if (a._network > b._network)
	{
		return false;
	}
	else
	{
		if (a._usernum < b._usernum)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void CreateGraph(int N, int M)
{
	adjacent = vector<vector<int>>(N + 1);
	for (int t = 0; t < M; ++t)
	{
		int here, there;
		cin >> here >> there;
		adjacent[here].push_back(there);
		adjacent[there].push_back(here);
	}
}

vector<int> GetDistance(int here ,int N)
{
	vector<int> distance(N + 1, 0);
	discovered = vector<bool>(N + 1, false);
	queue<int> q;
	
	q.push(here);
	discovered[here] = true;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();
		for (int there : adjacent[here])
		{
			if (discovered[there] == true)
				continue;
			q.push(there);
			discovered[there] = true;
			distance[there] = distance[here] + 1;
		}
	}
	return distance;
}



int main(void)
{
	int N, M;
	// N: 유저의 수
	// M: 친구 관계의 수
	cin >> N >> M;
	CreateGraph(N, M);
	
	for (int usernum = 1; usernum <= N; ++usernum)
	{
		vector<int> distance = GetDistance(usernum, N);
		User newUser = { usernum, accumulate(distance.begin(), distance.end(), 0) };
		users.push_back(newUser);
	}

	sort(users.begin(), users.end(), cmp);
	cout << users[0]._usernum;

	return 0;
}