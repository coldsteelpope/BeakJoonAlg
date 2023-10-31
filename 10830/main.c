#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define MOD 1000

typedef struct _MATRIX
{
	long long _data[6][6];
	long long _size;
} Matrix;

Matrix SetMatrix(long long size)
{
	Matrix A;
	A._size = size;
	for (long long i = 0; i < size; ++i)
		for (long long j = 0; j < size; ++j)
			scanf("%lld", &A._data[i][j]);
	return A;
}

void PrintMatrix(Matrix A)
{
	long long size = A._size;
	for (long long i = 0; i < size; ++i)
	{
		for (long long j = 0; j < size; ++j)
		{
			printf("%lld ", A._data[i][j] % MOD);
		}
		printf("\n");
	}
}


Matrix MultiplyMatrix(Matrix A, Matrix B)
{
	Matrix Result;
	Result._size = A._size;
	for (long long i = 0; i < Result._size; ++i)
	{
		for (long long j = 0; j < Result._size; ++j)
		{
			Result._data[i][j] = 0;
			for (long long k = 0; k < Result._size; ++k)
			{
				Result._data[i][j] += A._data[i][k] * B._data[k][j];
			}
			Result._data[i][j] %= MOD;
		}
	}
	return Result;
}

Matrix Power(Matrix A, long long n)
{
	if (n == 1)
	{
		for (long long i = 0; i < A._size; ++i)
			for (long long j = 0; j < A._size; ++j)
				A._data[i][j] = (A._data[i][j]) % MOD;
		return A;
	}
	else if (n % 2 == 0)
	{
		Matrix T = Power(A, n / 2);
		return MultiplyMatrix(T, T);
	}
	else
	{
		return MultiplyMatrix(Power(A, n - 1), A);
	}
}

int main(void)
{
	long long size, exp;
	scanf("%lld%lld", &size, &exp);
	Matrix A = SetMatrix(size);
	
	Matrix Result = Power(A, exp);
	PrintMatrix(Result);
	return 0;
}