#include <iostream>
#include <map>

using namespace std;

void PrintMap(map<string, int> characters)
{
	for (const auto& elem : characters)
	{
		cout << elem.first << " " << elem.second << endl;
	}
	cout << endl;
}

int main(void)
{
	map<string, int> characters;
	int N, M;
	cin >> N >> M;

	for (int t = 0; t < N; ++t)
	{
		string name;
		cin >> name;
		characters.insert({ name, 1 });
	}

	int answer_num = 0;
	for (int t = 0; t < M; ++t)
	{
		string name;
		cin >> name;
		
		map<string, int>::iterator it = characters.find(name);
		if (it != characters.end())
		{
			++characters[name];
			if (characters[name] == 2)
				answer_num++;
		}
	}

	cout << answer_num << endl;
	for (map<string, int>::iterator it = characters.begin(); it != characters.end(); ++it)
	{
		if (it->second == 2)
			cout << it->first << endl;
	}
	return 0;
}