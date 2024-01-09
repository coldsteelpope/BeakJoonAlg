#include <iostream>

using namespace std;

inline long long GetMax(long long num1, long long num2)
{
	return num1 > num2 ? num1 : num2;
}

inline long long GetMin(long long num1, long long num2)
{
	return num1 > num2 ? num2 : num1;
}

int main(void)
{
	long long X, Y, W, S;
	cin >> X >> Y >> W >> S;
	
	long long costOne = (X + Y) * W;
	
	long long maxValue = GetMax(X, Y);
	long long minValue = GetMin(X, Y);

	long long costTwo = ((X + Y) % 2 == 0) ? ((maxValue)*S) : (((maxValue - 1) * S) + W);
	long long costThree = (minValue * S) + ((maxValue - minValue) * W);
	
	long long result = GetMin(costOne, GetMin(costTwo, costThree));
	cout << result << "\n";

	return 0;
}