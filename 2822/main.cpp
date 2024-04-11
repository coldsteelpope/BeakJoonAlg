#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> iScores;

int main(void)
{
	int iRank = 1;
	int iSum = 0;
	for (int i = 0; i < 8; ++i)
	{
		int iScore;
		cin >> iScore;
		iScores.push_back(make_pair(iScore, iRank++));

	}

	std::sort(iScores.begin(), iScores.end());

	vector<pair<int, int>> result;
	for (int i = 7; i >= 3; --i)
	{
		result.push_back(make_pair(iScores[i].second, iScores[i].first));
		iSum += iScores[i].first;
	}

	std::sort(result.begin(), result.end());
	
	cout << iSum << endl;
	for (pair<int, int> ele : result)
	{
		cout << ele.first << " ";
	}
	return 0;
}