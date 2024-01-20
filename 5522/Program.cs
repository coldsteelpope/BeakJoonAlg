using System;

namespace B5522
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[5];
            for (int index = 0; index < arr.Length; ++index)
            {
                arr[index] = int.Parse(Console.ReadLine());
            }

            int sum = 0;
            for (int index = 0; index < arr.Length; ++index)
            {
                sum += arr[index];
            }

            Console.WriteLine(sum);
        }
    }
}