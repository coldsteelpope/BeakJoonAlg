using System;

namespace B14681
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = int.Parse(Console.ReadLine());
            int y = int.Parse(Console.ReadLine());

            bool[] isQuadrant = { (x > 0 && y > 0), (x < 0 && y > 0), (x < 0 && y < 0), (x > 0 && y < 0) };
            for (int areaIdx = 0; areaIdx < isQuadrant.Length; ++areaIdx)
            {
                if (isQuadrant[areaIdx])
                {
                    Console.WriteLine(areaIdx + 1);
                    break;
                }
            }
        }
    }
}