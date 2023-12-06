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
			// c와 w의 크기는 서로 반비례 관계임
			// 따라서, c가 크게나오면, c를 줄이기 위해 w값을 높여야함. 그래서 lowW값을 높이는 거임
			lowW = midW;
			
			//answerW = midW;

		}
		else
		{
			// c와 w의 크기는 서로 반비례 관계임
			// 따라서, c가 작게 나오면 c를 늘리기 위해 w값을 낮추어야 함. 그래서 highW값을 낮추는 거임
			highW = midW;

			// 만약에 highW로 answer를 갱신한다면?
			// 상관없음 오차범위가 10^-3까지 허용하기 때문에
			answerW = midW;
		}
	}

	printf("%.3lf\n", answerW);
	return 0;
}