using System;

namespace B10817
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] splitedInput = input.Split(' ');

            int[] arr = new int[3];
            for (int index = 0; index < 3; ++index)
            {
                arr[index] = int.Parse(splitedInput[index]);
            }

            for (int i = 0; i < 3; ++i)
            {
                for(int j = i + 1; j < 3; ++j)
                {
                    if (arr[i] > arr[j])
                    {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }

            Console.WriteLine(arr[1]);
        }
    }
}