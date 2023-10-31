#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int N;
	scanf("%lf", &N);
	fflush(stdin);
	
	double* scores = (double*)malloc(sizeof(double) * N);
	double maxVal = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &scores[i]);
		fflush(stdin);
		maxVal = (maxVal < scores[i]) ? scores[i] : maxVal;
	}

	double sum = 0;
	for (int i = 0; i < N; ++i)
	{
		scores[i] = (scores[i] / maxVal) * 100;
		sum += scores[i];
	}
	double avg = (sum / N);
	printf("%lf\n", sum / N);
	return 0;
}