#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int iLastNumber = 0;

typedef struct tagNode
{
	char cData;
	int iLastNumber;
	struct tagNode* pNext;
	struct tagNode* pBack;
} Node;


typedef struct tagDeque
{
	int iCount;
	Node* pHead;
	Node* pTail;
} Deque;

Node* CreateNode(char cData, Deque** _deque);

Node* CreateTrashNode(Deque** _deque);

void CreateDeque(Deque** _deque);

void PushBack(Deque** _deque, char _cData);

void PushFront(Deque** _deque, char _cData);

void Pop(Deque** _deque);

bool Empty(Deque** _deque);

void Destroy(Deque** _deque);

void Print(Deque** _deque);

int main(void)
{
	Deque* deque;
	CreateDeque(&deque);

	int iNumber = 0;
	scanf("%d", &iNumber);

	for (int i = 0; i < iNumber; ++i)
	{
		int iSelect = 0;
		char cSelectCharacter = 0;

		scanf("%d", &iSelect);

		switch (iSelect)
		{
		case 1:
		{
			getchar();
			scanf("%c", &cSelectCharacter);
			PushBack(&deque, cSelectCharacter);
		}	
			break;
		case 2:
		{
			getchar();
			scanf("%c", &cSelectCharacter);
			PushFront(&deque, cSelectCharacter);
		}
			break;
		case 3:
		{
			Pop(&deque);
		}
			break;
		default:
			break;
		}
	}
	
	if (deque->iCount == 0)
	{
		printf("0");
	}
	else
	{
		Print(&deque);
	}
	Destroy(&deque);
	return 0;
}

Node* CreateNode(char cData, Deque** _deque)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->cData = cData;
	newNode->iLastNumber = ++iLastNumber;
	newNode->pBack = newNode->pNext = NULL;
	return newNode;
}

Node* CreateTrashNode(Deque** _deque)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->cData = 0;
	newNode->pBack = newNode->pNext = NULL;
	return newNode;
}

void CreateDeque(Deque** _deque)
{
	(*_deque) = (Deque*)malloc(sizeof(Deque));
	(*_deque)->pHead = CreateTrashNode(_deque);
	(*_deque)->pTail = CreateTrashNode(_deque);

	(*_deque)->iCount = 0;

	(*_deque)->pHead->pNext = (*_deque)->pTail;
	(*_deque)->pTail->pBack = (*_deque)->pHead;
}

void PushBack(Deque** _deque, char _cData)
{
	Node* newNode = CreateNode(_cData, _deque);
	newNode->cData = _cData;

	(*_deque)->pTail->pBack->pNext = newNode;
	newNode->pBack = (*_deque)->pTail->pBack;

	(*_deque)->pTail->pBack = newNode;
	newNode->pNext = (*_deque)->pTail;

	(*_deque)->iCount++;
}

void PushFront(Deque** _deque, char _cData)
{
	Node* newNode = CreateNode(_cData, _deque);
	newNode->cData = _cData;

	(*_deque)->pHead->pNext->pBack = newNode;
	newNode->pNext = (*_deque)->pHead->pNext;

	(*_deque)->pHead->pNext = newNode;
	newNode->pBack = (*_deque)->pHead;

	(*_deque)->iCount++;
}

void Pop(Deque** _deque)
{
	if ((*_deque)->iCount == 0)
	{
		return;
	}

	Node* poppedNode = NULL;
	Node* frontNode = (*_deque)->pHead->pNext;
	Node* rearNode = (*_deque)->pTail->pBack;

	if (frontNode->iLastNumber > rearNode->iLastNumber)
	{
		poppedNode = (*_deque)->pHead->pNext;
		poppedNode->pNext->pBack = (*_deque)->pHead;
		(*_deque)->pHead->pNext = poppedNode->pNext;
	}
	else
	{
		poppedNode = (*_deque)->pTail->pBack;
		poppedNode->pBack->pNext = (*_deque)->pTail;
		(*_deque)->pTail->pBack = poppedNode->pBack;
	}
	(*_deque)->iCount--;
	free(poppedNode);
}

bool Empty(Deque** _deque)
{
	return (*_deque)->iCount == 0;
}

void Destroy(Deque** _deque)
{
	while (Empty(_deque) == false)
	{
		Pop(_deque);
	}
	free((*_deque)->pHead);
	free((*_deque)->pTail);
	free((*_deque));
}

void Print(Deque** _deque)
{
	Node* ptr = (*_deque)->pHead->pNext;
	while (ptr != (*_deque)->pTail)
	{
		char cData = ptr->cData;
		printf("%c", cData);
		ptr = ptr->pNext;
	}
}