#include <iostream>
#include <queue>

using namespace std;

void SwapQueue(queue<int>& q1, queue<int>& q2)
{
	queue<int> temp = q1;
	q1 = q2;
	q2 = temp;
}
class Stack
{

public:
	void Push(int n)
	{
		q1.push(n);
	}

	int Pop()
	{
		int q1Size = q1.size();
		for (int i = 0; i < q1Size - 1; ++i)
		{
			q2.push(q1.front());
			q1.pop();
		}
	
		int result = q1.front();
		q1.pop();
		SwapQueue(q1, q2);
		return result;
	}
private:
	queue<int> q1;
	queue<int> q2;
};

int main(void)
{
	Stack stack;
	
	for (int i = 1; i <= 5; ++i)
	{
		stack.Push(i);
		cout << i << " 데이터 Push" << endl;
	}

	cout << endl;

	for (int i = 1; i <= 5; ++i)
	{
		cout << stack.Pop() << " 데이터 Pop" << endl;
	}

	return 0;
}