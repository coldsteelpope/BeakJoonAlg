#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	//cin >> str;
	getline(cin, str);

	long long str_ptr = 0;

	string candidate;
	//cin >> candidate;
	getline(cin, candidate);
	
	long long answer = 0;
	long long limit_str_ptr = (long long)str.size() - (long long)candidate.size();
	while (str_ptr <= limit_str_ptr)
	{
		bool result = true;
		for (long long candidate_ptr = 0; candidate_ptr < candidate.size(); ++candidate_ptr)
		{
			if (candidate[candidate_ptr] != str[str_ptr + candidate_ptr])
			{
				result = false;
				break;
			}
		}

		if (result == true)
		{
			++answer;
			str_ptr += candidate.length();
		}
		else
		{
			++str_ptr;
		}
	}

	cout << answer << endl;
}