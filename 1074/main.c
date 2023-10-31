#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void DivideAndConquer(long long start_i, long long start_j, long long width, long long r, long long c, long long N, long long* answer, bool* find)
{
	if (width == 2)
	{
		for (long long i = start_i; i < start_i + width; ++i)
		{
			for (long long j = start_j; j < start_j + width; ++j)
			{
				if ((*find) == false && i == r && j == c)
				{
					(*find) = true;
					break;
				}
				else if((*find) == false)
				{
					++(*answer);
				}
			}
		}
		return;
	}
	else
	{
		int passingSize = 1;
		for (int i = 0; i < N - 1; ++i)
			passingSize *= 4;
		if ((r >= start_i && r < start_i + width / 2) && (c >= start_j + width / 2 && c < start_j + width))
		{
			// 1사분면
			(*answer) += passingSize * 1;
			DivideAndConquer(start_i, start_j + width / 2, width / 2, r, c, N - 1, answer, find);
		}
		else if ((r >= start_i && r < start_i + width / 2) && (c >= start_j && c < start_j + width / 2))
		{
			// 2사분면
			(*answer) += passingSize * 0;
			DivideAndConquer(start_i, start_j, width / 2, r, c, N - 1, answer, find);
		}
		else if ((r >= start_i + width / 2 && r < start_i + width) && (c >= start_j && c < start_j + width / 2))
		{
			// 3사분면
			(*answer) += passingSize * 2;
			DivideAndConquer(start_i + width / 2, start_j, width / 2, r, c, N - 1, answer, find);
		}
		else if ((r >= start_i + width / 2 && r < start_i + width) && (c >= start_j + width / 2 && c < start_j + width))
		{
			// 4사분면
			(*answer) += passingSize * 3;
			DivideAndConquer(start_i + width / 2, start_j + width / 2, width / 2, r, c, N - 1, answer, find);
		}
	}
}

int main(void)
{
	long long N, r, c;
	long long answer = 0;
	bool find = false;

	scanf("%lld%lld%lld", &N, &r, &c);
	
	long long width = 1;
	for (int i = 0; i < N; ++i)
		width *= 2;

	DivideAndConquer(0, 0, width, r, c, N, &answer, &find);
	printf("%lld\n", answer);

	return 0;
}