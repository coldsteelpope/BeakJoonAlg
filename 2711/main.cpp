#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		int pos;
		string mis_spell;
		cin >> pos >> mis_spell;

		string answer = "";
		int mis_spell_len = mis_spell.size();
		
		for (int i = 0; i < mis_spell_len; ++i)
		{
			if (pos == i + 1)
				continue;
			answer += mis_spell[i];
		}
		cout << answer << endl;
	}
	return 0;
}