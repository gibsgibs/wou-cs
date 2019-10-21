using System;

namespace lab03
{
    public class Trap : Card
    {
        private string trapType; //thses are: Normal, Continuous, Counter
        /// <summary>
        /// Default constructor sets the Trap card to "Compuls", and fills in the approriate data form the "database".
        /// </summary>
        public Trap()
        {
            SetName("Compulsory Evacuation Device");
            SetCardType(MyGlobals.nameCardTypePairs[GetName()]);
            SetText(MyGlobals.nameTextPairs[GetName()]);
            trapType = MyGlobals.nameTrapTypePairs[GetName()];
        }
        /// <summary>
        /// If the Trap card name exists in the list of cards, this custom constuctor creates the Trap card
        /// given by the parameter name, and fills in the approriate data form the "database". If the Trap
        /// card name is not in the list of card names, an error message is printed out to the user.
        /// </summary>
        /// <param name="name">
        /// The name of the Trap card.
        /// </param>
        public Trap(string name)
        {
            try
            {
                SetName(name);
                SetCardType(MyGlobals.nameCardTypePairs[GetName()]);
                SetText(MyGlobals.nameTextPairs[GetName()]);
                trapType = MyGlobals.nameTrapTypePairs[GetName()];
            }
            catch (Exception)
            {
                Console.WriteLine("\nNot a valid card name.\n");
            }
        }
        /// <summary>
        /// Gets the type of the Trap card (Normal, Continuous, Counter), and returns the string.
        /// </summary>
        /// <returns>
        /// The string representing the Trap type.
        /// </returns>
        public string GetTrapType()
        {
            return trapType;
        }
        /// <summary>
        /// The overridden abstract function form the card class. It prints out the Trap card if the names of the
        /// Trap card exists in the list of card names. This is a polymorphic function.
        /// </summary>
        public override void PrintOutCard() 
        {
            if (MyGlobals.allNames.Contains(GetName()))
            {
                Console.WriteLine("----------------------------------------");
                Console.WriteLine(GetName());
                Console.WriteLine(GetTrapType() + " " + GetCardType());
                Console.WriteLine(GetText());
                Console.WriteLine("----------------------------------------");
            }
        }
    }
}