#define _CRT_SECURE_NO_WARNINGS

#define REMAINDER 1000000007

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _MATRIX
{
	long long _data[2][2];
} Matrix;

Matrix MultiplyMatrix(Matrix A, Matrix B)
{
	Matrix C;
	C._data[0][0] = (((A._data[0][0] * B._data[0][0])) + ((A._data[0][1] * B._data[1][0]))) % REMAINDER;
	C._data[0][1] = (((A._data[0][0] * B._data[0][1])) + ((A._data[0][1] * B._data[1][1]))) % REMAINDER;
	C._data[1][0] = (((A._data[1][0] * B._data[0][0])) + ((A._data[1][1] * B._data[1][0]))) % REMAINDER;
	C._data[1][1] = (((A._data[1][0] * B._data[0][1])) + ((A._data[1][1] * B._data[1][1]))) % REMAINDER;
	return C;
}

Matrix PowerMatrix(Matrix A, long long n)
{
	if (n > 1)
	{
		A = PowerMatrix(A, n / 2);
		A = MultiplyMatrix(A, A);

		if (n % 2 != 0)
		{
			Matrix B;
			B._data[0][0] = 1; B._data[0][1] = 1;
			B._data[1][0] = 1; B._data[1][1] = 0;
			A = MultiplyMatrix(A, B);
		}
	}
	return A;
}


int main(void)
{
	Matrix A;
	A._data[0][0] = 1; A._data[0][1] = 1;
	A._data[1][0] = 1; A._data[1][1] = 0;
	
	long long n;
	scanf("%lld", &n);

	A = PowerMatrix(A, n);
	printf("%lld", A._data[0][1]);
	return 0;
}