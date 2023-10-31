#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> arr;
map<string, bool> users;

int main(void)
{
	int N;
	char C;
	cin >> N >> C;
	arr.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int players_num = 0;
	switch (C)
	{
	case 'Y':
		players_num = 2;
		break;
	case 'F':
		players_num = 3;
		break;
	case 'O':
		players_num = 4;
		break;
	default:
		break;
	}

	int answer = 0;
	vector<string> tmp;
	for (int t = 0; t < arr.size(); ++t)
	{
		string current_name = arr[t];
		if (users[current_name] == false)
		{
			tmp.push_back(current_name);
			users[current_name] = true;
			if (tmp.size() == players_num - 1)
			{
				++answer;
				tmp.clear();
			}
		}
	}

	cout << answer << endl;
	return 0;
}