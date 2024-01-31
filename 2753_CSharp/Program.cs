using System;

namespace B2753
{
    class Program
    {
        static void Main(string[] args)
        {
            int year = int.Parse(Console.ReadLine());
            
            bool bLeapYear = true;
            if (year % 4 != 0)
            {
                // 선조건: 전무
                // 선조건이 전무인 상태에서 year % 4가 0이 아니면 평년이므로 false
                bLeapYear = false;
            }
            else if (year % 100 != 0)
            {
                // 선조건: year % 4 == 0 는 true
                // year % 4 == 0 이고 year != 0 이면 윤년이므로 true 
                bLeapYear = true;
            }
            else if (year % 400 != 0)
            {
                // 선조건: year % 4 == 0 는 true && year % 100 == 0 는 true
                // 선조건을 만족하고 year % 400가 0이 아니면, 평년이므로 false
                bLeapYear = false;
            }
            else
            {
                // 선조건: year % 4 == 0 는 true && year % 100 == 0 는 true && year % 400 == 0 는 true
                // 따라서 모든 조건을 만족하므로 무조건 윤년(true)!
                bLeapYear = true;
            }
            
            if (bLeapYear)
            {
                Console.WriteLine(1);
            }
            else
            {
                Console.WriteLine(0);
            }
        }
    }
}

