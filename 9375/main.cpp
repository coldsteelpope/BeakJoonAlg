#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	int testcase_num;
	cin >> testcase_num;

	map<string, int> closet;

	for (int t = 0; t < testcase_num; ++t)
	{
		int t_num = 0;
		cin >> t_num;
		for (int i = 0; i < t_num; ++i)
		{
			string clothes_detail_name;
			string clothes_name;

			cin >> clothes_detail_name >> clothes_name;
			if (closet.find(clothes_name) != closet.end())
				++closet[clothes_name];
			else
				closet.insert({ clothes_name, 1 });
		}

		int answer = 1;
		map<string, int>::iterator iter;
		for (iter = closet.begin(); iter != closet.end(); ++iter)
		{
			answer *= (iter->second + 1);
		}
		cout << answer - 1 << endl;
		closet.clear();
	}

	return 0;
}