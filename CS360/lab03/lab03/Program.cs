using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab03
{
    class Program
    {   
        static string welcomeMsg = "|\tWelcome to the Yu-Gi-Oh! card simulator!\t|\n"; //This is just a welcome message,

        static string hBar = "+-------------------------------------------------------+\n"; //A horizantal bar to make the output look nicer.

        /// <summary>
        /// This is the main, where the whole project is being run. It prints out a welcome message, the asks the user to input their name.
        /// The name is stored, and used during the porgram to make it seem more personal. There a personalized greeting, and a short descrption
        /// of how the program works, along with a menu. The user can then select the different options from the menu, which executes functions
        /// based on the input using a switch statement.
        /// </summary>
        static void Main(string[] args)
        {
            Console.WriteLine(hBar + welcomeMsg + hBar);

            Console.Write("Please type your name, and then press ENTER: ");
            string playerName = Console.ReadLine();
            Console.WriteLine("\nGreetings, " + playerName + "!\n");
            Console.WriteLine("This program will simulate drawing cards from a deck.\n");
            Hand myHand = new Hand();
            Console.WriteLine("MENU");
            Console.WriteLine("1: Draw a card.");
            Console.WriteLine("2: Look at last card drawn.");
            Console.WriteLine("3: Look at hand.");
            Console.WriteLine("4: End simulation.\n");
            string playerInput = "0";
            while (playerInput != "4")
            {
                playerInput = Console.ReadLine();
                switch (playerInput)
                {
                    case "1":
                        myHand.drawCard();
                        Console.WriteLine("~You drew a card!~");
                        break;
                    case "2":
                        if(myHand.GetSize() == 0)
                        {
                            Console.WriteLine("\n~Your hand is empty.\nYou must draw a card first.~");
                        }
                        else
                        {
                            Console.WriteLine("~Last card drawn~");
                            myHand.GetLast().PrintOutCard();
                        }
                        break;
                    case "3":
                        if (myHand.GetSize() == 0)
                        {
                            Console.WriteLine("\n~Your hand is empty.\nYou must draw a card first.~");
                        }
                        else
                        {
                            Console.WriteLine("~Your hand~");
                            myHand.PrintHand();
                        }
                        break;
                    case "4":
                        Console.WriteLine("~Goodbye, " + playerName + "!~");
                        break;
                    default:
                        Console.WriteLine("~Invalid input.~");
                        break;
                }
            }
            Console.Read();
        }
    }
}
