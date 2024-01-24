using System;

namespace B13752
{
    class Program
    {
        static void Main(string[] args) 
        {
            int n = int.Parse(Console.ReadLine());
            for (int index = 0; index < n; ++index)
            {
                int height = int.Parse(Console.ReadLine());
                for (int heightIdx = 0; heightIdx < height; ++heightIdx)
                {
                    Console.Write("=");
                }
                Console.WriteLine();
            }
        }
    }
}