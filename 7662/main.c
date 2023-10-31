#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>


bool valid[1000001] = { 0, };

typedef struct _NODE
{
	int _data;
	int _ins_num;
	bool _deleteFlag;
} Node;

typedef struct _MAXHEAP
{
	int _capacity;
	int _usedsize;
	Node* _nodes;
} MaxHeap;

typedef struct _MINHEAP
{
	int _capacity;
	int _usedsize;
	Node* _nodes;
} MinHeap;

void CreateMaxHeap(MaxHeap** maxHeap, int init_capacity)
{
	(*maxHeap) = (MaxHeap*)malloc(sizeof(MaxHeap));
	(*maxHeap)->_capacity = init_capacity;
	(*maxHeap)->_usedsize = 0;
	(*maxHeap)->_nodes = (Node*)malloc(sizeof(Node) * init_capacity);
}

void CreateMinHeap(MinHeap** minHeap, int init_capacity)
{
	(*minHeap) = (MinHeap*)malloc(sizeof(MinHeap));
	(*minHeap)->_capacity = init_capacity;
	(*minHeap)->_usedsize = 0;
	(*minHeap)->_nodes = (Node*)malloc(sizeof(Node) * init_capacity);
}

void SwapMaxHeapNodes(MaxHeap** maxHeap, int index1, int index2)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memcpy(temp, &(*maxHeap)->_nodes[index1], sizeof(Node));
	memcpy(&(*maxHeap)->_nodes[index1], &(*maxHeap)->_nodes[index2], sizeof(Node));
	memcpy(&(*maxHeap)->_nodes[index2], temp, sizeof(Node));
	free(temp);
}

void SwapMinHeapNodes(MinHeap** minHeap, int index1, int index2)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memcpy(temp, &(*minHeap)->_nodes[index1], sizeof(Node));
	memcpy(&(*minHeap)->_nodes[index1], &(*minHeap)->_nodes[index2], sizeof(Node));
	memcpy(&(*minHeap)->_nodes[index2], temp, sizeof(Node));
	free(temp);
}

int GetParentPosition(int index)
{
	return (index - 1) / 2;
}

int GetLeftPosition(int index)
{
	return 2 * index + 1;
}

void PushMaxHeap(MaxHeap** maxHeap, int data, int ins_num)
{
	int currentPosition = (*maxHeap)->_usedsize;
	int parentPosition = GetParentPosition(currentPosition);
	
	if ((*maxHeap)->_capacity == (*maxHeap)->_usedsize)
	{
		(*maxHeap)->_capacity *= 2;
		(*maxHeap)->_nodes = (Node*)realloc((*maxHeap)->_nodes, sizeof(Node) * (*maxHeap)->_capacity);
	}

	(*maxHeap)->_nodes[currentPosition]._data = data;
	(*maxHeap)->_nodes[currentPosition]._deleteFlag = false;
	(*maxHeap)->_nodes[currentPosition]._ins_num = ins_num;

	while (currentPosition > 0 && (*maxHeap)->_nodes[currentPosition]._data >= (*maxHeap)->_nodes[parentPosition]._data)
	{
		SwapMaxHeapNodes(maxHeap, currentPosition, parentPosition);
		currentPosition = parentPosition;
		parentPosition = GetParentPosition(currentPosition);
	}
	(*maxHeap)->_usedsize++;
}

void PushMinHeap(MaxHeap** minHeap, int data, int ins_num)
{
	int currentPosition = (*minHeap)->_usedsize;
	int parentPosition = GetParentPosition(currentPosition);

	if ((*minHeap)->_capacity == (*minHeap)->_usedsize)
	{
		(*minHeap)->_capacity *= 2;
		(*minHeap)->_nodes = (Node*)realloc((*minHeap)->_nodes, sizeof(Node) * (*minHeap)->_capacity);
	}

	(*minHeap)->_nodes[currentPosition]._data = data;
	(*minHeap)->_nodes[currentPosition]._deleteFlag = false;
	(*minHeap)->_nodes[currentPosition]._ins_num = ins_num;

	while (currentPosition > 0 && (*minHeap)->_nodes[currentPosition]._data <= (*minHeap)->_nodes[parentPosition]._data)
	{
		SwapMinHeapNodes(minHeap, currentPosition, parentPosition);
		currentPosition = parentPosition;
		parentPosition = GetParentPosition(currentPosition);
	}

	(*minHeap)->_usedsize++;
}

Node FrontMaxHeap(MaxHeap** maxHeap)
{
	return (*maxHeap)->_nodes[0];
}

Node FrontMinHeap(MinHeap** minHeap)
{
	return (*minHeap)->_nodes[0];
}

void PopMaxHeap(MaxHeap** maxHeap)
{
	int currentPosition = 0;
	
	
	memset(&(*maxHeap)->_nodes[currentPosition], 0, sizeof(Node));
	
	(*maxHeap)->_usedsize--;
	memcpy(&(*maxHeap)->_nodes[currentPosition], &(*maxHeap)->_nodes[(*maxHeap)->_usedsize], sizeof(Node));
	
	int leftPosition = GetLeftPosition(currentPosition);
	int rightPosition = leftPosition + 1;

	while (1)
	{
		int selectedPosition = 0;
		if (leftPosition >= (*maxHeap)->_usedsize)
			break;
		if (rightPosition >= (*maxHeap)->_usedsize)
			selectedPosition = leftPosition;
		else
		{
			if ((*maxHeap)->_nodes[leftPosition]._data <= (*maxHeap)->_nodes[rightPosition]._data)
				selectedPosition = rightPosition;
			else
				selectedPosition = leftPosition;
		}

		if ((*maxHeap)->_nodes[currentPosition]._data <= (*maxHeap)->_nodes[selectedPosition]._data)
		{
			SwapMaxHeapNodes(maxHeap, currentPosition, selectedPosition);
			currentPosition = selectedPosition;
		}
		else
		{
			break;
		}
		leftPosition = GetLeftPosition(currentPosition);
		rightPosition = leftPosition + 1;
	}

	if ((*maxHeap)->_capacity == (*maxHeap)->_usedsize / 2)
	{
		(*maxHeap)->_capacity /= 2;
		(*maxHeap)->_nodes = (Node*)realloc((*maxHeap)->_nodes, sizeof(Node) * (*maxHeap)->_capacity);
	}
}

