#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _NODE
{
	int _data;
	struct _NODE* _next;
	struct _NODE* _prev;
} Node;

typedef struct _DECK
{
	int _count;
	bool _reverse;
	Node* _head;
	Node* _rear;
} Deck;

void CreateDeck(Deck** deck)
{
	(*deck) = (Deck*)malloc(sizeof(Deck));

	(*deck)->_head = (Node*)malloc(sizeof(Node));
	(*deck)->_rear = (Node*)malloc(sizeof(Node));

	(*deck)->_count = 0;
	(*deck)->_reverse = false;

	(*deck)->_head->_data = 0; (*deck)->_head->_next = (*deck)->_rear; (*deck)->_head->_prev = NULL;
	(*deck)->_rear->_data = 0; (*deck)->_rear->_prev = (*deck)->_head; (*deck)->_rear->_next = NULL;
}

void Push(Deck** deck, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_data = data;
	(*deck)->_count++;

	if ((*deck)->_reverse == false)
	{
		(*deck)->_rear->_prev->_next = newNode;
		newNode->_prev = (*deck)->_rear->_prev;

		newNode->_next = (*deck)->_rear;
		(*deck)->_rear->_prev = newNode;
	}
	else
	{
		(*deck)->_head->_next->_prev = newNode;
		newNode->_next = (*deck)->_head->_next;

		newNode->_prev = (*deck)->_head;
		(*deck)->_head->_next = newNode;
	}
}

Node* Front(Deck** deck)
{
	if ((*deck)->_reverse == false)
		return (*deck)->_head->_next;
	else
		return (*deck)->_rear->_prev;
}

void Pop(Deck** deck)
{
	(*deck)->_count--;
	Node* poppedNode = Front(deck);

	if ((*deck)->_reverse == false)
	{
		(*deck)->_head->_next = poppedNode->_next;
		poppedNode->_next->_prev = (*deck)->_head;
	}
	else
	{
		(*deck)->_rear->_prev = poppedNode->_prev;
		poppedNode->_prev->_next = (*deck)->_rear;
	}
	free(poppedNode);
}

bool Empty(Deck** deck)
{
	return (*deck)->_count == 0;
}

void DestroyDeck(Deck** deck)
{
	while (Empty(deck) == false)
		Pop(deck);
	free((*deck)->_head);
	free((*deck)->_rear);
	free((*deck));
}

void Reverse(Deck** deck)
{
	if ((*deck)->_reverse == false)
		(*deck)->_reverse = true;
	else
		(*deck)->_reverse = false;
}

char cmd[100001] = { 0, };
char nums[400001] = { 0, };

int main(void)
{
	int testcaseNum = 0;
	scanf("%d", &testcaseNum);

	for (int t = 0; t < testcaseNum; ++t)
	{
		Deck* deck;
		CreateDeck(&deck);

		scanf("%s", cmd);
		int nums_num = 0;
		scanf("%d", &nums_num);

		scanf("%s", nums);

		int n = 0;
		int numsLen = strlen(nums);
		for (int i = 1; i < numsLen; ++i)
		{
			if (nums[i] == ']' || nums[i] == ',')
			{
				if (n != 0)
					Push(&deck, n);
				n = 0;
			}
			else
			{
				n = n * 10 + (nums[i] - '0');
			}
		}

		bool error = false;
		for (int cmd_pointer = 0; cmd[cmd_pointer] != '\0'; ++cmd_pointer)
		{
			if (cmd[cmd_pointer] == 'R')
			{
				Reverse(&deck);
			}
			else if (cmd[cmd_pointer] == 'D')
			{
				if (deck->_count == 0)
				{
					error = true;
					break;
				}
				else
				{
					Pop(&deck);
				}
			}
		}

		if (error)
		{
			printf("error\n");
		}
		else
		{
			if (deck->_count == 0)
			{
				printf("[]\n");
			}
			else
			{
				printf("[");
				Node* poppedNode = Front(&deck);
				for (int i = 0; i < deck->_count; ++i)
				{
					printf("%d", poppedNode->_data);
					poppedNode = (deck->_reverse == false) ? poppedNode->_next : poppedNode->_prev;
					if (i != deck->_count - 1)
						printf(",");
				}
				printf("]\n");
			}
		}
		DestroyDeck(&deck);
	}
	return 0;
}