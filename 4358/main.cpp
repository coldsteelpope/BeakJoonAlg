#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> trees;
vector<pair<string, double>> ratios;

int main(void)
{
	int totalNum = 0;
	string tree;
	while (getline(cin, tree))
	{
		++trees[tree];
		++totalNum;
	}

	for (auto it = trees.begin(); it != trees.end(); ++it)
	{
		double ratio = (it->second / (double)totalNum) * 100;
		ratios.push_back(make_pair(it->first, ratio));
	}
	
	std::sort(ratios.begin(), ratios.end());

	for (int i = 0; i < ratios.size(); ++i)
	{
		cout << fixed;
		cout.precision(4);
		cout << ratios[i].first << " " << ratios[i].second << "\n";
	}

	return 0;
}