#include <iostream>
#include <stack>

using namespace std;

class Queue
{
public:
	void Enqueue(int n)
	{
		stack_one.push(n);
	}

	int Dequeue()
	{
		if (stack_two.size() == 0)
		{
			int stack_one_size = stack_one.size();
			for (int i = 0; i < stack_one_size; ++i)
			{
				stack_two.push(stack_one.top());
				stack_one.pop();
			}
		}
		int data = stack_two.top();
		stack_two.pop();
		return data;
	}

private:
	stack<int> stack_one;
	stack<int> stack_two;
};

int main(void)
{
	Queue q;
	
	for (int i = 1; i <= 5; ++i)
	{
		q.Enqueue(i);
		cout << i << " 데이터가 Enqueue" << endl;
	}

	cout << endl;

	for (int i = 1; i <= 5; ++i)
		cout << q.Dequeue() << " 데이터가 Dequeue" << endl;
	
	return 0;
}