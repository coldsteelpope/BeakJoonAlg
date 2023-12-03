#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int month_mm_leap_year[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int month_mm_normal_year[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool IsLeapYear(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int GetMonth(char* str)
{
	if (strcmp(str, "January") == 0)
	{
		return 1;
	}
	else if (strcmp(str, "February") == 0)
	{
		return 2;
	}
	else if (strcmp(str, "March") == 0)
	{
		return 3;
	}
	else if (strcmp(str, "April") == 0)
	{
		return 4;
	}
	else if (strcmp(str, "May") == 0)
	{
		return 5;
	}
	else if (strcmp(str, "June") == 0)
	{
		return 6;
	}
	else if (strcmp(str, "July") == 0)
	{
		return 7;
	}
	else if (strcmp(str, "August") == 0)
	{
		return 8;
	}
	else if (strcmp(str, "September") == 0)
	{
		return 9;
	}
	else if (strcmp(str, "October") == 0)
	{
		return 10;
	}
	else if (strcmp(str, "November") == 0)
	{
		return 11;
	}
	else if (strcmp(str, "December") == 0)
	{
		return 12;
	}
}

int main(void)
{
	char raw_month[10];
	char raw_dd[10];
	char raw_year[10];
	char raw_hhmm[10];
	
	scanf("%s%s%s%s", raw_month, raw_dd, raw_year, raw_hhmm);

	int dd = atoi(strtok(raw_dd, ","));
	int year = atoi(raw_year);
	int hh = atoi(strtok(raw_hhmm, ":"));
	int mm = atoi(strtok(NULL, ":"));
	
	bool isLeapYear = IsLeapYear(year);
	int month = GetMonth(raw_month);

	int sum = 0;
	int total = 0;
	sum += (hh * 60);
	sum += mm;
	if (isLeapYear == true)
	{
		for (int m = 1; m <= month - 1; ++m)
		{
			sum += (month_mm_leap_year[m] * 24 * 60);
		}
		
		for (int m = 1; m <= 12; ++m)
		{
			total += (month_mm_leap_year[m] * 24 * 60);
		}
	}
	else
	{
		for (int m = 1; m <= month - 1; ++m)
		{
			sum += (month_mm_normal_year[m] * 24 * 60);
		}

		for (int m = 1; m <= 12; ++m)
		{
			total += (month_mm_normal_year[m] * 24 * 60);
		}
	}
	sum += ((dd - 1) * 24 * 60);

	long double result = (sum) / (double)(total);
	printf("%.10llf\n", result * 100);
	
	return 0;
}