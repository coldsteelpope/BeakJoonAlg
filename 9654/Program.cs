using System;

namespace B9654
{
    class Program
    {
        static void Main(string[] args) 
        {
            string dataForm = "{0,-15}{1,-15}{2,-11}{3,-10}";
            Console.WriteLine(dataForm, "SHIP NAME", "CLASS", "DEPLOYMENT", "IN SERVICE");
            Console.WriteLine(dataForm, "N2 Bomber", "Heavy Fighter", "Limited", "21");
            Console.WriteLine(dataForm, "J-Type 327", "Light Combat", "Unlimited", "1");
            Console.WriteLine(dataForm, "NX Cruiser", "Medium Fighter", "Limited", "18");
            Console.WriteLine(dataForm, "N1 Starfighter", "Medium Fighter", "Unlimited", "25");
            Console.WriteLine(dataForm, "Royal Cruiser", "Light Combat", "Limited", "4");

        }
    }
}