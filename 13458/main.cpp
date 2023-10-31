#include <iostream>
#include <vector>

using namespace std;

vector<long long> students;

int main(void)
{
	long long N, B, C;
	cin >> N;
	for (long long i = 0; i < N; ++i)
	{
		long long students_num = 0;
		cin >> students_num;
		students.push_back(students_num);
	}
	cin >> B >> C;

	long long answer = 0;
	for (int i = 0; i < N; ++i)
	{
		if (students[i] >= 0)
		{
			students[i] -= B;
			++answer;
		}
	}
	
	for (long long i = 0; i < N; ++i)
	{
		if (students[i] > 0)
		{
			if (students[i] % C == 0)
			{
				answer += (students[i] / C);
			}
			else
			{
				answer += ((students[i] / C) + 1);
			}
		}

		//while (students[i] > 0)
		//{
		//	students[i] -= C;
		//	++answer;
		//}
	}

	cout << answer << endl;
	return 0;
}