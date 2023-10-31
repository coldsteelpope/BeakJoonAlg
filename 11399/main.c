#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _USER
{
	int _userNum;
	int _needTime;
} User;

User* users[1001];

void Swap(User** user1, User** user2)
{
	User* temp = (*user1);
	(*user1) = (*user2);
	(*user2) = temp;
}

int Partition(int left, int right)
{
	int pivot = users[left]->_needTime;
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		if (low <= right && users[low]->_needTime <= pivot)
		{
			++low;
		}

		if (high >= left + 1 && users[high]->_needTime >= pivot)
		{
			--high;
		}

		if (low < high)
		{
			Swap(&users[low], &users[high]);
		}
	}
	Swap(&users[left], &users[high]);
	return high;
}

int QuickSort(int left, int right)
{
	if (left > right)
		return;
	int pivot = Partition(left, right);
	QuickSort(left, pivot - 1);
	QuickSort(pivot + 1, right);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int userNum = 0; userNum < N; ++userNum)
	{
		User* user = (User*)malloc(sizeof(User));
		user->_userNum = userNum + 1;
		scanf("%d", &user->_needTime);
		users[userNum] = user;
	}

	QuickSort(0, N - 1);

	int answer = 0;
	int accumulatedTime = 0;
	for (int i = 0; i < N; ++i)
	{
		accumulatedTime += users[i]->_needTime;
		answer += accumulatedTime;
	}

	printf("%d", answer);

	int a = 3;
	for (int i = 0; i < N; ++i)
		free(users[i]);
	return 0;
}