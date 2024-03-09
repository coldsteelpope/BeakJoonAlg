#include <iostream>

using namespace std;

int main(void)
{
	int iN;
	int iM;
	cin >> iN >> iM;
	
	int iMinSetPrice = 2147483647;
	int iMinPartPrice = 2147483647;
	
	for (int index = 0; index < iM; ++index)
	{
		int iSetPrice;
		int iPartPrice;
		
		cin >> iSetPrice >> iPartPrice;

		iMinSetPrice = (iSetPrice < iMinSetPrice) ? iSetPrice : iMinSetPrice;
		iMinPartPrice = (iPartPrice < iMinPartPrice) ? iPartPrice : iMinPartPrice;
	}

	// 일단 Set를 전부 구매한 후, 그룹 구매 OR 낱개 구매 중 더 싼 선택하기
	int iSetNum = iN / 6;
	int iRemainNum = iN % 6;

	int iTotalCost = (iSetNum * iMinSetPrice);

	if (iRemainNum != 0)
	{
		int iRemainCost = iMinSetPrice;
		iRemainCost = (iRemainCost > (iRemainNum * iMinPartPrice)) ? (iRemainNum * iMinPartPrice) : iRemainCost;
		iTotalCost += iRemainCost;
	}

	// 낱개 구매 박치기
	iTotalCost = ((iN * iMinPartPrice) < iTotalCost) ? (iN * iMinPartPrice) : iTotalCost;

	cout << iTotalCost << "\n";
	return 0;
}