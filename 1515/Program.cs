using System;

namespace B1515
{
    class Program
    {
        static void Main(string[] args) 
        {
            string str = Console.ReadLine();
            int ptr = 0;

            for (int num = 1; num <= 30000; ++num)
            {
                string numToString = num.ToString();

                for (int numToStringIdx = 0; numToStringIdx < numToString.Length; numToStringIdx++) 
                { 
                    if (numToString[numToStringIdx] == str[ptr])
                    {
                        ++ptr;
                    }

                    if (ptr == str.Length)
                    {
                        Console.WriteLine(num);
                        return;
                    }
                }
            }
        }
    }
}