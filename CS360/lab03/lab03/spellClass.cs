using System;

namespace lab03
{
    public class Spell : Card
    {

        private string spellType; //spell types are: normal, quick, continuous, ritual, field, and equip.
        /// <summary>
        /// Default constructor sets the Spell card to "Harpie's", and fills in the approriate data form the "database".
        /// </summary>
        public Spell()
        {
            SetName("Harpie's Feather Duster");
            SetCardType(MyGlobals.nameCardTypePairs[GetName()]);
            SetText(MyGlobals.nameTextPairs[GetName()]);
            spellType = MyGlobals.nameSpellTypePairs[GetName()];
        }
        /// <summary>
        /// If the Spell card name exists in the list of cards, this custom constuctor creates the Spell card
        /// given by the parameter name, and fills in the approriate data form the "database". If the Spell
        /// card name is not in the list of card names, an error message is printed out to the user.
        /// </summary>
        /// <param name="name">
        /// The name of the Spell card.
        /// </param>
        public Spell(string name)
        {
            try
            {
                SetName(name);
                SetCardType(MyGlobals.nameCardTypePairs[GetName()]);
                SetText(MyGlobals.nameTextPairs[GetName()]);
                spellType = MyGlobals.nameSpellTypePairs[GetName()];
            }
            catch (Exception)
            {
                Console.WriteLine("\nNot a valid card name.\n");
            }
        }
        /// <summary>
        /// Gets the type of Spell card (Normal, Quick, Continuous, Ritual, Field, and Equip), and returns the string.
        /// </summary>
        /// <returns>
        /// The string representing the Spell type.
        /// </returns>
        public string GetSpellType()
        {
            return spellType;
        }
        /// <summary>
        /// The overridden abstract function form the card class. It prints out the Spell card if the names of the
        /// Spell card exists in the list of card names. This is a polymorphic function.
        /// </summary>
        public override void PrintOutCard() //polymorphic function that prints out spell card
        {
            if (MyGlobals.allNames.Contains(GetName()))
            {
                Console.WriteLine("----------------------------------------");
                Console.WriteLine(GetName());
                Console.WriteLine(GetSpellType() + " " + GetCardType());
                Console.WriteLine(GetText());
                Console.WriteLine("----------------------------------------");
            }
        }
    };
};
