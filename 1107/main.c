#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int broken_btns[11] = { 0, };

int GetDigitNum(int channel)
{
	if (channel == 0)
	{
		return 1;
	}
	else
	{
		int digit_num = 0;
		while (channel != 0)
		{
			++digit_num;
			channel /= 10;
		}
		return digit_num;
	}
}

int GetMaxChannel(int channel_digit_num)
{
	int max_num = 1;
	for (int i = 0; i < channel_digit_num; ++i)
		max_num *= 10;
	return max_num;
}

int GetMinChannel(int channel_digit_num)
{
	if (channel_digit_num - 1 == 0)
	{
		return 0;
	}
	else
	{
		int min_num = 1;
		for (int i = 0; i < channel_digit_num - 1; ++i)
		{
			min_num *= 10;
		}
		return min_num;
	}
}

bool CheckValidChannel(int channel, int channel_digit_num)
{
	int valid_digit_num = 0;
	if (channel == 0)
	{
		if (broken_btns[channel] == 0)
		{
			valid_digit_num = 1;
		}
	}
	else
	{
		while (channel != 0)
		{
			int remainder = channel % 10;
			if (broken_btns[remainder] == 0)
				++valid_digit_num;
			channel /= 10;
		}
	}

	if (valid_digit_num == channel_digit_num)
		return true;
	else
		return false;
}

int main(void)
{
	int current_channel = 100;
	
	int final_channel = 0;
	scanf("%d", &final_channel);

	int broken_btns_num = 0;
	scanf("%d", &broken_btns_num);

	for (int i = 0; i < broken_btns_num; ++i)
	{
		int broken_btn_num = 0;
		scanf("%d", &broken_btn_num);
		++broken_btns[broken_btn_num];
	}

	int final_channel_digit_num = GetDigitNum(final_channel);
	if (final_channel == 100)
	{
		printf("0\n");
	}
	else if(CheckValidChannel(final_channel, final_channel_digit_num))
	{
		int minVal = 2147483647;
		minVal = (minVal > abs(100 - final_channel)) ? abs(100 - final_channel) : minVal;
		minVal = (minVal > final_channel_digit_num) ? final_channel_digit_num : minVal;
		printf("%d\n", minVal);
	}
	else
	{
		int minVal = 2147483647;
		minVal = (minVal > abs(100 - final_channel)) ? abs(100 - final_channel) : minVal;
		for (int ch = 0; ch <= 1000001; ++ch)
		{
			if (CheckValidChannel(ch, GetDigitNum(ch)))
			{
				int diff = abs(ch - final_channel) + GetDigitNum(ch);
				minVal = (minVal > diff) ? diff : minVal;
			}
		}

		printf("%d\n", minVal);
	}
	return 0;
}