#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int num;
	struct Node* next;
};

struct Queue {
	struct Node* front, * rear;
	int size;
};

struct Node* newNode(int num) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));

	node->num = num;
	node->next = NULL;
	return node;
}

struct Queue* createQueue() {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

	queue->front = queue->rear = NULL;
	queue->size = 0;
	return queue;
}

void push(struct Queue* q, int n) {
	struct Node* node = newNode(n);

	if (q->size == 0) {
		q->front = q->rear = node;
		q->size++;
		return;
	}

	q->rear->next = node;
	q->rear = node;
	q->size++;
}

int pop(struct Queue* q) {
	if (q->size == 0)
		return -1;

	struct Node* temp = q->front;
	int num = q->front->num;

	if (q->size == 1)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;

	q->size--;
	free(temp);
	return num;
}

int L(int n) {
	int d1 = n / 1000;
	n = n * 10 + d1;
	return n % 10000;
}

int R(int n) {
	int d4 = n % 10;
	n = n / 10 + d4 * 1000;
	return n;
}

int len(char* str) {
	int n = 0;
	while (*str++)
		n++;
	return n;
}

void decode(int* visit, int B, int A, char* cmd) {
	int x;

	while (A != B) {
		x = visit[B];
		if (visit[R(B)] == x - 1) {
			*cmd++ = 'L';
			B = R(B);
		}
		else if (visit[L(B)] == x - 1) {
			*cmd++ = 'R';
			B = L(B);
		}
		else if (visit[(B + 1) % 10000] == x - 1) {
			*cmd++ = 'S';
			B = (B + 1) % 10000;
		}
		else {
			*cmd++ = 'D';
			if (visit[B / 2] == x - 1)
				B = B / 2;
			else
				B = (10000 + B) / 2;
		}
	}

	*cmd = '\0';
}

void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int T;
	scanf("%d", &T);

	int A, B;
	while (T--) {
		struct Queue* q = createQueue();
		int visit[10000] = {0,};
		scanf("%d %d", &A, &B);
		push(q, A);

		int x, i, j;
		int k = 1;
		while (q->size) {
			x = q->size;
			for (i = 0; i < x; i++) {
				int n = pop(q);

				if (n == B) {
					visit[n] = k;
					break;
				}

				if (visit[n] == 0) {
					visit[n] = k;
					j = (n * 2) % 10000;
					if (visit[j] == 0)
						push(q, j);

					j = ((n > 0) ? n - 1 : 9999);
					if (visit[j] == 0)
						push(q, j);

					j = L(n);
					if (visit[j] == 0)
						push(q, j);

					j = R(n);
					if (visit[j] == 0)
						push(q, j);
				}
			}
			if (i < x)
				break;
			k++;
		}

		char cmd[128];
		decode(visit, B, A, cmd);

		k = len(cmd);
		for (i = 0; i < k / 2; i++)
			swap(&cmd[i], &cmd[k - 1 - i]);

		printf("%s\n", cmd);
		free(q);
	}
}