#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double GetC(double x, double y, double w)
{
	double h1 = sqrt((x * x) - (w * w));
	double h2 = sqrt((y * y) - (w * w));
	double answer = (h1 * h2) / (h1 + h2);
	return answer;
}

int main(void)
{
	double x, y, c;
	scanf("%lf%lf%lf", &x, &y, &c);
	
	double lowW = 0;
	double highW = (x < y) ? x : y;
	double answerW = 0.0;

	while (highW - lowW > 0.000001)
	{
		double midW = (lowW + highW) / 2.0;
		if (GetC(x, y, midW) >= c)
		{
			// c�� w�� ũ��� ���� �ݺ�� ������
			// ����, c�� ũ�Գ�����, c�� ���̱� ���� w���� ��������. �׷��� lowW���� ���̴� ����
			lowW = midW;
			
			//answerW = midW;

		}
		else
		{
			// c�� w�� ũ��� ���� �ݺ�� ������
			// ����, c�� �۰� ������ c�� �ø��� ���� w���� ���߾�� ��. �׷��� highW���� ���ߴ� ����
			highW = midW;

			// ���࿡ highW�� answer�� �����Ѵٸ�?
			// ������� ���������� 10^-3���� ����ϱ� ������
			answerW = midW;
		}
	}

	printf("%.3lf\n", answerW);
	return 0;
}