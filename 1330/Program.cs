using System;

namespace B1330
{
    class Program
    {
        static void Main(string[] args) 
        {
            string input = Console.ReadLine();
            string[] strNums = input.Split(' ');
            
            int numOne = int.Parse(strNums[0]);
            int numTwo = int.Parse(strNums[1]);

            if (numOne > numTwo)
            {
                Console.WriteLine(">");
            }
            else if (numOne < numTwo)
            {
                Console.WriteLine("<");
            }
            else
            {
                Console.WriteLine("==");
            }
        }
    }
}