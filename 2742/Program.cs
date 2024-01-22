using System;

namespace B2742
{
    class Program
    {
        static void Main(string[] args) 
        {
            int N = int.Parse(Console.ReadLine());
            for (int num = N; num >= 1; --num)
            {
                Console.WriteLine(num);
            }
        }
    }
}