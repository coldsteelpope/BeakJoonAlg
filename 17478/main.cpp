#include <iostream>

using namespace std;

void PrintBars(int depth)
{
	for (int index = 0; index < 4 * depth; ++index)
	{
		cout << "_";
	}
}

void ChatBot(int depth, int target)
{
	PrintBars(depth);
	cout << "\"����Լ��� ������?\"" << "\n";

	if (depth == target)
	{
		PrintBars(depth);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
	}
	else
	{
		PrintBars(depth);
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
		PrintBars(depth);
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
		PrintBars(depth);
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";
		ChatBot(depth + 1, target);
	}
	PrintBars(depth);
	cout << "��� �亯�Ͽ���." << "\n";
	return;
}

int main(void)
{
	int N;
	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";
	ChatBot(0, N);
	return 0;
}