void PopMinHeap(MinHeap** minHeap)
{
	int currentPosition = 0;

	memset(&(*minHeap)->_nodes[currentPosition], 0, sizeof(Node));

	(*minHeap)->_usedsize--;
	memcpy(&(*minHeap)->_nodes[currentPosition], &(*minHeap)->_nodes[(*minHeap)->_usedsize], sizeof(Node));

	int leftPosition = GetLeftPosition(currentPosition);
	int rightPosition = leftPosition + 1;

	while (1)
	{
		int selectedPosition = 0;
		if (leftPosition >= (*minHeap)->_usedsize)
			break;
		if (rightPosition >= (*minHeap)->_usedsize)
			selectedPosition = leftPosition;
		else
		{
			if ((*minHeap)->_nodes[leftPosition]._data <= (*minHeap)->_nodes[rightPosition]._data)
				selectedPosition = leftPosition;
			else
				selectedPosition = rightPosition;
		}

		if ((*minHeap)->_nodes[currentPosition]._data >= (*minHeap)->_nodes[selectedPosition]._data)
		{
			SwapMinHeapNodes(minHeap, currentPosition, selectedPosition);
			currentPosition = selectedPosition;
		}
		else
		{
			break;
		}
		leftPosition = GetLeftPosition(currentPosition);
		rightPosition = leftPosition + 1;
	}



	if ((*minHeap)->_capacity == (*minHeap)->_usedsize / 2)
	{
		(*minHeap)->_capacity /= 2;
		(*minHeap)->_nodes = (Node*)realloc((*minHeap)->_nodes, sizeof(Node) * (*minHeap)->_capacity);
	}
}

void PrintMaxHeap(MaxHeap** maxHeap)
{
	int maxHeapUsedSize = (*maxHeap)->_usedsize;
	for (int i = 0; i < maxHeapUsedSize; ++i)
	{
		printf("%d\t", (*maxHeap)->_nodes[i]._data);
	}
	printf("\n");
}

void PrintMinHeap(MinHeap** minHeap)
{
	int minHeapUsedSize = (*minHeap)->_usedsize;
	for (int i = 0; i < minHeapUsedSize; ++i)
	{
		printf("%d\t", (*minHeap)->_nodes[i]._data);
	}
	printf("\n");
}

void DestroyMaxHeap(MaxHeap** maxHeap)
{
	free((*maxHeap)->_nodes);
	free((*maxHeap));
}

void DestroyMinHeap(MinHeap** minHeap)
{
	free((*minHeap)->_nodes);
	free((*minHeap));
}




int main(void)
{
	

	MaxHeap* maxHeap;
	MinHeap* minHeap;

	int offset = 2147483648;
	int testcase = 0;
	scanf("%d", &testcase);

	for (int t = 0; t < testcase; ++t)
	{
		CreateMaxHeap(&maxHeap, 3);
		CreateMinHeap(&minHeap, 3);

		int instruction_num = 0;
		scanf("%d", &instruction_num);
		for (int instruction_index = 0; instruction_index < instruction_num; ++instruction_index)
		{
			char instruction = 0;
			int num = 0;
			scanf(" %c%d", &instruction, &num);

			if (instruction == 'I')
			{
				PushMaxHeap(&maxHeap, num, instruction_index);
				PushMinHeap(&minHeap, num, instruction_index);
				valid[instruction_index] = true;
			}
			else
			{
				if (num == 1)
				{
					while (valid[maxHeap->_nodes[0]._ins_num] == false && maxHeap->_usedsize > 0)
					{
						PopMaxHeap(&maxHeap);
					}
					if (maxHeap->_usedsize > 0)
					{
						valid[maxHeap->_nodes[0]._ins_num] = false;
						PopMaxHeap(&maxHeap);
					}
				}
				else if (num == -1)
				{
					while (valid[minHeap->_nodes[0]._ins_num] == false && minHeap->_usedsize > 0)
					{
						PopMinHeap(&minHeap);
					}
					if (minHeap->_usedsize > 0)
					{
						valid[minHeap->_nodes[0]._ins_num] = false;
						PopMinHeap(&minHeap);
					}
				}
			}

		}

		while (valid[maxHeap->_nodes[0]._ins_num] == false && maxHeap->_usedsize > 0)
		{
			PopMaxHeap(&maxHeap);
		}
		while (valid[minHeap->_nodes[0]._ins_num] == false && minHeap->_usedsize > 0)
		{
			PopMinHeap(&minHeap);
		}

		if (maxHeap->_usedsize == 0 && minHeap->_usedsize == 0)
		{
			printf("EMPTY\n");
		}
		else
		{
			printf("%d %d\n", maxHeap->_nodes[0]._data, minHeap->_nodes[0]._data);
		}
		DestroyMaxHeap(&maxHeap);
		DestroyMinHeap(&minHeap);
	}

	return 0;
}