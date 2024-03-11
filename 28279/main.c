#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	int _data;
	struct _NODE* _front;
	struct _NODE* _back;
} Node;

typedef struct _DEQUE
{
	int _size;
	Node* _head;
	Node* _rear;
} Deque;

Node* CreateNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_front = NULL;
	node->_back = NULL;
	return node;
}

void CreateDeque(Deque** deque)
{
	(*deque) = (Deque*)malloc(sizeof(Deque));
	(*deque)->_head = CreateNode(0);
	(*deque)->_rear = CreateNode(0);
	(*deque)->_size = 0;

	(*deque)->_head->_front = (*deque)->_rear;
	(*deque)->_head->_back = NULL;
	
	(*deque)->_rear->_back = (*deque)->_head;
	(*deque)->_rear->_front = NULL;
}

void PushFront(int _iData, Deque** _deque)
{
	Node* newNode = CreateNode(_iData);

	(*_deque)->_head->_front->_back = newNode;
	newNode->_front = (*_deque)->_head->_front;

	(*_deque)->_head->_front = newNode;
	newNode->_back = (*_deque)->_head;

	(*_deque)->_size++;
}

void PushBack(int _iData, Deque** _deque)
{
	Node* newNode = CreateNode(_iData);
	
	(*_deque)->_rear->_back->_front = newNode;
	newNode->_back = (*_deque)->_rear->_back;

	newNode->_front = (*_deque)->_rear;
	(*_deque)->_rear->_back = newNode;

	(*_deque)->_size++;
}

int Size(Deque** _deque)
{
	return (*_deque)->_size;
}

int Empty(Deque** _deque)
{
	return ((*_deque)->_size == 0) ? 1 : 0;
}

int Front(Deque** _deque)
{
	return ((*_deque)->_size == 0) ? -1 : (*_deque)->_head->_front->_data;
}

int Back(Deque** _deque)
{
	return ((*_deque)->_size == 0) ? -1 : (*_deque)->_rear->_back->_data;
}

int PopFront(Deque** _deque)
{
	Node* poppedNode = (*_deque)->_head->_front;
	int result = poppedNode->_data;

	(*_deque)->_head->_front = poppedNode->_front;
	poppedNode->_front->_back = (*_deque)->_head;
	free(poppedNode);

	(*_deque)->_size--;
	return result;
}

int PopBack(Deque** _deque)
{
	Node* poppedNode = (*_deque)->_rear->_back;
	int result = poppedNode->_data;

	(*_deque)->_rear->_back = poppedNode->_back;
	poppedNode->_back->_front = (*_deque)->_rear;
	free(poppedNode);
	
	(*_deque)->_size--;
	return result;
}

void Destroy(Deque** _deque)
{
	while (!Empty(_deque))
	{
		PopFront(_deque);
	}

	free((*_deque)->_head);
	free((*_deque)->_rear);
	free((*_deque));
}

int main(void)
{
	Deque* deque;
	CreateDeque(&deque);

	int iN;
	scanf("%d", &iN);
	
	for (int index = 0; index < iN; ++index)
	{
		int instruction;
		scanf("%d", &instruction);

		if (instruction == 1)
		{
			int iData;
			scanf("%d", &iData);
			PushFront(iData, &deque);
		}
		else if (instruction == 2)
		{
			int iData;
			scanf("%d", &iData);
			PushBack(iData, &deque);
		}
		else if (instruction == 3)
		{
			if (Empty(&deque))
			{
				printf("-1\n");
			}
			else
			{
				int popped = PopFront(&deque);
				printf("%d\n", popped);
			}
		}
		else if (instruction == 4)
		{
			if (Empty(&deque))
			{
				printf("-1\n");
			}
			else
			{
				int popped = PopBack(&deque);
				printf("%d\n", popped);
			}
		}
		else if (instruction == 5)
		{
			printf("%d\n", Size(&deque));
		}
		else if (instruction == 6)
		{
			printf("%d\n", Empty(&deque));
		}
		else if (instruction == 7)
		{
			printf("%d\n", Front(&deque));
		}
		else if (instruction == 8)
		{
			printf("%d\n", Back(&deque));
		}
	}

	Destroy(&deque);
	return 0;
}