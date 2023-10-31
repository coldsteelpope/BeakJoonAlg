#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> alps;

bool compare(char a, char b)
{
	return a < b;
}

char answer[51] = { 0, };

int main(void)
{
	string str;
	cin >> str;

	sort(str.begin(), str.end(), compare);
	
	for (int str_idx = 0; str_idx < str.size(); ++str_idx)
	{
		++alps[str[str_idx]];
	}
		
	bool is_even = (str.size() % 2 == 0);
	int odd_num = 0;
	
	for (int alp = 'A'; alp <= 'Z'; ++alp)
	{
		if (alps[alp] % 2 != 0)
			++odd_num;
	}

	if ((is_even == true && odd_num > 0) || (is_even == false && odd_num != 1))
	{
		cout << "I'm Sorry Hansoo" << endl;
	}
	else
	{
		int front_idx = 0;
		bool front_back_toggle = true;

		for (int alp = 'A'; alp <= 'Z'; ++alp)
		{
			if (alps[alp] == 0)
				continue;
			
			if (alps[alp] == 1)
			{
				answer[str.size() / 2] = alp;
			}
			else
			{
				if (alps[alp] % 2 == 0)
				{
					while (alps[alp] != 0)
					{
						if (front_back_toggle == true)
						{
							answer[front_idx] = alp;
							front_back_toggle = false;
							--alps[alp];
						}
						else
						{
							answer[str.size() - 1 - front_idx] = alp;
							front_idx++;
							--alps[alp];
							front_back_toggle = true;
						}
					}
				}
				else
				{
					while (alps[alp] != 1)
					{
						if (front_back_toggle == true)
						{
							answer[front_idx] = alp;
							front_back_toggle = false;
							--alps[alp];
						}
						else
						{
							answer[str.size() - 1 - front_idx] = alp;
							front_idx++;
							--alps[alp];
							front_back_toggle = true;
						}
					}
					answer[str.size() / 2] = alp;
				}
			}
		}
	}

	cout << answer << endl;
	return 0;
}