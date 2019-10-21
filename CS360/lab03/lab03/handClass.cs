using System;
using System.Collections.Generic;
using System.Linq;

namespace lab03
{ 
    public class Hand
    {
        public List<Card> cards = new List<Card>();
        private int size;
        /// <summary>
        /// Default constuctor simply sets the size to zero. That is to say, it gives
        /// the user an empty hand.
        /// </summary>
        public Hand()
        {
            size = 0;
        }
        /// <summary>
        /// This function creates a random integer between 0 and the size of the list of names.
        /// It then assigns a string a random name form the list of names. Then it enters a
        /// switch statement to see which card type (Monster, Spell, Trap), corresponds to 
        /// that name. It creates the appropriate card, and increments the size.
        /// </summary>
        public void drawCard()
        {
            Random rand = new Random();
            int num = rand.Next(MyGlobals.allNames.Count());
            string cardName = MyGlobals.allNames.ElementAt(num);
            string test = MyGlobals.nameCardTypePairs[cardName];
            switch (test)
            {
                case "Monster":
                    Monster newMCard = new Monster(cardName);
                    cards.Add(newMCard);
                    break;
                case "Spell":
                    Spell newSCard = new Spell(cardName);
                    cards.Add(newSCard);
                    break;
                case "Trap":
                    Trap newTCard = new Trap(cardName);
                    cards.Add(newTCard);
                    break;
            }
            size++;
        }
        /// <summary>
        /// Gets the size of the hand.
        /// </summary>
        /// <returns>
        /// Returns the integer representing the size of the hand.
        /// </returns>
        public int GetSize()
        {
            return size;
        }
        /// <summary>
        /// Gets the last card in the hand, or nothing if the hand is empty.
        /// </summary>
        /// <returns>
        /// Returns the last card in the hand.
        /// </returns>
        public Card GetLast()
        {
            return cards.LastOrDefault();
        }
        /// <summary>
        /// Under the assumption that the hand contains cards, this function prints out
        /// the cards in the hand. If there are no cards, there is an error message 
        /// printed out to the user.
        /// </summary>
        public void PrintHand()
        {
            try
            {
                for(int i = 0; i < size; i++)
                {
                    cards.ElementAt(i).PrintOutCard();
                }
            }
            catch
            {
                Console.WriteLine("There are no cards in your hand.");
            }
        }
    }
}