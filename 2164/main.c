#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _CARD
{
	int _data;
	struct _CARD* _next;
	struct _CARD* _prev;
} Card;

typedef struct _DECK
{
	int _count;
	Card* _head;
	Card* _rear;
} Deck;

void CreateDeck(Deck** deck)
{
	(*deck) = (Deck*)malloc(sizeof(Deck));
	(*deck)->_count = 0;

	(*deck)->_head = (Card*)malloc(sizeof(Card));
	(*deck)->_rear = (Card*)malloc(sizeof(Card));
	
	(*deck)->_head->_data = -1;
	(*deck)->_rear->_data = -1;
	(*deck)->_head->_next = (*deck)->_rear;
	(*deck)->_head->_prev = NULL;
	(*deck)->_rear->_prev = (*deck)->_head;
	(*deck)->_rear->_next = NULL;
}

void Push(Deck** deck, int newData)
{
	Card* newCard = (Card*)malloc(sizeof(Card));
	newCard->_data = newData;
	
	(*deck)->_rear->_prev->_next = newCard;
	newCard->_prev = (*deck)->_rear->_prev;
	newCard->_next = (*deck)->_rear;
	(*deck)->_rear->_prev = newCard;
	(*deck)->_count++;
}

Card* Front(Deck** deck)
{
	return (*deck)->_head->_next;
}

void Pop(Deck** deck)
{
	Card* poppedCard = Front(deck);
	(*deck)->_head->_next = poppedCard->_next;
	poppedCard->_next->_prev = (*deck)->_head;
	(*deck)->_count--;
	free(poppedCard);
}

bool Empty(Deck** deck)
{
	return (*deck)->_count == 0;
}

void Destroy(Deck** deck)
{
	while (Empty(deck) == false)
	{
		Pop(deck);
	}
	free((*deck)->_head);
	free((*deck)->_rear);
	free((*deck));
}

int main(void)
{
	Deck* deck;
	CreateDeck(&deck);
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		Push(&deck, i);
	}
	
	bool throwAway = true;
	while (deck->_count != 1)
	{
		if (throwAway)
		{
			Pop(&deck);
			throwAway = false;
		}
		else
		{
			Card* poppedCard = Front(&deck);
			int poppedCardData = poppedCard->_data;
			Pop(&deck);
			Push(&deck, poppedCardData);
			throwAway = true;
		}
	}

	printf("%d", Front(&deck)->_data);
	Destroy(&deck);
	return 0;
}