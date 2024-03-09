#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	int answer = 0;
	int S;
	int P;
	string str;
	map<char, int> dnaLimits;
	map<char, int> dna;
	
	cin >> S >> P;
	cin >> str;
	cin >> dnaLimits['A'] >> dnaLimits['C'] >> dnaLimits['G'] >> dnaLimits['T'];

	dna['A'] = 0;
	dna['C'] = 0;
	dna['G'] = 0;
	dna['T'] = 0;
	
	int leftPointer = 0;
	int rightPointer = leftPointer + P - 1;
	for (int index = leftPointer; index <= rightPointer; ++index)
	{
		++dna[str[index]];
	}
	
	if (dna['A'] >= dnaLimits['A'] && dna['C'] >= dnaLimits['C'] && dna['G'] >= dnaLimits['G'] && dna['T'] >= dnaLimits['T'])
	{
		++answer;
	}

	for (int index = 0; index < str.size() - P; ++index)
	{
		dna[str[leftPointer + index]] -= 1;
		dna[str[rightPointer + index + 1]] += 1;
		if (dna['A'] >= dnaLimits['A'] && dna['C'] >= dnaLimits['C'] && dna['G'] >= dnaLimits['G'] && dna['T'] >= dnaLimits['T'])
		{
			++answer;
		}
	}

	cout << answer << "\n";
	return 0;
}